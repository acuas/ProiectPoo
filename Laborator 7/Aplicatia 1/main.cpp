#include <iostream>
#include <cstring>

using namespace std;

class student {
    protected:
        char *nume, *prenume;
        int year, varsta;
    public:
        virtual void display();

        student(char *, int);
        virtual ~student();
};

void student::display() {
    if(nume != nullptr)
        cout << nume << ' ' << year << '\n';
}

student::student(char *nume, int x) {
    this->prenume = nullptr;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->year = x; // anul de studiu
}

student::~student() {
    delete[] nume;
    delete[] prenume;
}

class on_campus : public student {
    private:
        char *dorm, *room;
    public:
        virtual void display() {
            cout << nume << ' ' << year << '\n';
            cout << dorm << ' ' << room << '\n';
        }
        on_campus(char *, int, char *, char *);
        virtual ~on_campus();
};

on_campus::on_campus(char *nume, int an, char *dorm, char *room) : student(nume, an) {
    this->dorm = new char[strlen(dorm) + 1];
    this->room = new char[strlen(room) + 1];
    strcpy(this->dorm, dorm);
    strcpy(this->room, room);
}

on_campus::~on_campus() {
    delete[] dorm;
    delete[] room;
}

class off_campus : public student {
    private:
        char *strada, *oras;
        int nr;
    public:
        void display();

        off_campus(char *,  int, char *, char *, int);
        virtual ~off_campus();
};

void off_campus::display() {
    cout << nume << ' ' << year << '\n';
    cout << strada << ' ' << oras << ' ' << nr << '\n';
}

off_campus::off_campus(char *nume, int an, char *strada, char *oras, int nr) :
        student(nume, an) {
    this->strada = new char[strlen(strada) + 1];
    this->oras = new char[strlen(oras) + 1];
    strcpy(this->strada, strada);
    strcpy(this->oras, oras);
    this->nr = nr;
}

off_campus::~off_campus() {
    delete[] strada;
    delete[] oras;
}

class Node {
    private:
        student *info;
        Node *next;
    public:
        explicit Node(student *, Node *);

        void setNext(Node *);
        Node* getNext() {
            return next;
        }
        student* getInfo() {
            return info;
        }
};

Node::Node(student *A, Node *next) {
    info = A;
    this->next = next;
}

void Node::setNext(Node *next) {
    this->next = next;
}

class LinkedList {
    private:
        Node *A;
    public:
        LinkedList();
        void insertFront(student *);
        void print();
};

LinkedList::LinkedList() {
    A = nullptr;
}

void LinkedList::insertFront(student *info) {
    auto elem = new Node(info, A);
    A = elem;
}

void LinkedList::print() {
    Node * cross = A;
    while(cross) {
        cross->getInfo()->display();
        cross = cross->getNext();
    }
}

int main() {
    LinkedList cap = LinkedList();
    auto Aur = new on_campus("popescu", 1, "p5", "214");
    auto Diana = new off_campus("Moromete" , 3, "Agriculturii", "Targu Jiu", 24);
    auto Maria = new on_campus("Duta" , 3, "p6", "312");
    cap.insertFront(Aur);
    cap.insertFront(Diana);
    cap.insertFront(Maria);
    cap.print();
    return 0;
}