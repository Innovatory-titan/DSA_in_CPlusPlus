#include <bits/stdc++.h>
using namespace std;

int countStairs(int n) {
    if (n <= 2) return n;
    int first = 1, second = 2, result = 0;

    for (int i = 2; i < n; i++) {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}

int main() {
    cout << countStairs(4) << endl;
    return 0;
}
