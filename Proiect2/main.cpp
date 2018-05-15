//
// Created by auras on 08.05.2018.
//

#include <iostream>
#include <fstream>
#include <ctime>
#include <climits>
#include "Museums.h"
#include "Tourist.h"
#include "Activitate.h"
#include "Destination.h"
#include "Beach.h"
#include "Monastery.h"
#include "Mountain.h"

using namespace std;

int main() {
    cout << "Bun venit la Agentia Aurelu!\n";
    cout << "Motto : Daca cu Aurelu in vacanta pleci, in mod sigur o sa te distrezi!\n";
    auto dest = new Destination*[3];
    for(int i = 1; i <= 3; ++i) {
        dest[i - 1] = Destination::Create(i);
    }

    ifstream fin("dateTuristi.in");
    if(!fin.is_open()) {
        cout << "The file can't be opened!\n";
        exit(EXIT_FAILURE);
    }
    int noOfTourist;
    fin >> noOfTourist;
    fin.get();
    auto turisti = new Tourist[noOfTourist];
    for(int i = 0; i < noOfTourist; ++i) {
        fin >> turisti[i];
    }
    fin.close();
    int ok1 = 0;
    do {
        int choice1, choice2;
        cout << "Menu\n";
        cout << "1. About destinations\n";
        cout << "2. Add tourist\n";
        cout << "3. Display tourists\n";
        cout << "4. Display selected destination and activity plan\n";
        cout << "5. EXIT\n";
        cin >> choice1;
        switch (choice1) {
            case 1 : {
                int ok2 = 0;
                do {
                    cout << "1. Thassos\n";
                    cout << "2. Amsterdam\n";
                    cout << "3. Razlog\n";
                    cout << "4. Go back\n";
                    cin >> choice2;
                    switch (choice2) {
                        case 1 : {
                            cout << *dest[0] << '\n';
                            break;
                        }
                        case 2 : {
                            cout << *dest[1] << '\n';
                            break;
                        }
                        case 3 : {
                            cout << *dest[2] << '\n';
                            break;
                        }
                        case 4 : {
                            ok2 = 1;
                            break;
                        }
                        default : {
                            cout << "Invalid choice\n";
                        }
                    }
                } while (ok2 == 0);
                break;
            }
            case 2 : {
                auto aux = new Tourist();
                cin >> *aux;
                auto tmp = new Tourist[noOfTourist + 1];
                for(int i = 0; i < noOfTourist; ++i)
                    tmp[i] = turisti[i];
                tmp[noOfTourist] = *aux;
                ++noOfTourist;
                delete[] turisti;
                turisti = tmp;
                break;
            }
            case 3 : {
                cout << "Number of tourists : " << noOfTourist << '\n';
                for(int i = 0; i < noOfTourist; ++i)
                    cout << turisti[i] << '\n';
                break;
            }
            case 4 : {
                int minDest = INT_MAX;
                int save = 0;
                for(int i = 0; i < 3; ++i) {
                    int nrDiferente = 0;
                    for (int j = 0; j < noOfTourist; ++j) {
                        for(int k = 0; k < turisti[j].getNoOfActivities(); ++k) {
                            int MIN = INT_MAX;
                            for (int l = 0; l < dest[i]->getNumarActivitati(); ++l) {
                                int aux = Activitate::comparaActivitati(turisti[j].getActivitate(k), dest[i]->getActivitate(l));
                                if(MIN > aux && aux >= 0)
                                    MIN = aux;
                            }
                            if(MIN != INT_MAX)
                                nrDiferente += MIN;
                        }
                    }
                    //cout << nrDiferente << '\n';
                    if(minDest > nrDiferente) {
                        minDest = nrDiferente;
                        save = i;
                    }
                }
                srand(time(NULL));
                int zile;

                while ((zile = rand() % 15) < 3 || zile > 14);

                cout << *dest[save] << '\n';
                cout << "Number of days required : " << zile << '\n';
                double tmp1 = 1;
                double tmp3;
                while(zile > tmp1) {
                    for (int i = 0; i < dest[save]->getNumarActivitati() && zile > tmp1; ++i) {
                        double tmp2 = dest[save]->getActivitate(i)->getDaysNeed();
                        tmp3 = tmp1;
                        tmp1 += tmp2;
                        if(zile < tmp1)
                            tmp1 -= tmp2;
                        else if(zile >= tmp1) {
                            cout << "The activity " << dest[save]->getActivitate(i)->getName();
                            cout << " takes place on days " << tmp3 << "-" << tmp1 << '\n';
                        }
                    }
                }
                break;
            }
            case 5 :
                ok1 = 1;
                break;
            default :
                cout << "Invalid Choice\n";
                break;
        }
    } while(ok1 == 0);

    delete[] dest;
    delete[] turisti;

    return 0;
}
