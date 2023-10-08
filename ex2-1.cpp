#include <iostream>

using namespace std;

long combination(int n, int r) {
    if (r == 0 || r == n)
        return 1;
    
    return combination(n-1, r-1) + combination(n-1, r);
}

int main() {
    int i = 0, j = 0;
    while(!cin.eof()) { // cmd + z 를 눌러야 파일의 끝
        cin >> i >> j;
        cout << i << "C" << j << " = " << combination(i, j) << endl;
    }
    return 0;
}