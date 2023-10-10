#include <iostream>

using namespace std;

void move(int n, int a, int c, int b) { // 원반의 개수, 출발지, 경유지, 목적지
    // 1) 지역변수 초기화
    // 2) 탈출지점 및 처리방법 정의
    if(n == 1) {
        cout << "Move disk 0 from tray " << a << " to tray " << b << endl;
        return;
    }

    // 하노이 타워는 재귀를 사용하여 구현한다

    // 3) n-1개의 원반을 C로 옮기는 과정
    move(n-1, a, b, c);
    // 4) print("Move disk n from tray a to tray b") n -> n-1
    cout << "Move disk " << n-1 << " from tray " << a << " to tray " << b << endl;
    // 5) n-1개의 원반을 B로 옮기는 과정 
    move(n-1, c, a, b);
}

int main() {
    int disk_num = 0;
    cout << "입력예시 : ";
    cin >> disk_num;
    cout << "출력예시 :" << endl;
    move(disk_num, 1, 3, 2); // A, B, C 는 각각 1, 2, 3
}