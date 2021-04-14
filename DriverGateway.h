//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_DRIVERGATEWAY_H
#define UNTITLED13_DRIVERGATEWAY_H
#include <string>
#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Driver.h"
using namespace std;

class DriverGateway {
    vector<Driver> driversDatabase;
    Driver currentDriver;
    DriverGateway(Driver driver);
    void seeOrderHistory();
};


#endif //UNTITLED13_DRIVERGATEWAY_H
