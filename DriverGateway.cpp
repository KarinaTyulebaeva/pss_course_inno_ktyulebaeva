//
// Created by user on 14.04.2021.
//

#include "DriverGateway.h"

DriverGateway::DriverGateway(Driver driver) {
    this->currentDriver=driver;

}

void DriverGateway::seeOrderHistory() {
    for(int i=0; i<currentDriver.orderHistory.size(); i++){
        cout<<i+1<<") "<<currentDriver.orderHistory[i].getFrom()<<" - "<<currentDriver.orderHistory[i].getTo()<<" : "<<currentDriver.orderHistory[i].getPrice()<<endl;
    }

}
