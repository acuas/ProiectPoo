//
// Created by auras on 14.03.2018.
//

#include "Drive.h"

Drive::Drive() {
    Q = new Queue;
    cout << "MENU\n";
    cout << "1. push_back\n";
    cout << "2. pop_front\n";
    cout << "3. empty\n";
    cout << "4. front\n";
    cout << "5. back\n";
    cout << "6. size\n";
    bool flag = true;
    int x, __tmp;
    do{
        cout << "Optiunea dorita : ";
        cin >> x;
        switch (x) {
            case opt1 : {
                cout << "Valoare : ";
                cin >> __tmp;
                Q->push_back(__tmp);
                break;
            }
            case opt2 : {
                Q->pop_front();
                break;
            }
            case opt3 : {
                if(Q->empty())
                    cout << "Coada este goala!\n";
                else
                    cout << "Coada nu este goala\n";
                break;
            }
            case opt4 : {
                cout << Q->front() <<'\n';
                break;
            }
            case opt5 : {
                cout << Q->back() << '\n';
                break;
            }
            case opt6 : {
                cout << Q->size() << '\n';
                break;
            }
            case opt7 : {
                flag = false;
                break;
            }
            default :
                cout << "Optiune invalida!\n\n";
        }
    }while(flag);
}

Drive::~Drive() {
    delete Q;
}