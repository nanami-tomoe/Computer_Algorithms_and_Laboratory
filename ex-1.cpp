#include <iostream>
using namespace std;

int main(){
    int e;
    while(true){
        cin >> e;
        if (e == 1)
            cout << "Welcome to Woong-Sup's Algorithm Class" << endl;
        else if (e == 2)
            cout << "Good Luck for 2022 class" << endl;
        else if (e == 3)
            break;
    }
    return 0;
}