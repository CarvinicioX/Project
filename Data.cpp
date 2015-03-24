#include "Data.h"
#include "Digimon.h"
#include "string"
#include "sstream"

using std::string;
using std::stringstream;

Data::Data(string Name, int Hp, int Attack, QString image):Digimon(Name, Hp, Attack, image){
    this->Type = 2;
}

Data::~Data()
{

}

int Data::Defend(int)const {
    if (Type == 1) {
        return Attack;
    } else if (Type == 2) {
        return Attack/2;
    } else if (Type == 3) {
        return 0;
    }
    return 0;
}

int Data::getType()const {
    return 0;
}

string Data::toString()const {
    stringstream ss;
    ss << Digimon::toString() << ", Attribute: Data";
    return ss.str();
}
