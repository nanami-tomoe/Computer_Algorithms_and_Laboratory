#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

// 단어와 연결 리스트 노드를 정의합니다.
struct Node {
    string word;
    Node* next;

    Node(const string& w) : word(w), next(nullptr) {}
};

void generateSentence(const unordered_map<string, unordered_map<string, Node*>>& wordMap)
{
    // 첫 번째 해시 테이블에서 랜덤한 시작 인덱스를 선택합니다.
    auto it1 = wordMap.begin();
    advance(it1, rand() % wordMap.size());

    // 시작 단어들을 가져옵니다.
    string word1 = it1->first;
    unordered_map<string, Node*> secondMap = it1->second;
    auto it2 = secondMap.begin();
    advance(it2, rand() % secondMap.size());
    string word2 = it2->first;

    // 시작 단어들을 출력합니다.
    cout << word1 << " " << word2 << " ";

    // 나머지 문장을 생성합니다.
    while (true)
    {
        // 현재 단어들이 해시 테이블에 존재하는지 확인합니다.
        if (wordMap.find(word1) != wordMap.end() && wordMap.at(word1).find(word2) != wordMap.at(word1).end())
        {
            // 다음 단어 옵션들을 가져옵니다.
            Node* nextWords = wordMap.at(word1).at(word2);

            // 다음 단어 중에서 랜덤하게 선택합니다.
            int count = 0;
            Node* curr = nextWords;
            while (curr != nullptr) {
                count++;
                curr = curr->next;
            }
            int randomIndex = rand() % count;

            curr = nextWords;
            for (int i = 0; i < randomIndex; i++) {
                curr = curr->next;
            }
            string nextWord = curr->word;

            // 다음 단어를 출력합니다.
            cout << nextWord << " ";

            // 다음 단어들로 이동합니다.
            word1 = word2;
            word2 = nextWord;

            // 다음 단어가 문장의 끝을 나타내는 구두점인지 확인합니다.
            if ((nextWord.back() == '.') or (nextWord.back() == '"') or (nextWord.back() == '?') or (nextWord.back() == '!'))
            {
                // 문장을 종료합니다.
                cout << endl;
                return;
            }
        }
        else
        {
            // 더 이상 생성할 단어가 없으므로 문장을 종료합니다.
            return;
        }
    }
}

int main()
{
    // 난수 생성기를 시드로 초기화합니다.
    srand(static_cast<unsigned int>(time(0)));

    // 단어 맵을 구성합니다.
    unordered_map<string, unordered_map<string, Node*>> wordMap;

    // 파일에서 텍스트를 읽어와서 단어를 해시 맵에 저장합니다.
    ifstream inputFile("war_peace_plain.txt");
    string line;
    string prevWord1, prevWord2;
    while (getline(inputFile, line))
    {
        string word;
        istringstream iss(line);
        while (iss >> word)
        {
            if (!prevWord1.empty() && !prevWord2.empty())
            {
                // 새로운 노드를 생성합니다.
                Node* newNode = new Node(word);

                // 해시 맵에 단어를 저장합니다.
                wordMap[prevWord1][prevWord2] = newNode;
            }
            prevWord1 = prevWord2;
            prevWord2 = word;
        }
    }
    inputFile.close();

    // 사용자 인터페이스
    int choice;
    do
    {
        cout << "Choose options below." << endl;
        cout << "1) Generate a sentence." << endl;
        cout << "2) Finish." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            generateSentence(wordMap);
            break;
        case 2:
            cout << "Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    } while (choice != 2);

    // 해시 맵에 저장된 노드들을 삭제합니다.
    for (auto& entry : wordMap) {
        for (auto& secondEntry : entry.second) {
            Node* curr = secondEntry.second;
            while (curr != nullptr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    return 0;
}