//
// Created by auras on 08.05.2018.
//

#ifndef PROIECT2_DESTINATION_H
#define PROIECT2_DESTINATION_H
#include <string>
#include <iostream>
#include "Tourist.h"
#include "Activitate.h"
#include "Museums.h"
#include "Beach.h"
#include "Monastery.h"
#include "Mountain.h"

using namespace std;

class Destination {
    protected:
        string moneda;
        string fusOrar;
        int populatie;
        int nrActivitati;
        double pret;
        bool inchiriereAutovehicule;
        Activitate **activitati;
        explicit Destination(const string &, const string &, const int &, const double &);

        void setNrActivitati(int);
    public:
        static Destination *Create(int); //Simulating virtual constructor
        Destination(const Destination &) = delete;
        virtual ~Destination();

        //Getters
        int getNumarActivitati() const;
        string getMoneda() const;
        string getFusOrar() const;
        int getPopulatie() const;
        double getPret() const;
        bool getInchiriereAutovehicule() const;
        Activitate *getActivitate(int) const;
        virtual void Display(ostream &) const = 0;

        //Overloading operators
        void operator=(const Destination &) = delete;
        friend ostream &operator<<(ostream &out, const Destination &obj);
};

class Thassos final : public Destination {
    private:
        static Thassos *instance;
        Thassos(const string &moneda, const string &fusOrar, const int &populatie, const double &pret);
    public:
        Thassos(const Thassos &) = delete;
        ~Thassos() override = default;
        void operator=(const Thassos &) = delete;

        static Thassos *getInstance();

        void Display(ostream &) const override;
};

class Amsterdam final : public Destination {
    private:
        static Amsterdam *instance;
        explicit Amsterdam(const string &moneda, const string &fusOrar, const int &populatie, const double &pret);
    public:
        Amsterdam(const Amsterdam &) = delete;
        ~Amsterdam() override = default;
        void operator=(const Amsterdam &) = delete;

        static Amsterdam *getInstance();

        void Display(ostream &) const override;
};

class Razlog final : public Destination {
    private:
        static Razlog *instance;
        explicit Razlog(const string &moneda, const string &fusOrar, const int &populatie, const double &pret);
    public:
        Razlog(const Razlog &) = delete;
        ~Razlog() override = default;
        void operator=(const Razlog) = delete;

        static Razlog *getInstance();

        void Display(ostream &) const override;
};

#endif //PROIECT2_DESTINATION_H
