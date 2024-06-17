---
title: Threads
description: MulThread and Thread Pool
date: 2024-03-18T21:06:19+08:00
image: 
math: true
toc: true
tags:
    - CPP
---

# 线程管理

在程序开发中，很多时候都是程序都是串行处理，这没有什么问题。然而，在某些重复工作较多，且性能要求较高的场景，串行处理所需时间往往过于漫长。

因此，合理地使用线程管理有助于我们程序的更好运行。但是请注意，不是一味地使用多线程或线程池就一定是好的，适合运行场景的处理方式才是最好的。

## 单线程

在本文中，我们考虑这样一个场景：有一个非常耗时的计算函数，其计算一次需要 `time` 秒。

```cpp
void waitTime(int time) {
    std::chrono::seconds duration(time);
    std::this_thread::sleep_for(duration);
    
    std::cout << "wait for " << time << " seconds" << std::endl;
}
```

按照常规的做法，我们串行地对批量任务进行处理：

```cpp
int main() {
    std::vector<int> todoList(10, 3);

    for (auto time : todoList) {
        waitTime(time);
    }

    return 0;
}
```

可以预见，这种处理方法会非常耗时。

## 多线程

为了加速程序运行和处理的速度，我们可以使用多线程来并行处理。多线程的思想是：先将要进行的任务放入队列中，然后让这些任务同时运行，最终实现加速程序运行的效果。

```cpp
void mulTreads(std::vector<int> todoList, const int MaxThreads) {
    std::vector<std::unique_ptr<std::thread>> fetchingThreads;

    for (int i = 0, l = todoList.size(); i < l; i ++) {
        fetchingThreads.emplace_back(std::make_unique<std::thread>(waitTime, todoList[i]));

        if (fetchingThreads.size() >= MaxThreads) {
            fetchingThreads.front()->join();
            fetchingThreads.erase(fetchingThreads.begin());
        }
    }

    for (auto &threadPtr : fetchingThreads) {
        threadPtr->join();
    }
}


int main() {
    std::vector<int> todoList(10, 3);
    mulTreads(todoList, 7);

    return 0;
}
```

## 线程池

多线程虽好，但是频繁地创建和删除线程，同样会造成时间和空间的浪费。因此，线程池出现了，在每次任务完成之后，保留现有线程并继续处理下一个任务。

```cpp
class ThreadPool {
public:
    ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty())
                            return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }

                    task();
                }
            });
        }
    }

    // 添加任务到线程池
    template<class F>
    void enqueue(F&& task) {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace(std::forward<F>(task));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker : workers)
            worker.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};


int main() {
    const int numThreads = 7;
    ThreadPool pool(numThreads); // 创建包含7个线程的线程池

    std::vector<int> todoList(10, 3);

    // 向线程池中添加任务
    for (const int& time : todoList) {
        pool.enqueue([time] {
            waitTime(time);
        });
    }

    return 0;
}
```