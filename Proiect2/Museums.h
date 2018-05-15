//
// Created by auras on 10.05.2018.
//

#ifndef PROIECT2_MUSEUMS_H
#define PROIECT2_MUSEUMS_H
#include "Activitate.h"

class Museums final : public Activitate {
    private:
        int typesOfMuseums; //0 -> art, 1 -> history, 2 -> science
        bool accessRestricted;
        void setTypesOfMuseums(int);
        void setAccessRestricted(int);
    public:
        //Constructors and destructor
        Museums() = default;
        explicit Museums(const string &, int, pair<int, int>, double, double, int, int, int);
        Museums(const Museums &) = default;
        ~Museums() override = default;

        //Methods to manipulate the class
        string getTypesOfMuseums() const;
        bool getAccessRestricted() const;
        //Overriding virtual methods
        void read(istream &) override;
        void write(ostream &) const override;
};


#endif //PROIECT2_MUSEUMS_H
