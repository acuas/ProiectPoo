//
// Created by auras on 10.05.2018.
//

#ifndef PROIECT2_MOUNTAIN_H
#define PROIECT2_MOUNTAIN_H
#include "Activitate.h"
#include "Monastery.h"

class Mountain final : public Activitate {
    private:
        int typesOfRoutes; //0 -> easy route, 1 -> medium route, 2 -> hard route
        bool accessRestricted; // It is available just if route is hard
        int noOfStops;
        int noOfMonastery;
        Monastery **manastiri;

        void setTypesOfRoutes(int);
        void setAccessRestricted();
        void setNoOfStops(int);
        void setNoOfMonastery(int);
    public:
        //Constructors and destructor
        Mountain() = default;
        explicit Mountain(const string &, int, pair<int, int>, double, double, int, int, int, int, Monastery **);
        Mountain(const Mountain &);
        ~Mountain() override;

        //Methods to manipulate the class
        string getTypesOfRoutes() const;
        bool getAccessRestricted() const;
        int getNoOfStops() const;
        int getNoOfMonastery() const;
        Monastery *getMonastery(int) const;

        Mountain operator=(const Mountain &);
        //Overriding virtual methods
        void read(istream &) override;
        void write(ostream &) const override;
};


#endif //PROIECT2_MOUNTAIN_H
