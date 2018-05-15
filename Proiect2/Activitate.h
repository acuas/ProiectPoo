//
// Created by auras on 09.05.2018.
//

#ifndef PROIECT2_ACTIVITATE_H
#define PROIECT2_ACTIVITATE_H
#include <iostream>
#include "extendException.h"
using namespace std;

//This is an abstract class

class Activitate {
    protected:
        string name;
        int sex; //0 for man, 1 for woman and 2 if doesn't matter
        pair<int, int> ageGroup;
        bool carNeed;
        double daysNeed; //poate sa fie si 1/2 dintr-o zi
        double distance;
        bool isGroupActivity;
        //I made these setters protected because it can be called just by the constructor
        void setName(string);
        void setSex(int);
        void setAgeGroup(pair<int, int>);
        void setCarNeed(int);
        void setDaysNeed(double);
        void setIsGroupActivity(int);
        void setDistance(double);
    public:
        //Constructors and destructor
        Activitate() = default;
        explicit Activitate(string, int, pair<int, int>, double, double, int);
        Activitate(const Activitate &) = default;
        virtual ~Activitate() = default;

        //Methods to manipulate the class
        string getName() const;
        string getSex() const;
        pair<int, int> getAgeGroup() const;
        bool getCarNeed() const;
        double getDaysNeed() const;
        double getDistance() const;
        bool getIsGroupActivity() const ;
        virtual void read(istream &) = 0;
        virtual void write(ostream &) const = 0;

        static int comparaActivitati(Activitate *, Activitate *);

        //Overloading operator
        friend istream &operator>>(istream &in, Activitate &);
        friend ostream &operator<<(ostream &out, const Activitate &);
};


#endif //PROIECT2_ACTIVITATE_H
