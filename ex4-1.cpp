#include <iostream>
#include <string>
using namespace std;

int main() {
    string myMessage = "Hello, please love woongsup";
    char encryption[MESSAGE_LENGTH];

    for (i = 0; i < myMessage.length(); i++) {
        c = (usigned int) mtMessage.at(i);
        c = c ^ key;
        encryption[i] = (char) c;
    }
    encryption[i] = "\0";

    cout << encryption << endl;
}