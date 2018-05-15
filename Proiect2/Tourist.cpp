//
// Created by auras on 08.05.2018.
//

#include <cassert>
#include "Tourist.h"
#include "Monastery.h"
#include "Mountain.h"
#include "Beach.h"
#include "Museums.h"

Tourist::Tourist() {
    name = "";
    sex = 0;
    age = 0;
    noOfActivities = 0;
    pActivitati = nullptr;
}

Tourist::Tourist(const string &name, const string &sex, const int &age, const int &n, Activitate **p) {
    this->name = name;
    string aux = sex;
    transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
    setSex(aux);
    setAge(age);
    this->noOfActivities = n;
    this->pActivitati = p;
}

Tourist::Tourist(const Tourist &obj) {
    this->name = obj.name;
    this->sex = obj.sex;
    setAge(obj.age);
    this->noOfActivities = obj.noOfActivities;
    this->pActivitati = new Activitate*[obj.noOfActivities];
    for (int i = 0; i < obj.noOfActivities; ++i) {
        if(dynamic_cast<Beach *>(obj.pActivitati[i]) != nullptr) {
            auto p = new Beach();
            *p = *dynamic_cast<Beach *>(obj.pActivitati[i]);
            *pActivitati[i] = *dynamic_cast<Activitate *>(p);
        }
        else if(dynamic_cast<Monastery *>(obj.pActivitati[i]) != nullptr) {
            auto p = new Monastery();
            *p = *dynamic_cast<Monastery *>(obj.pActivitati[i]);
            *pActivitati[i] = *dynamic_cast<Activitate *>(p);
        }
        else if(dynamic_cast<Mountain *>(obj.pActivitati[i]) != nullptr) {
            auto p = new Mountain();
            *p = *dynamic_cast<Mountain *>(obj.pActivitati[i]);
            *pActivitati[i] = *dynamic_cast<Activitate *>(p);
        }
        else if(dynamic_cast<Museums *>(obj.pActivitati[i]) != nullptr) {
            auto p = new Museums();
            *p = *dynamic_cast<Museums *>(obj.pActivitati[i]);
            *pActivitati[i] = *dynamic_cast<Activitate *>(p);
        }
    }
}

Tourist::~Tourist() {
    if(pActivitati != nullptr) {
        for (int i = 0; i < noOfActivities; ++i)
            delete pActivitati[i];
        delete[] pActivitati;
    }
}

void Tourist::setSex(const string &sex) {
    try {
        if(sex == "man")
            this->sex = 0;
        else if(sex == "woman")
            this->sex = 1;
        else
            throw bad_sex();
    }
    catch (bad_sex& e) {
        cout << e.what();
    }
}

void Tourist::setAge(const int &age) {
    try {
        (age > 0 && age < 200) ? this->age = age : throw bad_age();
    }
    catch(bad_age& e) {
        cout << e.what();
    }
}

string Tourist::getName() const {
    return name;
}

string Tourist::getSex() const {
    if(sex == 0)
        return "man";
    else
        return "woman";
}

string Tourist::getGroupAge() const {
    if(age < 14) {
        return "Child";
    }
    else if(age >= 14 && age <= 18) {
        return "Teen";
    }
    else if(age >= 19 && age <= 65) {
        return "Adult";
    }
    else if(age > 65) {
        return "Older";
    }
}

int Tourist::getNoOfActivities() const {
    return noOfActivities;
}

Activitate *Tourist::getActivitate(int i) const {
    assert(i >= 0 && i < noOfActivities);
    return pActivitati[i];
}

istream &operator>>(istream &in, Tourist &obj) {
    string aux;
    getline(in, aux);
    obj.name = aux;
    getline(in, aux);
    obj.setSex(aux);
    int age, noOfActivities;
    in >> age;
    obj.setAge(age);
    in >> noOfActivities;
    obj.noOfActivities = noOfActivities;
    obj.pActivitati = new Activitate*[obj.noOfActivities];
    string tipActivitate;
    getline(in, tipActivitate);
    for(int i = 0; i < obj.noOfActivities; ++i) {
        getline(in, tipActivitate);
        //cout << tipActivitate << '\n';
        if(tipActivitate == "Monastery") {
            auto *p = new Monastery();
            in >> *p;
            obj.pActivitati[i] = dynamic_cast<Activitate *>(p);
        }
        else if(tipActivitate == "Mountain") {
            auto *p = new Mountain();
            in >> *p;
            obj.pActivitati[i] = dynamic_cast<Activitate *>(p);
        }
        else if(tipActivitate == "Beach") {
            auto *p = new Beach();
            in >> *p;
            obj.pActivitati[i] = dynamic_cast<Activitate *>(p);
        }
        else if(tipActivitate == "Museum") {
            auto *p = new Museums();
            in >> *p;
            obj.pActivitati[i] = dynamic_cast<Activitate *>(p);
        }
    }
    return in;
}

ostream &operator<<(ostream &out, const Tourist &obj) {
    out << "Name : " << obj.getName() << '\n';
    out << "Sex : " << obj.getSex() << '\n';
    out << "Group Age : " << obj.getGroupAge() << '\n';
    int n = obj.getNoOfActivities();
    out << "This tourist is desiring to do " << n << " activities.\n";
    for(int i = 0; i < n; ++i) {
        out << *obj.pActivitati[i] << '\n';
    }
    return out;
}