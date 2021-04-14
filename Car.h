//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_CAR_H
#define UNTITLED13_CAR_H
#include <string>
#include <iostream>
using namespace std;


class Car {
string model;
string color;
string number;
double x;
double y;
public:
    string getModel();
    string getColor();
    string getNumber();
    double getX();
    double getY();

};

class Economy : public Car{

};

class Comfort : public Economy{
   int freeBottleOfWater;
public:
    int getFreeBottleOfWater();
};

class ComfortPlus : public Comfort{

};

class Business : public ComfortPlus{
  void parkRightInFrontOfTheEntrance();

};


#endif //UNTITLED13_CAR_H
