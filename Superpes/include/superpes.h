#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Talent                                 //abstract class
{
public:
    virtual void showTalent() const = 0;
};

class Swimming : virtual public Talent {     //swimming
public:
    void showTalent() const override;
};
class Dancing : virtual public Talent {      //dancing
public:
    void showTalent() const override;
};
class Counting : virtual public Talent {     //counting
public:
    void showTalent() const override;
};
class Boxing : virtual public Talent {       //boxing
public:
    void showTalent() const override;
};

class Dog                                    //main class
{
    std::string name;
    int age;
    std::vector<Talent*> talents;
    bool isSwim, isDance, isCount, isBox;
public:
    Dog(int _age, std::string _name);
    ~Dog();
    void addTalent();
    void showTalents();
};