#ifndef DIGIMON_H
#define DIGIMON_H

#include "string"
#include "QString"

using std::string;

class Digimon {
protected:
    string Name;
    int Hp;
    int Attack;
    QString image;
public:
    Digimon(string, int, int, QString);
    ~Digimon();
    int getHp()const;
    string getName()const;
    virtual string toString()const;
    virtual int getType()const=0;
};

#endif // DIGIMON_H
