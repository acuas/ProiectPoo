//
// Created by auras on 10.05.2018.
//

#include "Museums.h"

Museums::Museums(const string &name, int sex, pair<int, int> ageGroup, double distance, double daysNeed, \
                 int isGroupActivity, int typesOfMuseums, int accessRestricted) :                        \
                 Activitate(name, sex, ageGroup, distance, daysNeed, isGroupActivity) {
    setTypesOfMuseums(typesOfMuseums);
    setAccessRestricted(accessRestricted);
}

void Museums::setTypesOfMuseums(int typesOfMuseums) {
    this->typesOfMuseums = typesOfMuseums;
}

void Museums::setAccessRestricted(int accessRestricted) {
    if(getTypesOfMuseums() == "science") {
        try {
            if(accessRestricted == 0 || accessRestricted == 1)
                this->accessRestricted = static_cast<bool>(accessRestricted);
            else
                throw -1;
        }
        catch(const int &e) {
            cout << "The access for women can be restricted or not! Another option it does not exist!.\n";
            exit(EXIT_FAILURE);
        }
    }
    else
        this->accessRestricted = false;
}

string Museums::getTypesOfMuseums() const {
    switch (typesOfMuseums) {
        case 0 : {
            return "art";
        }
        case 1 : {
            return "history";
        }
        case 2 : {
            return "science";
        }
    }
}

bool Museums::getAccessRestricted() const {
    return accessRestricted;
}

void Museums::read(istream &in) {
    int typesOfMuseums, accessRestricted;
    in >> typesOfMuseums >> accessRestricted;
    in.get();
    setTypesOfMuseums(typesOfMuseums);
    setAccessRestricted(accessRestricted);
}

void Museums::write(ostream &out) const {
    out << "The museum is of the type " << getTypesOfMuseums() << ".\n";
    if(getTypesOfMuseums() == "science") {
        if(getAccessRestricted())
            out << "The museum is restricted for woman.\n";
        else
            out << "The museum isn't restricted for woman.\n";
    }
}