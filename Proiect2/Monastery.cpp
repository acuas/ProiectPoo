//
// Created by auras on 10.05.2018.
//

#include "Monastery.h"

Monastery::Monastery(const string &name, int sex, pair<int, int> ageGroup, double distance, double daysNeed, \
                     int isGroupActivity, string religion) :                             \
                     Activitate(name, sex, ageGroup, distance, daysNeed, isGroupActivity), religion(religion) {
    if(sex == 1) {
        cout << "Nu este posibil ca o manastire sa fie formata doar din femei!\n";
        exit(EXIT_FAILURE);
    }
}

int Monastery::writePomelnic() {
    return -5;
}

string Monastery::getReligion() const {
    return religion;
}

void Monastery::read(istream &in) {
    getline(in, religion);
}

void Monastery::write(ostream &out) const {
    out << "Religion : " << getReligion();
}