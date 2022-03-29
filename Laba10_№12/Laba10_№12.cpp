#include <iostream>
#include <Windows.h>
#include <string>
#include <list>
#include <iterator>

using namespace std;

struct Guide {
    string term;
    char text[375];
};

//вывод всех заявок
void print(list <Guide> & myList, Guide & dict) {
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        dict = *it;
        cout << dict.term << " - " << dict.text << endl;
    }
}

//вывод поясняющего текста для заданного термина
void print_special(list <Guide> &List, Guide & dict) {
    string termin;
    int count=0;
    cout << "Введите термин, определение которого хотите узнать: ";
    cin >> termin;
    for (auto it = List.begin(); it != List.end(); ++it) {
        dict = *it;
        if (dict.term == termin) {
            cout << dict.term << " - " << dict.text << endl;
            count++;
        }
        
    }
    if (count == 0) cout << "Такого термина нет в списке! " << endl;
    
};


int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int punct;
    list <Guide> myList;

    Guide dictionary = {"словарик", "книга, информация в которой упорядочена c помощью разбивки на небольшие статьи, отсортированные по названию или тематике."};
    myList.push_back(dictionary);

    dictionary = { "игра", "инстинктивный способ получения и развития навыков людьми и животными в момент отсутствия непосредственной угрозы для жизни." };
    myList.push_back(dictionary);

    dictionary = { "синоним", "слово, различное по написанию и произношению, но близкое по лексическому значению." };
    myList.push_back(dictionary);

    dictionary = { "антоним", "слово одной части речи, но противоположное по лексическому значению" };
    myList.push_back(dictionary);

    
    do {
        cout << "Вывод текста помощи: 1" << endl;
        cout << "Вывод поясняющего текста для заданного термина: 2"<< endl;
        cout << "Выход: 3" << endl;
        cin >> punct;

        switch (punct) {
            case 1:
                print(myList, dictionary);
                cout << endl;
                break;
            case 2:
                print_special(myList, dictionary);
                cout << endl;
                break;
            default:
                break;
        }
    } while(punct==1 || punct ==2);
    

    myList.clear();
    return 0;
}

