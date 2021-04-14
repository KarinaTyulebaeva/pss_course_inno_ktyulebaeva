//
// Created by user on 14.04.2021.
//

#include "Passenger.h"

string Passenger::getName() {
    return this->name;
}

double Passenger::getRating() {
    return this->rating;
}

Passenger::Passenger(string Name, string Login, string Password, double Rating, string PayemtMethods,
                     string PinnedAddresses) {
    this->name = Name;
    this->login = Login;
    this->password = Password;
    this->rating = Rating;
    this->paymentMethods.emplace_back(PayemtMethods);
    this->pinnedAddresses.emplace_back(PinnedAddresses);

}

Passenger::Passenger() {

}

string Passenger::getLogin() {
    return this->login;
}

string Passenger::getPassword() {
    return this->password;
}
