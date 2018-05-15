//
// Created by auras on 09.05.2018.
//

#include "Activitate.h"

Activitate::Activitate(string name, int sex, pair<int, int> ageGroup, double distance, double daysNeed, int isGroupActivity) {
    setName(name);
    setSex(sex);
    setAgeGroup(ageGroup);
    setDistance(distance);
    setDaysNeed(daysNeed);
    setIsGroupActivity(isGroupActivity);
    if(distance > 2.0) {
        setCarNeed(1);
    }
    else setCarNeed(0);
}

void Activitate::setName(string name) {
    this->name = name;
}

void Activitate::setSex(int sex) {
    try {
        (sex == 0 || sex == 1 || sex == 2) ? this->sex = sex : throw bad_sex();
    }
    catch (bad_sex &e) {
        cout << e.what();
        exit(EXIT_FAILURE);
    }
}

void Activitate::setAgeGroup(pair<int, int> ageGroup) {
    try {
        (ageGroup.first > 0 && ageGroup.second < 200) ? this->ageGroup = ageGroup : throw bad_age();
    }
    catch (bad_age &e) {
        cout << e.what();
        exit(EXIT_FAILURE);
    }
}

void Activitate::setCarNeed(int carNeed) {
    try {
        (carNeed == 0 || carNeed == 1) ? this->carNeed = static_cast<bool>(carNeed) : throw -1;
    }
    catch (const int &e) {
        cout << "The option of activity if a car is required or not has been corrupted.";
        exit(EXIT_FAILURE);
    }
}

void Activitate::setDaysNeed(double daysNeed) {
    try {
        (daysNeed == static_cast<double>(1/2.0) \
         || static_cast<int>(daysNeed) == daysNeed ) ? this->daysNeed = daysNeed : throw -1;
    }
    catch (const int &e) {
        cout << "The number of days that was entered is incorrect.";
        exit(EXIT_FAILURE);
    }
}

void Activitate::setIsGroupActivity(int isGroupActivity) {
    try {
        (isGroupActivity == 0 || isGroupActivity == 1) ? this->isGroupActivity = static_cast<bool>(isGroupActivity) : throw -1;
    }
    catch (const int &e) {
        cout << "The option of activity if is a group activity or not has been corrupted.";
        exit(EXIT_FAILURE);
    }
}

void Activitate::setDistance(double distance) {
    try {
        (distance > 0) ? this->distance = distance : throw -1;
    }
    catch (const int &e) {
        cout << "The distance can't be negative!\n";
        exit(EXIT_FAILURE);
    }
}

string Activitate::getName() const {
    return name;
}

string Activitate::getSex() const {
    if(sex == 0)
        return "man";
    else if(sex == 1)
        return "woman";
    else
        return "Not known!";
}

pair<int, int> Activitate::getAgeGroup() const {
    return ageGroup;
}

bool Activitate::getCarNeed() const {
    return carNeed;
}

double Activitate::getDaysNeed() const {
    return daysNeed;
}

double Activitate::getDistance() const {
    return distance;
}

bool Activitate::getIsGroupActivity() const {
    return isGroupActivity;
}

istream &operator>>(istream &in, Activitate &obj) {
    string name;
    int sex;
    pair<int, int> ageGroup;
    double daysNeed;
    double distance;
    int isGroupActivity;
    int aux1, aux2;
    getline(in, name);
    in >> sex;
    in >> aux1 >> aux2;
    ageGroup = {aux1, aux2};
    in >> daysNeed;
    in >> distance >> isGroupActivity;
    in.get();
    obj.setName(name);
    obj.setSex(sex);
    obj.setAgeGroup(ageGroup);
    obj.setDaysNeed(daysNeed);
    obj.setDistance(distance);
    obj.setIsGroupActivity(isGroupActivity);
    (distance > 2) ? obj.setCarNeed(1) : obj.setCarNeed(0);
    obj.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Activitate &obj) {
    out << "The name of the activity location : " << obj.getName() << '\n';
    out << "sex : " << obj.getSex() << '\n';
    out << "Age group : ";
    out << obj.getAgeGroup().first << ' ' << obj.getAgeGroup().second << '\n';
    out << "Distance : " << obj.getDistance() << '\n';
    out << "Days need : " << obj.getDaysNeed() << '\n';
    if(obj.getIsGroupActivity())
        out << "This is a group activity!\n";
    else
        out << "This is not a group activity!\n";
    if(obj.getCarNeed())
        out << "You need to rent a car for this activity!\n";
    else
        out << "You don't need to rent a car for this activity!\n";
    obj.write(out);
    return out;
}