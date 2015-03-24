#ifndef VACUNA_H
#define VACUNA_H

#include "Digimon.h"
#include "string"

using std::string;

class Vaccine:public Digimon {
    int Type;
public:
    Vaccine(string, int, int, QString);
    ~Vaccine();
    int Defend(int)const;
    virtual string toString()const;
    virtual int getType()const;
};

#endif // VACUNA_H
