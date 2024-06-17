---
title: Swift Tutorial
description: Swift Tutorial
date: 2024-04-25T00:28:05+08:00
image: assets/swift.png
math: true
toc: true
categories:
    - Swift
---

# Swift 教程

## Swift 基础
### 常量和变量
#### 声明常量和变量

在 Swift 中，常量使用 `let` 进行声明，变量使用 `var` 进行声明：

```swift
let MAX = 10;
var intVar = 20;
```

#### 类型注解

在 Swift 中，程序会根据声明的值来自动分析标识符的类型，同时也提供了显示指定类型的方法：

```swift
var intVar:int = 10;
var doubleVar:double = 10;

print("intVar = \(intVar)");
print("doubleVar = \(doubleVar)")

// --------------- 输出 --------------------
// intVar = 10
// doubleVar = 10.0
```

需要注意的是，若只不在声明时定义标识符的值，则必须指定类型：

```swift
var testVar: String;
testVar = "test var";
print(testVar)

// --------------- 输出 --------------------
// test var
```

### 整数

Swift 提供了8、16、32和64位的有符号和无符号整数类型。

#### 整数范围

可以访问不同整数类型的 `min` 和 `max` 属性来获取对应类型的最小值和最大值：

```swift
let minValue = UInt8.min  // minValue 为 0，是 UInt8 类型
let maxValue = UInt8.max  // maxValue 为 255，是 UInt8 类型
```

#### Int 与 UInt

Swift 提供了一个特殊的整数类型 `Int`，长度与当前平台的原生字长相同：

- 在 32 位平台上，`Int` 和 `Int32` 长度相同。
- 在 64 位平台上，`Int` 和 `Int64` 长度相同。

同样的，`UInt` 的长度也与当前平台的原生字长相同。

### 浮点数

Swift 提供两种有符号浮点数类型：

- `Double` 表示 64 位浮点数。
- `Float` 表示 32 位浮点数。

### 数值型字面量

整数字面量可以被写作：

- 一个 **十进制** 数：没有前缀
- 一个 **二进制** 数：前缀为 `0b`
- 一个 **八进制** 数：前缀是 `0o`
- 一个 **十六进制** 数：前缀是 `0x`

若想要用指数 `exp` 表示，则可在浮点数字面量后面添加大写或小写的 `e` 来指定。

```swift
let decInt = 10
let binInt = 0b1011

let expDouble = 1.25e2
```

### 类型别名

可以使用以下方法对指定类型定义一个别名：

```swift
typealias newType = Int64
```

### 布尔值

在 Swift 中布尔值强制使用 `true` 和 `false` 来表示，`0` 和 `1` 不能作为布尔值进行判断。

### 元组

在 Swift 中的元组可以包含任意多个值，且这些值可以是任意类型：

```swift
// 构造元组
let tuple = (10, "hello");
// 拆分元组
let (x, y) = tuple;
let (x, _) = tuple;
// 下标访问
let z = tuple.0;
```

和其他语言不同的是，Swift 的元组支持为元素命名，以实现便携的访问：

```swift
let nameTuple = (code: 11, des: "hello");

print(nameTuple.code)
```

### 可选类型

**可选类型**（options）用于处理值可能缺失的情况，其表示两种可能：

- 有值，可以通过强制解析来访问这个值
- 没有值，等于 `nil`

例如，在类型转换时，不一定能成功转换：

```swift
let x = "123", y = "hello";
print(Int(x), Int(y));
```

其中 `Int(x)` 有值，可以强制解析；而 `Int(y)` 没有值，等于 `nil`。

#### `nil`

对于没有值的变量，可以直接对其赋值 `nil` 来表示它没有值：

```swift
var x:String? = "hello";
x = nil;
```

#### 强制解析

对于可选类型的变量，如果确定其有值，则在其后面加一个 `!` 强制解析来访问其值：

```swift
var x = "123";
var y = Int(x);

print(y!);
```

