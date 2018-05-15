//
// Created by auras on 09.05.2018.
//

#ifndef PROIECT2_BEACH_H
#define PROIECT2_BEACH_H
#include "Activitate.h"

class Beach final : public Activitate {
    private:
        bool landType; //0 -> sand and 1 -> small pebbles
        bool nudists; //0 -> non-nudists and 1 -> nudists
        bool allowMinor;

        void setLandType(int landType);
        void setNudists(int nuditst);
        void setAllowMinor(int allowMinor);
    public:
        //Constructors and destructor
        Beach() = default;
        explicit Beach(const string &, int, pair<int, int>, double, double, int, int, int, int);
        Beach(const Beach &) = default;
        ~Beach() override = default;

        //Methods to manipulate the class
        string getLandType() const;
        bool getNudists() const;
        bool getAllowMinor() const;

        //Overriding virtual methods
        void read(istream &) override;
        void write(ostream &) const override;
};

#endif //PROIECT2_BEACH_H
