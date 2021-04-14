//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_DRIVER_H
#define UNTITLED13_DRIVER_H

#include <string>
#include<iostream>
#include<vector>
#include "Order.h"
#include "Car.h"


using namespace std;

class Driver {
    string name;
    double rating;
    vector<Order> orderHistory;
    Car ownCar;
    bool WorkStatus = 1;
    bool RideStatus = 1;
    string login;
    string password;
public:
    Driver(string Name, string Login, string Password, double Rating, Car car);

    Driver();

    string getLogin();

    string getPassword();

    string getName();

    double getRating();

    bool getWorkStatus();

    bool getRideStatus();

    friend class DriverGateway;

    friend class PassengerGateway;
};


#endif //UNTITLED13_DRIVER_H
