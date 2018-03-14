//
// Created by auras on 14.03.2018.
//

#ifndef APLICATIA2_DRIVE_H
#define APLICATIA2_DRIVE_H
#include "Queue.h"

class Drive{
    private:
        Queue *Q;
        enum optiuni{
            opt1 = 1, opt2, opt3, opt4, opt5, opt6, opt7
        };
    public:
        Drive();
        ~Drive();
};

#endif //APLICATIA2_DRIVE_H
