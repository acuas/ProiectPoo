#include <iostream>
#include <algorithm>
#include "Set.h"

using namespace std;


int main() {
    int choice;
    long long n;
    do {
        cout << "Numarul de multimi : ";
        cin >> n;
        if(n < 2 || n > INF)
            cout << "Numarul de multimi trebuie sa fie in intervalul [2, " << INF << "]\n";
        }while(n < 2 || n > INF);

    auto *arr = new Set<int>[n];
    for(int i = 0; i < n ; ++i) {
        cout << "Set number " << i + 1 << '\n';
        cin >> arr[i];
    }

    bool ok2 = 0;
    int choice2;
    do {
        cout << "Set Menu\n";
        cout << "1.Reuniunea celor n multimi.\n";
        cout << "2.Intersectia celor n multimi.\n";
        cout << "3.Diferenta dintre doua multimi.\n";
        cout << "4.Sortarea celor n multimi.\n";
        cout << "5.Produsul cartezian.\n";
        cout << "6.EXIT\n";

        cin >> choice2;
        switch (choice2) {
            case 1 : {
                Set<int> res;
                for(int i = 0; i < n; ++i)
                    res = res + arr[i];
                cout << res << '\n';
                break;
            }
            case 2 : {
                Set<int> res = arr[0];
                for(int i = 1; i < n; ++i)
                    res = (res * arr[i]);
                cout << res << '\n';
                break;
            }
            case 3 : {
                int x;
                do {
                    cout << "Indicele multimii din care se scade : ";
                    cin >> x;
                    if(x < 0 || x > n - 1)
                        cout << "Indicele multimii trebuie sa fie in intervalul [0, " << n - 1 << "]\n";
                }while(x < 0 || x > n - 1);

                int y;
                do {
                    cout << "Indicele multimii cu care se scade : ";
                    cin >> y;
                    if(y < 0 || y > n - 1)
                        cout << "Indicele multimii trebuie sa fie in intervalul [0, " << n - 1 << "]\n";
                }while(y < 0 || y > n - 1);

                cout << "Diferenta lor este : " << arr[x] - arr[y] << '\n';
                break;
            }
            case 4 : {
                sort(arr, arr + n);
                break;
            }
            case 5 : {
                int x;
                do {
                    cout << "Indicele deinmultitorului : ";
                    cin >> x;
                    if(x < 0 || x > n - 1)
                        cout << "Indicele deinmultitorului trebuie sa fie in intervalul [0, " << n - 1 << "]\n";
                }while(x < 0 || x > n - 1);

                int y;
                do {
                    cout << "Indicele inmultitorului ";
                    cin >> y;
                    if(y < 0 || y > n - 1)
                        cout << "Indicele inmultitorului trebuie sa fie in intervalul [0, " << n - 1 << "]\n";
                }while(y < 0 || y > n - 1);

                cout << produs(arr[x], arr[y]) << '\n';
                break;
            }
            case 6 : {
                ok2 = 1;
                break;
            }
            default : {
                cout << "Alegere invalida.\n";
                break;

            }

        }
    }while(!ok2);

    delete[] arr;

    return 0;
}