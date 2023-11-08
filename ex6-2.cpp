#include <iostream>
#include <fstream>
#include <algorithm>
int LENGTH = 100;
using namespace std;

int partition(int A[], int p, int r) { // A[p ... r] 파티션
    int pivot = A[p]; // 파티션의 처음값인 A[p]를 pivot으로 지정 
    int h = p; 
    int k;

    /* 
    a[k] 랑 a[p] 계속 비교하면서 진행
    a[k] < p 면 h++하고 a[h], a[p]값 바꾼다음 k++
    a[k] > p 면 k++ 
    */
    for (k = p + 1; k <= r; k++) {
        if (A[k] < pivot) {
            h = h + 1;
            swap(A[h], A[k]);
        }
    }

    swap(A[p], A[h]);

    return h;
}

void quicksort(int A[], int p, int r) { // A[p ... r] 정렬
    int q;

    if (p < r) {
        q = partition(A, p, r); // 파티션 수행
        quicksort(A, p, q-1); // 좌측 파티션에 대해 quicksort
        quicksort(A, q+1, r); // 우측 파티션에 대해 quicksort
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

    quicksort(a, 0, i-1);

    for (int j = 0; j < i; j++) {
        cout << a[j] << " ";
    }
}