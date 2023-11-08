#include <iostream>
#include <fstream>
int LENGTH = 100;
using namespace std;

void insertion_sort(int A[], int n) { // A[1 ... n] 정렬
    int i, j, tmp;

    for (int i = 1; i < n+1; i++) {
        tmp = A[i];

        // A[i]가 삽입될 자리를 찾음. 삽입될 자리는 j.
        for(j = i; A[j-1] > tmp && j > 0; j--) {
            // A[j]에 값을 할당해 줌. 어떤 값을 할당해 주는 가 하는 부분은 아래 그림 참고해서 작성
            A[j] = A[j-1];
        }
        
        A[j] = tmp; // tmp의 값을 A[j]에 할당
    }
}

int main() {
    ifstream inputFile("input.txt");

    int a[LENGTH];
    int number;
    int i = 0;
    while (inputFile >> number) {
        // 여기에서 number 변수에 읽어온 숫자를 사용할 수 있습니다.
        a[i] = number;
        i++;
    }

    insertion_sort(a, i-1);

    for (int j = 0; j < i; j++) {
        cout << a[j] << " ";
    }
}