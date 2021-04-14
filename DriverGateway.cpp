//
// Created by user on 14.04.2021.
//

#include "DriverGateway.h"


void DriverGateway::seeOrderHistory(Driver driver) {
    if (driver.orderHistory.size() == 0) cout << "You do not have any orders yet\n";
    else {
        for (int i = 0; i < driver.orderHistory.size(); i++) {
            cout << i + 1 << ") " << driver.orderHistory[i].getFrom() << " - " << driver.orderHistory[i].getTo()
                 << " : " << driver.orderHistory[i].getPrice() << endl;
        }
    }
}

void DriverGateway::updateWorkStatus(Driver driver) {
    if (driver.WorkStatus == 0) driver.WorkStatus = 1;
    else driver.WorkStatus = 0;

}

void DriverGateway::updateRideStatus(Driver driver) {
    if (driver.RideStatus == 0) driver.RideStatus = 1;
    else driver.RideStatus = 0;

}

void DriverGateway::seeCar(Driver driver) {
    cout << "Model: " << driver.ownCar.getModel() << "  Color: " << driver.ownCar.getColor() << "  Number: "
         << driver.ownCar.getNumber() << endl;
    cout << "Current coodinate: " << driver.ownCar.getX() << " , " << driver.ownCar.getY() << endl;
}

void DriverGateway::StartOrder(Driver driver, Order order) {
    driver.orderHistory.push_back(order);
    updateRideStatus(driver);


}

void DriverGateway::FinishOrder(Driver driver) {
    updateRideStatus(driver);
}

void DriverGateway::seeAvailableOrders() {
    if (listOfAvailableOrders.size() == 0) cout << "\nThere are no available orders\n";
    else {
        for (int i = 0; i < listOfAvailableOrders.size(); i++) {
            cout << i + 1 << ") " << listOfAvailableOrders[i].getFrom() << " -> " << listOfAvailableOrders[i].getTo()
                 << " - " << listOfAvailableOrders[i].getPrice() << endl;
        }
    }
    cout << "\n1) Accept one of them\n2) Decline all\n";
    int n;
    cin >> n;
    if (n == 1) {
        cin >> n;
        StartOrder(currentDriver, listOfAvailableOrders[n]);
        listOfAvailableOrders.erase(listOfAvailableOrders.begin() + n - 1);
    }
}