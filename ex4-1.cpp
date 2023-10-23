#include <iostream>
#include <string> // 문자열 처리시 필요한 라이브러리
#define MESSAGE_LENGTH 50
using namespace std;

int main() {

    // 문자열과 문자 배열 선언

    string myMessage = "Hello, please love seunghyun";
    char encryption[MESSAGE_LENGTH];
    char decryption[MESSAGE_LENGTH];

    // 문자열의 각 문자에 대해 key의 xor 연산후 문자 배열에 저장

    int key = 5;

    int i = 0;
    for (i = 0; i < myMessage.length(); i++) {
        int c = (unsigned int) myMessage.at(i); // string 해당위치 문자 반환
        c = c ^ key;
        encryption[i] = (char) c;
    }
    encryption[i] = '\0';

    cout << encryption << endl;

    int j = 0;
    while (encryption[j] != '\0') {
        int d = (unsigned int) encryption[j];
        d = d ^ key;
        decryption[j] = (char) d;
        j++;
    }
    decryption[j] = '\0';

    cout << decryption << endl;

    return 0;
}