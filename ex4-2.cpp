#include <iostream>

using namespace std;

struct Node {
    int first; // x
    int second; // y
    int third; // gcd
};

Node* extendedEuclid(int a, int b) {
    Node* n1 = new Node();

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
        Node* n2 = new Node();
        n2 = extendedEuclid(b, a%b);
        n1->first = n2->second;
        n1->second = n2->first - (a/b) * n2->second;
        n1->third = n2->third;

        return n1;
    }
}

    int main() {
        Node* n = nullptr;
        int u = 0;
        int v = 0;

        cout << "Type two positive integers" << endl;

        cin >> u >> v;

        if (u < 0 || v < 0) 
            cout << "invalid input" << endl;
        else if (u == 0) 
            cout << "gcd is " << u << endl;
        else if (v == 0)
            cout << "gcd is " << v << endl;
        else {
            n = extendedEuclid(u, v);
            cout << "x is " << n->first << endl;
            cout << "y is " << n->second << endl;
            cout << "gcd is " << n->third << endl;
        }
    }