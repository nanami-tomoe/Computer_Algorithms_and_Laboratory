#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<ctime>
#define TABLE_SIZE 541
#define NAME_SIZE 10
#define EMPTY "EMPTY"
#define FALSE 0
#define TRUE 1
using namespace std;

struct Hash {
    char names[NAME_SIZE];
    unsigned short collision;
};

struct Hash hash_table[TABLE_SIZE];

int hash1(char str[]) {
    int i, h;
    for (i = 0, h = 0; i < strlen(str); i++) {
        h = ((int)str[i] + h) % TABLE_SIZE;
    }
    return h;
}

int hash2(char str[],int random_values[]) {
    int i, h;
    for (i = 0, h = 0; i < strlen(str); i++) {
        h = (h + ((int)str[i] * random_values[i])) % TABLE_SIZE;
    }
    return h;
}

void hash_insert1(char name[]) {
    int number = 0; // for collision
    int key = hash1(name);
    while (strcmp(hash_table[key].names, "") != 0) {
        hash_table[key].collision++;
        number++;
        key = (number + key) % TABLE_SIZE;
    }
    strcpy(hash_table[key].names, name);
}

void hash_insert2(char name[], int random_values[]) {
    int number = 0; // for collision
    int key = hash2(name,random_values);
    while (strcmp(hash_table[key].names, "") != 0) {
        hash_table[key].collision++;
        number++;
        key = (number + key) % TABLE_SIZE;
    }
    strcpy(hash_table[key].names, name);
}

void initialize_table() {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        strcpy(hash_table[i].names,"");
        hash_table[i].collision = 0;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    initialize_table();
    ifstream inputFile("names.txt");
    char input[NAME_SIZE];
    int random_values[10];
    for (int i = 0; i < 10; i++)
    {
        random_values[i] = rand() % (TABLE_SIZE - 1) + 1;
    }
    string line;

    while (getline(inputFile, line)) {
        int i;
        for (i = 0; i < line.length(); i++) {
            input[i] = line[i];
        }
        input[i] = '\0';
        hash_insert1(input);
    }

    int totalCollision1 = 0;
    cout << "Hash1 출력결과 : " << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (strcmp(hash_table[i].names, "") == 0) {
            cout << "table[" << i << "]: " << setw(-10) << EMPTY << "\t" << hash_table[i].collision << endl;
        }
        else {
            cout << "table[" << i << "]: " << setw(-10) << hash_table[i].names << " " << hash_table[i].collision << endl;
        }
        totalCollision1 += hash_table[i].collision;
    }
    inputFile.close();

    initialize_table();
    inputFile.open("names.txt");
    int totalCollision2 = 0;
    while (getline(inputFile, line)) {
        int i;
        for (i = 0; i < line.length(); i++) {
            input[i] = line[i];
        }
        input[i] = '\0';
        hash_insert2(input,random_values);
        totalCollision2 += hash_table[i].collision;
    }
    
    cout << "Hash2 출력결과 : " << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        totalCollision2 += hash_table[i].collision;
        if (strcmp(hash_table[i].names, "") == 0) {
            cout << "table[" << i << "]: " << EMPTY << "\t" << hash_table[i].collision << endl;
        }
        else {
            cout << "table[" << i << "]: " << hash_table[i].names << " " << hash_table[i].collision << endl;
        }
    }
    inputFile.close();
    cout << "Total collision number in Hash1 is: " << totalCollision1 << "." << endl;
    cout << "Total collision number in Hash2 is: " << totalCollision2 <<"." << endl;

    return 0;
}
