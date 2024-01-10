#include <superpes.h>

void Swimming::showTalent() const {
    std::cout << "It can swim" << std::endl;
}
void Dancing::showTalent() const {
    std::cout << "It can dance" << std::endl;
}
void Counting::showTalent() const {
    std::cout << "It can count" << std::endl;
}
void Boxing::showTalent() const {
    std::cout << "it can box" << std::endl;
}
Dog::Dog(int _age, std::string _name) : name(std::move(_name)),
                                        isSwim(false),
                                        isDance(false),
                                        isCount(false),
                                        isBox(false)
{
    while (!( _age >= 0 && _age < 30 ))
    {
        std::cerr << "Incorrect age, please input again" << std::endl;
        std::cin >> _age;
    }
    age = _age;
}

void Dog::addTalent()
{
    std::string tempStr;
    std::cout << "Which talent do you want to add(swim, dance, count, box)?" << std::endl;
    std::cin >> tempStr;

    while ((tempStr != "swim" &&
            tempStr != "dance" &&
            tempStr != "count" &&
            tempStr != "box") ||
           (tempStr == "swim" && isSwim) ||
           (tempStr == "dance" && isDance) ||
           (tempStr == "count" && isCount) ||
           (tempStr == "box" && isBox))
    {
        std::cerr << "Incorrect talent, please, input again" << std::endl;
        std::cin >> tempStr;
    }
    if (tempStr == "swim") {
        talents.push_back(new Swimming());
        isSwim = true;
    }
    else if (tempStr == "dance") {
        talents.push_back(new Dancing());
        isDance = true;
    }
    else if (tempStr == "count") {
        talents.push_back(new Counting());
        isCount = true;
    }
    else if (tempStr == "box") {
        talents.push_back(new Boxing());
        isBox = true;
    }
}

void Dog::showTalents() {
    std::cout << "This is a " << name << ", it's " << age << " years old" << std::endl;
    if (talents.empty()) {
        std::cout << name << " has got no talents :(" << std::endl;
    }
    for (auto & talent : talents) {
        talent->showTalent();
    }
}

Dog::~Dog() {
    for (auto &talent: talents)
        delete talent;
}