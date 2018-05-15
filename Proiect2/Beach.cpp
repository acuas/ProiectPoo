//
// Created by auras on 09.05.2018.
//

#include "Beach.h"

Beach::Beach(const string &name, int sex, pair<int, int> ageGroup, double distance, double daysNeed, \
             int isGroupActivity, int landType, int nudists, int allowMinor = 1) :                   \
             Activitate(name, sex, ageGroup, distance, daysNeed, isGroupActivity) {
    setLandType(landType);
    setNudists(nudists);
    setAllowMinor(allowMinor);
}

void Beach::setLandType(int landType) {
    try {
        (landType == 0 || landType == 1) ? this->landType = static_cast<bool>(landType) : throw -1;
    }
    catch (const int &e) {
        cout << "This type of land for beach it isn't accepted!\n";
        exit(EXIT_FAILURE);
    }
}

void Beach::setNudists(int nudists) {
    try {
        (nudists == 0 || nudists == 1) ? this->nudists = static_cast<bool>(nudists) : throw -1;
    }
    catch (const int &e) {
        cout << "The beach can be for nudists or not! Another option it doesn't exist!\n";
        exit(EXIT_FAILURE);
    }
}

void Beach::setAllowMinor(int allowMinor) {
    try {
        if (allowMinor == 0 || allowMinor == 1)
            this->allowMinor = static_cast<bool>(allowMinor);
        else
            throw -1;
    }
    catch (const int &e) {
        cout << "Minors can be accepted on beaches or not! Anothor option it doesn't exist!\n";
        exit(EXIT_FAILURE);
    }
}

string Beach::getLandType() const {
    if(landType == 0)
        return "sand";
    else if(landType == 1)
        return "small pebbles";
}

bool Beach::getNudists() const {
    return nudists;
}

bool Beach::getAllowMinor() const {
    return allowMinor;
}

void Beach::read(istream &in) {
    int landType, nudists, allowMinor;
    in >> landType;
    setLandType(landType);
    in >> nudists;
    setNudists(nudists);
    if(getNudists()) {
        in >> allowMinor;
        setAllowMinor(allowMinor);
    }
    else {
        setAllowMinor(1);
    }
    in.get();
}

void Beach::write(ostream &out) const {
    out << "The beach is covered by " << getLandType() << ".\n";
    if(getNudists()) {
        out << "The beach is for nudists.\n";
        if(getAllowMinor()) {
            out << "The beach is accepting minors.\n";
        }
        else {
            out << "The beach isn't accepting minors!\n";
        };
    }
    else
        out << "The beach isn't for nudists.\n";

}