//
// Created by auras on 08.05.2018.
//

#include <typeinfo>
#include <cassert>
#include "Destination.h"
#include "extendException.h"

Thassos *Thassos::instance = nullptr;
Amsterdam *Amsterdam::instance = nullptr;
Razlog *Razlog::instance = nullptr;

Destination::Destination(const string &moneda, const string &fusOrar, const int &populatie, const double &pret) {
    this->moneda = moneda;
    this->fusOrar = fusOrar;
    this->populatie = populatie;
    this->pret = pret;
    activitati = nullptr;
}

Destination *Destination::Create(const int id) {
    Destination *dest = nullptr;
    try {
        if (id == 1) {
            dest = dynamic_cast<Destination *>(Thassos::getInstance());
        }
        else if (id == 2) {
            dest = dynamic_cast<Destination *>(Amsterdam::getInstance());
        }
        else if (id == 3) {
            dest = dynamic_cast<Destination *>(Razlog::getInstance());
        }
        else
            throw bad_create();
    }
    catch (bad_create& e) {
        cout << e.what();
    }
    return dest;
}

Destination::~Destination() {
    for (int i = 0; i < nrActivitati; ++i) {
        delete activitati[i];
    }
    delete[] activitati;
}

void Destination::setNrActivitati(int nrActivitati) {
    this->nrActivitati = nrActivitati;
}

string Destination::getMoneda() const {
    return moneda;
}

string Destination::getFusOrar() const {
    return fusOrar;
}

int Destination::getPopulatie() const {
    return populatie;
}

double Destination::getPret() const {
    return pret;
}

bool Destination::getInchiriereAutovehicule() const {
    return inchiriereAutovehicule;
}

int Destination::getNumarActivitati() const {
    return nrActivitati;
}

Activitate *Destination::getActivitate(int i) const {
    assert(i >= 0 && i < nrActivitati);
    return activitati[i];
}

ostream &operator<<(ostream &out,const Destination &obj) {
    out << "Destination name : ";
    obj.Display(out);
    out << '\n';
    out << "Currency : " << obj.getMoneda() << '\n';
    out << "Time zone : " << obj.getFusOrar() << '\n';
    out << "Population : " << obj.getPopulatie() << '\n';
    out << "Price : " << obj.getPret() << '\n';
    out << "You ";
    if(obj.getInchiriereAutovehicule())
        out << "can ";
    else
        out << "can not ";
    out << "rent a car.\n";
    int n = obj.getNumarActivitati();
    out << "Number of activities : " << n << '\n';
    for(int i = 0; i < n; ++i)
        out << *obj.activitati[i] << '\n';
    return out;
}

Thassos *Thassos::getInstance() {
    if(instance == nullptr) {
        static Thassos self("EUR", "UTC+3", 11305118, 1000);
        instance = &self;
    }

    return instance;
}

Thassos::Thassos(const string &moneda, const string &fusOrar, const int &populatie, const double &pret) : \
                 Destination(moneda, fusOrar, populatie, pret) {
    setNrActivitati(5);
    activitati = new Activitate*[5];
    activitati[0] = new Beach("Golden Beach", 2, {1, 199}, 1, 0.5, 1, 0, 0, 1);
    activitati[1] = new Beach("Paradise Beach", 2, {1, 199}, 3, 1, 1, 1, 0, 1);
    activitati[2] = new Beach("Marble", 2, {18, 65}, 5, 1, 1, 1, 1, 0);
    auto **vec = new Monastery*[2];
    vec[0] = new Monastery("Archangel Michael Monastery", 2, {1, 199}, 2, 0.5, 1, "orthodox");
    vec[1] = new Monastery("St. Panteleimon Monastery", 0, {1, 199}, 10, 0.5, 1, "orthodox");
    activitati[3] = new Mountain("Mount Ipsarion", 2, {1, 199}, 1.2, 0.5, 1, 2, 2, 2, vec);
    activitati[4] = new Museums("Tarsanas museum", 2, {18, 199}, 1.0, 0.5, 1, 0, 0);

    inchiriereAutovehicule = static_cast<bool>(rand() % 2);
}

void Thassos::Display(ostream &out) const {
    out << "Thassos";
}

Amsterdam *Amsterdam::getInstance() {
    if(instance == nullptr) {
        static Amsterdam self("EUR", "UTC+1", 16787689, 3000);
        instance = &self;
    }
    return instance;
}

Amsterdam::Amsterdam(const string &moneda, const string &fusOrar, const int &populatie, const double &pret) : \
                     Destination(moneda, fusOrar, populatie, pret) {
    setNrActivitati(8);
    activitati = new Activitate*[8];
    activitati[0] = new Beach("Strand Zuid", 2, {1, 199}, 1.5, 1, 1, 0, 0, 0);
    activitati[1] = new Beach("Blijburg an Zee", 1, {20, 86}, 3, 1, 1, 1, 0, 1);
    activitati[2] = new Museums("Rijksmuseum Amsterdam", 2, {1, 199}, 0.3, 0.5, 0, 0, 1);
    activitati[3] = new Museums("Van Gogh", 2, {1, 199}, 0.7, 1, 1, 0, 0);
    activitati[4] = new Museums("Tulip Museums", 0, {1, 199}, 1.34, 2, 1, 2, 1);
    activitati[5] = new Museums("Van Loon", 2, {1, 199}, 1.63, 1, 1, 1, 0);
    activitati[6] = new Monastery("Begijnhof", 2, {1, 199}, 1.7, 2, 0, "catholic");
    activitati[7] = new Monastery("Basilica of St. Nicholas", 0, {1, 199}, 2.29, 1, 1, "catholic");

    inchiriereAutovehicule = static_cast<bool>(rand() % 2);
}

