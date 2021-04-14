//
// Created by user on 14.04.2021.
//

#include "PassengerGateway.h"

PassengerGateway::PassengerGateway(Passenger passenger) {
this->currentPassenger=passenger;
}

void PassengerGateway::seeOrderHistory() {
    for(int i=0; i<currentPassenger.orderHistory.size(); i++){
        cout<<i+1<<") "<<currentPassenger.orderHistory[i].getFrom()<<" - "<<currentPassenger.orderHistory[i].getTo()<<" : "<<currentPassenger.orderHistory[i].getPrice()<<endl;
    }

}

void PassengerGateway::seePaymentMethods() {
    for(int i=0; i<currentPassenger.paymentMethods.size(); i++){
        cout<<i+1<<") "<<currentPassenger.paymentMethods[i]<<endl;
    }

}

void PassengerGateway::addPaymentMethod(string newMethod) {
    currentPassenger.paymentMethods.push_back(newMethod);

}

void PassengerGateway::deletePaymentMethod(int number) {
    currentPassenger.paymentMethods.erase(currentPassenger.paymentMethods.begin()+number-1);

}

void PassengerGateway::seePinnedAddresses() {
    for(int i=0; i<currentPassenger.pinnedAddresses.size(); i++){
        cout<<i+1<<") "<<currentPassenger.pinnedAddresses[i]<<endl;
    }

}

void PassengerGateway::addPinnedAddress(string newAddress) {
    currentPassenger.pinnedAddresses.push_back(newAddress);

}

void PassengerGateway::deletePinnedAddress(int number) {
    currentPassenger.pinnedAddresses.erase(currentPassenger.pinnedAddresses.begin()+number-1);

}

void PassengerGateway::checkRide(string from, string to, int carType) {
    double price;
    int desicion;
    if(carType==1) price=(1+rand()%150)*1;
    else if(carType==2) price=(1+rand()%150)*2;
    else if(carType==3) price=(1+rand()%150)*3;
    else price=(1+rand()%150)*4;
    cout<<"Price to order the car from "<<from<<" to "<<to<<" will cost: "<<price<<" rubles"<<endl;
    cout<<"Do you want to make this order?"<<endl<<"1) Yes"<<endl<<"2) No"<<endl;
    cin>>desicion;
    if(desicion==1){

    }
    else {
        cout<<"OK! will waiting for you soon.."<<endl;
    }

}
