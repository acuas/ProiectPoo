//
// Created by auras on 13.03.2018.
//

#ifndef APLICATIA1_DRIVE_H
#define APLICATIA1_DRIVE_H


#include "LinkedList.h"
#include <iostream>
using namespace std;

class Drive{
    private :
        LinkedList *list;
        enum optiuni{
            opt1 = 1, opt2, opt3, opt4, opt5
        };
    public :
        Drive();
        ~Drive();
};

#endif //APLICATIA1_DRIVE_H
