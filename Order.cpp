//
// Created by user on 14.04.2021.
//

#include "Order.h"

Order::Order(string AddressFrom, string AddressTo, double cost) {
    this->from = AddressFrom;
    this->to = AddressTo;
    this->price = cost;

}

string Order::getFrom() {
    return this->from;
}

string Order::getTo() {
    return this->to;
}

double Order::getPrice() {
    return this->price;
}
