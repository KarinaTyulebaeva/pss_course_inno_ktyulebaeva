//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_PASSENGER_H
#define UNTITLED13_PASSENGER_H

#include <string>
#include <vector>
#include <iostream>
#include "Order.h"

using namespace std;

class Passenger {
    string name;
    double rating;
    string login;
    string password;
    vector<Order> orderHistory;
    vector<string> paymentMethods;
    vector<string> pinnedAddresses;
public:
    Passenger();

    Passenger(string Name, string Login, string Password, double Rating, string PayemtMethods, string PinnedAddresses);

    string getName();

    double getRating();

    string getLogin();

    string getPassword();

    friend class PassengerGateway;
};


#endif //UNTITLED13_PASSENGER_H
