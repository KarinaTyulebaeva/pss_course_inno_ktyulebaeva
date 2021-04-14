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
#include "DriverGateway.h"
using namespace std;

class Driver {
   string name;
   double rating;
   vector<Order> orderHistory;
   Car ownCar;
   bool WorkStatus;
   bool RideStatus;
public:
    string getName();
    double getRating();
    bool getWorkStatus();
    bool getRideStatus();
 friend class DriverGateway;

};


#endif //UNTITLED13_DRIVER_H
