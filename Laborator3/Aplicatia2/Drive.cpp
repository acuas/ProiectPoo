//
// Created by auras on 13.03.2018.
//

#include "Drive.h"

Drive::Drive() {
    cout << "MENU\n";
    cout << "1. Introducere valoare la inceput\n";
    cout << "2. Introducere valoare la sfarsit\n";
    cout << "3. Scoaterea unei valori din lista\n";
    cout << "4. Afisare lista\n";
    cout << "5. Iesire\n\n";

    list = new LinkedList();
    bool flag = true;
    int x, tmp;
    do {
        cout << "Numar optiune dorita : ";
        cin >> x;
        switch (x) {
            case opt1 : {
                cout << "Valoare : ";
                cin >> tmp;
                list->insertFront(tmp);
                break;
            }
            case opt2 : {
                cout << "Valoare : ";
                cin >> tmp;
                list->insertAfter(tmp);
                break;
            }
            case opt3 : {
                cout << "Valoare : ";
                cin >> tmp;
                list->deleteVal(tmp);
                break;
            }
            case opt4 : {
                cout << *list << '\n';
                break;
            }
            case opt5 : {
                flag = false;
                break;
            }
            default: {
                cout << "Optiune invalida\n";
            }
        }
    }while(flag);
}

Drive::~Drive() {
    delete list;
}