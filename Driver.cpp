//
// Created by user on 14.04.2021.
//

#include "Driver.h"


string Driver::getName() {
    return this->name;
}

double Driver::getRating() {
    return this->rating;
}

bool Driver::getWorkStatus() {
    return this->WorkStatus;
}

bool Driver::getRideStatus() {
    return this->RideStatus;
}


Driver::Driver() {

}

Driver::Driver(string Name, string Login, string Password, double Rating, Car car) {
    this->name = Name;
    this->login = Login;
    this->password = Password;
    this->rating = Rating;
    this->ownCar = car;
}

string Driver::getLogin() {
    return this->login;
}

string Driver::getPassword() {
    return this->password;
}
