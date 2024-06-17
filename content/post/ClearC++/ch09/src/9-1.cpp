#include "bits/stdc++.h"
#include <cstring>

using namespace std;

int intSolve(int a, int b) { return a > b ? a : b; }

double doubleSolve(double a, double b) { return a > b ? a : b; }

template <class T>
T solve(T a, T b) { return a > b ? a : b; }

template <> const char* solve<const char*> (const char* a, const char* b) {
    return strcmp(a, b) ? a : b;
}

int main() {
    long a = 2, b = 3;
    short c = 4;
    cout << solve<long>(a, c) << endl;

    cout << solve<const char*>("EFG", "ABC") << endl;

    return 0;
}