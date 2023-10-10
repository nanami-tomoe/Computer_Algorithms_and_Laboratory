#include <iostream>

using namespace std;

double taylor(int x, int n) {
    if (n >= 30)
        return 0.0;
    return (double) 1 + (x/n) * taylor(x, n+1); // 0, 1, 2, 3 ... 29
}

int main() {
    for (int i = 1; i <= 10; i++) {
        cout << "e^" << i << " = " << taylor(i, 1) << endl;
    }
    return 0;
}