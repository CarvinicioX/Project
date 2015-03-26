#ifndef VIRUS_H
#define VIRUS_H

#include "Digimon.h"
#include "QString"

using namespace std;

class Virus:public Digimon {
    int Type;
public:
    Virus(QString, int, int, QString);
    Virus(const Digimon&);
    virtual ~Virus();
    int Defend(int)const;
    int getType()const;
    virtual string toString()const;
};

#endif // VIRUS_H
