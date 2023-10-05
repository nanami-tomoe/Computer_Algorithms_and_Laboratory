#include <iostream>
using namespace std;

int col[10]; // index는 행이고 해당하는 값은 열이다. (indedx = selected, col[selected] = i)
int result = 0; // 가능한 경우의 수

bool check(int selected, int i) { 
    for(int j = 0; j < selected; j++) { // selected 전 행까지 돌면서 안되는 위치 거르기
        if(i == col[j] || abs(selected - j) == abs(i - col[j])) { // 같은열 or 대각선(행끼리 차 = 열끼리 차)
            return false; // 3. 해당 좌표에 퀸 방문 불가처리
        }
    }
    col[selected] = i; // 1. 해당 좌표에 퀸 방문 처리
    return true;
}

// selected 는 행, i 는 열이다.
void search(int selected) {
    int i = 0;

    if (selected == 10) {
        for (int j = 0; j < 10; j++){
            cout << col[j]; // 4. 퀸이 마킹된 위치를 모두 출력
        }
        cout << endl;
        result++;
        return;
    }
    else {
        while(i++ < 10){
            if(check(selected, i)){ // 1. 해당 좌표에 퀸 방문 처리
                search(selected + 1); // 2. search(selected + 1)
            }
        }
    }
}


int main() {
    search(0);
    cout << result << endl;
    return 0;
}