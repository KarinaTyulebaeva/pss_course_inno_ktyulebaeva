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
    double x = 0;
    double y = 0;
public:
    string getModel();

    string getColor();

    string getNumber();

    int typeOfCar;

    double getX();

    double getY();

    Car(string Model, string Color, string Number, int Type, double X, double Y);

    Car();
};

class Economy : public Car {

};

class Comfort : public Economy {
    int freeBottleOfWater;
public:
    int getFreeBottleOfWater();
};

class ComfortPlus : public Comfort {

};

class Business : public ComfortPlus {
    void parkRightInFrontOfTheEntrance();

};


#endif //UNTITLED13_CAR_H
