#ifndef DATA_H
#define DATA_H

#include "Digimon.h"
#include "QString"

using namespace std;

class Data: public Digimon {
    int Type;
public:
    Data(QString, int, int, QString);
    Data(const Digimon&);
    virtual ~Data();
    int Defend(int)const;
    int getType()const;
    virtual string toString()const;
};

#endif // DATA_H
