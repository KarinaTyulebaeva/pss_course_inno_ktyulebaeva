//
// Created by user on 14.04.2021.
//

#include "PassengerGateway.h"
#include "DriverGateway.h"


void PassengerGateway::seeOrderHistory() {
    if (currentPassenger.orderHistory.size() == 0) cout << "You do not have any orders yet\n";
    else {
        for (int i = 0; i < currentPassenger.orderHistory.size(); i++) {
            cout << i + 1 << ") " << currentPassenger.orderHistory[i].getFrom() << " - "
                 << currentPassenger.orderHistory[i].getTo() << " : " << currentPassenger.orderHistory[i].getPrice()
                 << endl;
        }
    }
}

void PassengerGateway::seePaymentMethods() {

    for (int i = 0; i < currentPassenger.paymentMethods.size(); i++) {
        cout << i + 1 << ") " << currentPassenger.paymentMethods[i] << endl;
    }


}

void PassengerGateway::addPaymentMethod(string newMethod) {
    currentPassenger.paymentMethods.push_back(newMethod);

}

void PassengerGateway::deletePaymentMethod(int number) {
    currentPassenger.paymentMethods.erase(currentPassenger.paymentMethods.begin() + number - 1);

}

void PassengerGateway::seePinnedAddresses() {
    for (int i = 0; i < currentPassenger.pinnedAddresses.size(); i++) {
        cout << i + 1 << ") " << currentPassenger.pinnedAddresses[i] << endl;
    }

}

void PassengerGateway::addPinnedAddress(string newAddress) {
    currentPassenger.pinnedAddresses.push_back(newAddress);

}

void PassengerGateway::deletePinnedAddress(int number) {
    currentPassenger.pinnedAddresses.erase(currentPassenger.pinnedAddresses.begin() + number - 1);

}

double PassengerGateway::checkRide(string from, string to, int carType) {
    double price;
    int decision;
    if (carType == 1) price = (1 + rand() % 150) * 1;
    else if (carType == 2) price = (1 + rand() % 150) * 2;
    else if (carType == 3) price = (1 + rand() % 150) * 3;
    else price = (1 + rand() % 150) * 4;
    return price;
}

void PassengerGateway::orderRide(Order order, DriverGateway DriverInterface, int type) {
    int nashli = 0;
    for (int i = 0; i < DriverInterface.driversDatabase.size(); i++) {
        if (DriverInterface.driversDatabase[i].getWorkStatus() == 1 &&
            DriverInterface.driversDatabase[i].getRideStatus() == 1 &&
            DriverInterface.driversDatabase[i].ownCar.typeOfCar == type) {
            StartRide(order, DriverInterface.driversDatabase[i], DriverInterface, type);
            nashli = 1;
        }

    }
    if (nashli == 0) {
        DriverInterface.listOfAvailableOrders.emplace_back(order);
        cout << DriverInterface.listOfAvailableOrders.size() << endl;
        cout << "Sorry, there are no free drivers..try again later\n";
    }

}

void PassengerGateway::StartRide(Order order, Driver driver, DriverGateway DriverInterface, int type) {
    int n;
    DriverInterface.StartOrder(driver, order);
    currentPassenger.orderHistory.push_back(order);
    cout << "Fasten seat belts!\n;";
    if (driver.ownCar.typeOfCar == type || driver.ownCar.typeOfCar == type || driver.ownCar.typeOfCar == type) {
        cout << "By the way, you have bottle of water, drink it!" << endl;

    }
    duringRide:
    cout << "Available options:\n1) Get current coordinates\n";
    if (driver.ownCar.typeOfCar == 4) cout << "2) Park right in front of the entrance\n";
    cout << "3) Exit\n-> ";
    cin >> n;
    switch (n) {
        case 1:
            askCurrentCoordinates();
            goto duringRide;
        case 2:
            cout << "Will be done, Sir..\n";
            goto duringRide;
        case 3:
            FinishRide(order, driver, DriverInterface);
            break;
    }


}

void PassengerGateway::FinishRide(Order order, Driver driver, DriverGateway DriverInterface) {
    DriverInterface.updateRideStatus(driver);
    //
    cout << "Your Ride costs " << order.getPrice() << " rubles.\nChoose Payment Method: " << endl;
    cout << "1) Use My Payment Methods" << endl << "2) Use cash" << endl;
    int n = 0;
    cin >> n;
    if (n == 1) {
        seePaymentMethods();
        cin >> n;
        cout << "OK!";
    } else {
        cout << "OK! Please, give " << order.getPrice() << " without sdacha";
    }
    DriverInterface.FinishOrder(driver);
}

void PassengerGateway::askCurrentCoordinates() {
    int x;
    int y;
    x = 0 + rand() % 100;
    y = 0 + rand() % 150;
    cout << "We took a detour due to blocked roads. The current coordinates: ( " << x << " , " << y << " )" << endl;


}





