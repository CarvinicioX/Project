#include "DigiDestined.h"
#include "Digimon.h"
#include "Vaccine.h"
#include "Data.h"
#include "Virus.h"
#include <string>
#include <sstream>
#include <vector>

using std::string;
using std::stringstream;
using std::vector;

DigiDestined::DigiDestined(string Name, QString Image) {
    this->Name = Name;
    this->Image = Image;
}

DigiDestined::~DigiDestined()
{
    for (int i = 0; i < Vpet.size(); i++) {
        delete Vpet[i];
    }
    Vpet.clear();
}

void DigiDestined::setWinns() {
    Winns = 0;
}

void DigiDestined::setDigimon(Digimon* rhs) {
    Vpet.push_back(rhs);
}

QString DigiDestined::getImage()const {
    return Image;
}

string DigiDestined::getName()const {
    return Name;
}

int DigiDestined::getWinns()const {
    return Winns;
}

string DigiDestined::toString()const {
    stringstream ss;
    ss << "DigiDestines: " << Name << ", Winns: " << Winns << ", ";
    for (int i = 0; i < Vpet.size(); i++) {
        ss << Vpet[i]->toString();
    }
    return ss.str();
}
