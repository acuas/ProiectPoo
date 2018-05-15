//
// Created by auras on 10.05.2018.
//

#include <cassert>
#include "Mountain.h"

Mountain::Mountain(const string &name, int sex, pair<int, int> ageGroup, double distance,
                   double daysNeed, int isGroupActivity, int typesOfRoutes,
                   int noOfStops, int noOfMonastery, Monastery **manastiri) :
                   Activitate(name, sex, ageGroup, distance, daysNeed, isGroupActivity) {
    setTypesOfRoutes(typesOfRoutes);
    setAccessRestricted();
    setNoOfStops(noOfStops);
    if(getAccessRestricted())
        setAgeGroup({17, 90});
    setNoOfMonastery(noOfMonastery);
    this->manastiri = manastiri;
}

Mountain::Mountain(const Mountain &obj) {
    this->setName(obj.getName());
    this->setSex(obj.sex);
    this->setAgeGroup(obj.getAgeGroup());
    this->setCarNeed(obj.getCarNeed());
    this->setDaysNeed(obj.getDaysNeed());
    this->setDistance(obj.getDistance());
    this->setIsGroupActivity(obj.getIsGroupActivity());
    this->setTypesOfRoutes(obj.typesOfRoutes);
    this->setAccessRestricted();
    this->setNoOfStops(obj.getNoOfStops());
    this->setNoOfMonastery(obj.getNoOfMonastery());
    manastiri = new Monastery*[obj.getNoOfMonastery()];
    for(int i = 0; i < obj.getNoOfMonastery(); ++i) {
        manastiri[i] = new Monastery();
        *manastiri[i] = *obj.manastiri[i];
    }

}

Mountain::~Mountain() {
    if(manastiri != nullptr) {
        for(int i = 0; i < noOfMonastery; ++i)
            delete manastiri[i];
        delete[] manastiri;
    }
}

Mountain Mountain::operator=(const Mountain &obj) {
    if(this != &obj)
        return *this;
    this->setName(obj.getName());
    this->setSex(obj.sex);
    this->setAgeGroup(obj.getAgeGroup());
    this->setCarNeed(obj.getCarNeed());
    this->setDaysNeed(obj.getDaysNeed());
    this->setDistance(obj.getDistance());
    this->setIsGroupActivity(obj.getIsGroupActivity());
    this->setTypesOfRoutes(obj.typesOfRoutes);
    this->setAccessRestricted();
    this->setNoOfStops(obj.getNoOfStops());
    this->setNoOfMonastery(obj.getNoOfMonastery());
    manastiri = new Monastery*[obj.getNoOfMonastery()];
    for(int i = 0; i < obj.getNoOfMonastery(); ++i) {
        manastiri[i] = new Monastery();
        *manastiri[i] = *obj.manastiri[i];
    }
    return *this;
}

void Mountain::setTypesOfRoutes(int typesOfRoutes) {
    try {
        if(typesOfRoutes == 0 || typesOfRoutes == 1 || typesOfRoutes == 2) {
            this->typesOfRoutes = typesOfRoutes;
        }
        else
            throw -1;
    }
    catch(const int &e) {
        cout << "You are trying to set an invalid type of route.\n";
        exit(EXIT_FAILURE);
    }
}

void Mountain::setNoOfMonastery(int noOfMonastery) {
    try {
        if(noOfMonastery >= 0)
            this->noOfMonastery = noOfMonastery;
        else
            throw -1;
    }
    catch (const int &e) {
        cout << "You are trying to set an invalid number of monasteries!\n";
        cout << "By default the number of monasteries will be setted with 0.\n";
        this->noOfMonastery = 0;
    }
}

void Mountain::setAccessRestricted() {
    accessRestricted = getTypesOfRoutes() == "hard";
}

void Mountain::setNoOfStops(int noOfStops) {
    this->noOfStops = noOfStops;
}

string Mountain::getTypesOfRoutes() const {
    if(typesOfRoutes == 0)
        return "easy";
    else if(typesOfRoutes == 1)
        return "medium";
    else if(typesOfRoutes == 2)
        return "hard";
}

bool Mountain::getAccessRestricted() const {
    return accessRestricted;
}

int Mountain::getNoOfStops() const {
    return noOfStops;
}

int Mountain::getNoOfMonastery() const {
    return noOfMonastery;
}

Monastery *Mountain::getMonastery(int i) const {
    assert(i >= 0 && i < noOfMonastery);
    return manastiri[i];

}

void Mountain::read(istream &in) {
    int typesOfRoutes, noOfStops;
    in >> typesOfRoutes >> noOfStops;
    in.get();
    setTypesOfRoutes(typesOfRoutes);
    setAccessRestricted();
    setNoOfStops(noOfStops);
}

void Mountain::write(ostream &out) const {
    out << "Type of route is " << getTypesOfRoutes() << ".\n";
    if(getAccessRestricted())
        out << "Access is restricted for children under 16 and for adults aged over 90.\n";
    out << "Number of stops is : " << getNoOfStops() << ".\n";
    int n = getNoOfMonastery();
    if(n) {
        out << "Number of monastaries : " << n << ".\n";
        for (int i = 0; i < n; ++i)
            out << *manastiri[i] << "\n";
    }
}