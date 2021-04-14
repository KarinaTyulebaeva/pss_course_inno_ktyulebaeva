//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_PASSENGERGATEWAY_H
#define UNTITLED13_PASSENGERGATEWAY_H
#include <string>
#include <vector>
#include <iostream>
#include "Passenger.h"
using namespace std;

class PassengerGateway {

   vector<Passenger> passengersDatabase;
    Passenger currentPassenger;
    PassengerGateway(Passenger passenger);

    void seeOrderHistory();
    void seePaymentMethods();
    void addPaymentMethod(string newMethod);
    void deletePaymentMethod(int number);
    void seePinnedAddresses();
    void addPinnedAddress(string newAddress);
    void deletePinnedAddress(int number);
    void checkRide(string from, string to, int carType);
    void


};


#endif //UNTITLED13_PASSENGERGATEWAY_H
