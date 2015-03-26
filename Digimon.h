#ifndef DIGIMON_H
#define DIGIMON_H

#include "QString"

using namespace std;

class Digimon {
protected:
    QString Name;
    int Hp;
    int Attack;
    QString image;
    bool Defense;
public:
    Digimon(QString, int, int, QString);
    Digimon(const Digimon&);
    virtual ~Digimon();
    int getHp()const;
    QString getName()const;
    int getAttack()const;
    QString getImage()const;
    virtual string toString()const;
    virtual int getType()const=0;
};

#endif // DIGIMON_H
