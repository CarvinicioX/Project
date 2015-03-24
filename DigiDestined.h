#ifndef DIGIDESTINED_H
#define DIGIDESTINED_H

#include "Digimon.h"
#include "Vaccine.h"
#include "Data.h"
#include "Virus.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class DigiDestined {
    string Name;
    int Winns;
    vector<Digimon*> Vpet;
    QString Image;
public:
    DigiDestined(string, QString);
    ~DigiDestined();
    void setWinns();
    void setDigimon(Digimon*);
    QString getImage()const;
    string getName()const;
    int getWinns()const;
    string toString()const;
};

#endif // DIGIDESTINED_H
