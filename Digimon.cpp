#include "Digimon.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Digimon::Digimon(string Name, int Hp, int Attack, QString image) {
    this->Name = Name;
    this->Hp = Hp;
    this->Attack = Attack;
    this->image = image;
}

Digimon::~Digimon() {
}

int Digimon::getHp()const {
    return Hp;
}

string Digimon::getName()const {
    return Name;
}

string Digimon::toString()const {
    stringstream ss;
    ss << "Name: " << Name << ", Hp: " << Hp << ", Attack: " << Attack;
    return ss.str();
}
