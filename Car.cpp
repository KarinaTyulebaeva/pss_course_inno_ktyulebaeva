//
// Created by user on 14.04.2021.
//

#include "Car.h"

string Car::getModel() {
    return this->model;
}

string Car::getColor() {
    return this->color;
}

string Car::getNumber() {
    return this->number;
}

double Car::getX() {
    return this->x;
}

double Car::getY() {
    return this->y;
}

Car::Car(string Model, string Color, string Number, int Type, double X, double Y) {
    this->model = Model;
    this->color = Color;
    this->number = Number;
    this->typeOfCar = Type;
    this->x = X;
    this->y = Y;

}

Car::Car() {

}

int Comfort::getFreeBottleOfWater() {
    return this->freeBottleOfWater;
}

void Business::parkRightInFrontOfTheEntrance() {

}
