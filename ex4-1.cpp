#include <iostream>
#include <string> // 문자열 처리시 필요한 라이브러리
#define MESSAGE_LENGTH 10
using namespace std;

int main() {
    string myMessage = "Hello, please love woongsup";
    char encryption[MESSAGE_LENGTH];

    // 문자열의 각 문자에 대해 key의 xor 연산후 문자 배열에 저장

    for (int i = 0; i < myMessage.length(); i++) {
        int c = (usigned int) mtMessage.at(i);
        c = c ^ key;
        encryption[i] = (char) c;
    }
    encryption[i] = "\0";

    cout << encryption << endl;
}