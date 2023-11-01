#include <iostream>

using namespace std;

string message = "Hello, dongguk. My name is Seunghyun Lee";
int MESSAGE_LENGTH; // 메세지 길이를 저장할 변수

unsigned int* encryption; // 동적으로 할당된 배열
char* decryption; // 동적으로 할당된 배열

struct _node {
    int first; // x
    int second; // y
    int third; // gcd
};

_node* extended_Euclid(int a, int b) {
    _node* n1 = new _node();

    int temp;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    if (b == 0){
        n1->first = 1;
        n1->second = 0;
        n1->third = a;

        return n1;
    }
    else {
        _node* n2 = new _node();
        n2 = extended_Euclid(b, a%b);
        n1->first = n2->second;
        n1->second = n2->first - (a/b) * n2->second;
        n1->third = n2->third;

        return n1;
    }
}

// c^key mod N 값을 구한다.
// 아래함수의 매개변수 key는 암호화 할 때의 공개키 (e, N)의 
// e 값이며 할 때는 복호화 할 때에는 비밀키 (d, N)의 d값을 의미한다.
unsigned int do_exp(int c, int key, int N) {
    if (N == 1) return 0;

    unsigned int prod = 1;
    c = c % N;

    while(key > 0) {
        if(key % 2 == 1) {
            prod = (prod * c) % N;
        }

        key = key >> 1; // key값을 절반으로 줄임
        c = (c * c) % N;
    }

    return prod;
}

void print_encryption(unsigned int e[], int length) {
    for (int i = 0; i < length; i++) 
        cout << e[i];
    cout << endl;
}

int main() {
    MESSAGE_LENGTH = message.length();

    encryption = new unsigned int[MESSAGE_LENGTH];
    decryption = new char[MESSAGE_LENGTH];

    _node* n;
    int p = 11, q = 17, e = 3;
    int N = p * q;
    int phi_N = (p-1)*(q-1);

    n = extended_Euclid(phi_N, e);
    int d = n->second; // 1. 비밀키 d값 얻기
    d = (d % phi_N + phi_N) % phi_N;

    // 2. 문자열을 한글자씩 읽어 암호화
    for (int i = 0; i < MESSAGE_LENGTH; i++) { 
        int c = (unsigned int) message.at(i); 
        c = do_exp(c, e, N);
        encryption[i] = c;
    }
    
    // 3. 한자 씩 읽어 암호화된 encryption 출력
    print_encryption(encryption, MESSAGE_LENGTH);

    // 4. 배열 encryption의 숫자를 하나씩 읽어 key값에 따라 복호화
    for (int i = 0; i < MESSAGE_LENGTH; i++) { 
        int c = (unsigned int) encryption[i]; 
        c = do_exp(c, d, N);
        decryption[i] = (char) c;
    }
    decryption[MESSAGE_LENGTH] = '\0';

    // 5. 복호화된 문자열 decryption 내용 출력
    cout << decryption << endl;

    delete[] encryption;
    delete[] decryption;
}