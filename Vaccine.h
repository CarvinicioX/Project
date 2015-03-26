#ifndef VACUNA_H
#define VACUNA_H

#include "Digimon.h"
#include "QString"

using namespace std;

class Vaccine:public Digimon {
    int Type;
public:
    Vaccine(QString, int, int, QString);
    Vaccine(const Digimon&);
    virtual ~Vaccine();
    int Defend(int)const;
    virtual string toString()const;
    virtual int getType()const;
};

#endif // VACUNA_H
