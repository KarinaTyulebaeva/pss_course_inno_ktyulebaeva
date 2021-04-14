//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_PASSENGER_H
#define UNTITLED13_PASSENGER_H
#include <string>
#include <vector>
#include <iostream>
#include "Order.h"
#include "PassengerGateway.h"
using namespace std;

class Passenger {
  string name;
  double rating;
  vector<Order> orderHistory;
  vector<string> paymentMethods;
  vector<string> pinnedAddresses;
public:
    string getName();
    double getRating();
    friend class PassengerGateway;

};


#endif //UNTITLED13_PASSENGER_H
