#include "Virus.h"
#include "Digimon.h"
#include "string"
#include "sstream"

using std::string;
using std::stringstream;

Virus::Virus(string Name, int Hp, int Attack, QString image):Digimon(Name, Hp, Attack, image){
    this->Type = 1;
}

Virus::~Virus()
{

}

int Virus::Defend(int Type)const {
    if (Type == 1) {
        return 0;
    } else if (Type == 2) {
        return Attack;
    } else if (Type == 3) {
        return Attack/2;
    }
    return 0;
}

int Virus::getType()const {
    return 3;
}

string Virus::toString()const {
    stringstream ss;
    ss << Digimon::toString() << ", Attribute: Vaccine";
    return ss.str();
}
