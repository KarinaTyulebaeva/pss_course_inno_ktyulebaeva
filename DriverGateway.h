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
public:
    vector<Driver> driversDatabase;
    Driver currentDriver;
    vector<Order> listOfAvailableOrders;

    inline DriverGateway() = default;

    void seeOrderHistory(Driver driver);

    void updateWorkStatus(Driver driver);

    void updateRideStatus(Driver driver);

    void seeCar(Driver driver);

    void StartOrder(Driver driver, Order order);

    void FinishOrder(Driver driver);

    void seeAvailableOrders();

    friend class PassengerGateway;
};


#endif //UNTITLED13_DRIVERGATEWAY_H
