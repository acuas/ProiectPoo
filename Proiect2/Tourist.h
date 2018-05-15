//
// Created by auras on 08.05.2018.
//

#ifndef PROIECT2_TOURIST_H
#define PROIECT2_TOURIST_H
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "extendException.h"
#include "Activitate.h"
using namespace std;

class Tourist {
    private:
        string name;
        bool sex; //The codification is 0 for man and 1 for woman
        int age; //The age for every tourist
        int noOfActivities;
        Activitate **pActivitati;
        void setSex(const string &);
        void setAge(const int &);
    public:
        Tourist();
        explicit Tourist(const string &, const string &, const int &, const int &, Activitate **);
        Tourist(const Tourist &);
        ~Tourist();

        string getName() const;
        string getSex() const;
        string getGroupAge() const;
        int getNoOfActivities() const;
        Activitate *getActivitate(int) const;

        friend istream &operator>>(istream &, Tourist &);
        friend ostream &operator<<(ostream &, const Tourist &);
};


#endif //PROIECT2_TOURIST_H