void Amsterdam::Display(ostream &out) const {
    out << "Amsterdam";
}

Razlog *Razlog::getInstance() {
    if(instance == nullptr) {
        static Razlog self("BGN", "UTC+2", 7351234, 800);
        instance = &self;
    }
    return instance;
}

Razlog::Razlog(const string &moneda, const string &fusOrar, const int &populatie, const double &pret) :  \
              Destination(moneda, fusOrar, populatie, pret) {                                            \
    setNrActivitati(6);
    activitati = new Activitate*[6];
    auto **vec = new Monastery*[1];
    vec[0] = new Monastery("Rozhen Monastery", 0, {1, 199}, 15, 2, 1, "orthodox");
    activitati[0] = new Mountain("Pirin", 2, {5, 199}, 20, 4, 1, 1, 1, 1, vec);
    activitati[1] = new Monastery("Sveta Troitsa", 0, {1, 199}, 1.4, 1, 1, "orthodox");
    activitati[2] = new Monastery("Holy Trinity", 2, {1, 199}, 10, 2, 1, "orthodox");
    activitati[3] = new Museums("Istoricheski Muzey", 2, {35, 70}, 0.7, 1, 0, 1, 0);
    activitati[4] = new Museums("Museum \"Nikola Vaptsarov\"", 2, {18, 90}, 12, 1, 1, 1, 0);
    activitati[5] = new Museums("\"Neofit Rilski\" House-Museum", 2, {1, 199}, 14, 1, 1, 0, 0);

    inchiriereAutovehicule = static_cast<bool>(rand() % 2);
}

void Razlog::Display(ostream &out) const  {
    out << "Razlog";
}

int Activitate::comparaActivitati(Activitate *a1, Activitate *a2) {
    int nrDiferente = 0;
    if(a1->getName() != a2->getName())
        ++nrDiferente;
    if(a1->getSex() != a2->getSex())
        ++nrDiferente;
    if(a1->getAgeGroup() != a2->getAgeGroup())
        ++nrDiferente;
    if(a1->getCarNeed() != a2->getCarNeed())
        ++nrDiferente;
    if(a1->getDaysNeed() != a2->getDaysNeed())
        ++nrDiferente;
    if(a1->getDistance() != a2->getDistance())
        ++nrDiferente;
    if(a1->getIsGroupActivity() != a2->getIsGroupActivity())
        ++nrDiferente;
    if (dynamic_cast<Beach *>(a1) != nullptr
        && dynamic_cast<Beach *>(a2) != nullptr) {
        auto *p = dynamic_cast<Beach *>(a1);
        auto *q = dynamic_cast<Beach *>(a2);
        if (p->getLandType() != q->getLandType())
            ++nrDiferente;
        if (p->getNudists() != q->getNudists())
            ++nrDiferente;
        if (p->getAllowMinor() != q->getAllowMinor())
            ++nrDiferente;
        return nrDiferente;
    }
    else if (dynamic_cast<Mountain *>(a1) != nullptr
             && dynamic_cast<Mountain *>(a2) != nullptr) {
        auto *p = dynamic_cast<Mountain *>(a1);
        auto *q = dynamic_cast<Mountain *>(a2);
        if (p->getTypesOfRoutes() != q->getTypesOfRoutes())
            ++nrDiferente;
        if (p->getAccessRestricted() != q->getAccessRestricted())
            ++nrDiferente;
        if (p->getNoOfStops() != q->getNoOfStops())
            ++nrDiferente;
        if (p->getNoOfMonastery() != q->getNoOfMonastery())
            ++nrDiferente;
        return nrDiferente;
    }
    else if (dynamic_cast<Museums *>(a1) != nullptr
             && dynamic_cast<Museums *>(a2) != nullptr) {
        auto *p = dynamic_cast<Museums *>(a1);
        auto *q = dynamic_cast<Museums *>(a2);
        if (p->getTypesOfMuseums() != q->getTypesOfMuseums())
            ++nrDiferente;
        if (p->getAccessRestricted() != q->getAccessRestricted())
            ++nrDiferente;
        return nrDiferente;
    }
    else if (dynamic_cast<Monastery *>(a1) != nullptr
             && dynamic_cast<Monastery *>(a2) != nullptr) {
        auto *p = dynamic_cast<Monastery *>(a1);
        auto *q = dynamic_cast<Monastery *>(a2);
        if (p->getReligion() != q->getReligion())
            ++nrDiferente;
        return nrDiferente;
    }
    else
        return -1;
}