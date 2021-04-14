//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_PASSENGERGATEWAY_H
#define UNTITLED13_PASSENGERGATEWAY_H

#include <string>
#include <vector>
#include <iostream>
#include "Passenger.h"
#include "Order.h"
#include "DriverGateway.h"

using namespace std;

class PassengerGateway {
public:
    vector<Passenger> passengersDatabase;

    inline PassengerGateway() = default;

    //  int index;
    Passenger currentPassenger; //=passengersDatabase[index];
    void seeOrderHistory();

    void seePaymentMethods();

    void addPaymentMethod(string newMethod);

    void deletePaymentMethod(int number);

    void seePinnedAddresses();

    void addPinnedAddress(string newAddress);

    void deletePinnedAddress(int number);

    double checkRide(string from, string to, int carType);

    void orderRide(Order order, DriverGateway DriverInterface, int type);

    void StartRide(Order order, Driver driver, DriverGateway DriverInterface, int type);

    void FinishRide(Order order, Driver driver, DriverGateway DriverInterface);

    void askCurrentCoordinates();
};


#endif //UNTITLED13_PASSENGERGATEWAY_H
