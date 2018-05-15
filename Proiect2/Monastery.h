//
// Created by auras on 10.05.2018.
//

#ifndef PROIECT2_MONASTERY_H
#define PROIECT2_MONASTERY_H
#include "Activitate.h"

class Monastery final : public Activitate {
    private:
        string religion;
    public:
        Monastery() = default;
        explicit Monastery(const string &, int, pair<int, int>, double, double, int, string);
        Monastery(const Monastery &) = default;
        ~Monastery() override = default;

        int writePomelnic();
        string getReligion() const;

        void read(istream &) override;
        void write(ostream &) const override;
};


#endif //PROIECT2_MONASTERY_H
