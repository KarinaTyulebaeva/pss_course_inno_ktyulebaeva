//
// Created by user on 14.04.2021.
//

#ifndef UNTITLED13_ORDER_H
#define UNTITLED13_ORDER_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;


class Order {
    string from;
    string to;
    double price;

public:
    Order(string AddressFrom, string AddressTo, double cost);

    string getFrom();

    string getTo();

    double getPrice();
};


#endif //UNTITLED13_ORDER_H
