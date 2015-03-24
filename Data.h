#ifndef DATA_H
#define DATA_H

#include "Digimon.h"
#include "string"

using std::string;

class Data: public Digimon {
    int Type;
public:
    Data(string, int, int, QString);
    ~Data();
    int Defend(int)const;
    int getType()const;
    virtual string toString()const;
};

#endif // DATA_H
