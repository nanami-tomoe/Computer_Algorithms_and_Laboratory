#include <iostream>

using namespace std;

double factorial(int n) {
    if (n == 0)
        return 1.0;

    return (double) n * factorial(n-1);
}

long combination(int n, int r) {
    if (r == 0 || r == n)
        return 1L;
    
    return factorial(n-1)/factorial(n-r-1)/factorial(r) + combination(n-1, r-1);
}

int main() {
    int i = 0, j = 0;
    while(!cin.eof()) { // cmd + z 를 눌러야 파일의 끝
        cin >> i >> j;
        cout << i << "C" << j << " = " << combination(i, j) << endl;
    }
    return 0;
}