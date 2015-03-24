#ifndef VIRUS_H
#define VIRUS_H

#include "Digimon.h"
#include "string"

using std::string;

class Virus:public Digimon {
    int Type;
public:
    Virus(string, int, int, QString);
    ~Virus();
    int Defend(int)const;
    int getType()const;
    virtual string toString()const;
};

#endif // VIRUS_H
