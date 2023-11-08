#include <iostream>
#include <fstream>
#include <map>
#include <locale>
using namespace std;

map<string, string> inputslovar() {
    ofstream outputFile("slova.txt");
    string translate;
    string word;
    map<string, string> slovar; 

    while (true) {
    

        cout << "введите слово на русском" << endl;
        cout << "введите exit для поиска слов в файле" << endl;
        cin >> word;
        if (word == "exit") {
      
            outputFile.close();

            return slovar;
        }


        cout << "введите перевод" << endl;
        cin >> translate;

        auto found = slovar.find(word);
        if (found == slovar.cend())
        {
            slovar[word] = translate;
            outputFile << word << ": " << translate << endl; 

        }
        else {
            cout << "такое слово уже существует" << endl;

        }
    }
}

void findword(map<string, string> slovar) {

    string word; 
    string translate;

    while (true) {

        cout << "введите слово" << endl;

        cin >> word;
        if (word == "exit")
            return;
        for (auto& pair: slovar) {
            if (pair.first == word) {
                cout << "перевод: " << pair.second << endl;

            }
            if (pair.second == word) {
                cout << "перевод: " << pair.first << endl;

            }
        }

    }
}
int main()
{
    setlocale (LC_ALL, "RUS");

    map<string, string> slovar = inputslovar();
    findword (slovar);

    return 0;
}
