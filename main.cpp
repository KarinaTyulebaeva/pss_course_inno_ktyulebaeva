#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "PassengerGateway.h"
#include "DriverGateway.h"

using namespace std;


int main() {
    string line;
    ifstream inP("PassengerDataBase.txt");
    ifstream inD("DriversDataBase.txt");
    PassengerGateway PassengerInterface;
    DriverGateway DriverInterface;
    string name;
    string surname;
    string login;
    string password;
    double rating;
    string firstPaymentMethod;
    string firstPinnedAddress;

    bool workS;
    bool rideS;
    string model;
    string color;
    string number;
    int carType;
    double x, y;

    int decision;
    string loginToLog;
    string passwordToLog;

    while (!inP.eof()) {
        inP >> name >> surname >> login >> password >> rating >> firstPaymentMethod >> firstPinnedAddress;
        line = name + " " + surname;
        PassengerInterface.passengersDatabase.emplace_back(
                Passenger(line, login, password, rating, firstPaymentMethod, firstPinnedAddress));
        //   cout<<PassengerInterface.passengersDatabase.size()<<endl;

    }

    while (!inD.eof()) {
        inD >> name >> surname >> login >> password >> rating >> model >> color >> number >> carType >> x >> y;
        line = name + " " + surname;
        Car temp(model, color, number, carType, x, y);
        DriverInterface.driversDatabase.emplace_back(Driver(line, login, password, rating, temp));
    }

    Login:
    cout << "To Login choose who you are\n1) Passenger\n2) Driver\n-> ";
    cin >> decision;
    int flag = 0;

    if (decision == 1) {
        cout << "\nEnter Login-> ";
        cin >> loginToLog;
        cout << "\nEnter Password-> ";
        cin >> passwordToLog;
        for (int i = 0; i < PassengerInterface.passengersDatabase.size(); i++) {

            if (PassengerInterface.passengersDatabase[i].getLogin().compare(loginToLog) == 0 &&
                PassengerInterface.passengersDatabase[i].getPassword().compare(passwordToLog) == 0) {
                PassengerInterface.currentPassenger = PassengerInterface.passengersDatabase[i];
                flag = 1;
            }
        }
        if (!flag) cout << "\nCheck Login and Password correctness" << endl;
    } else {
        cout << "\nEnter Login-> ";
        cin >> loginToLog;
        cout << "\nEnter Password-> ";
        cin >> passwordToLog;
        for (int i = 0; i < DriverInterface.driversDatabase.size(); i++) {
            if (DriverInterface.driversDatabase[i].getLogin() == loginToLog &&
                DriverInterface.driversDatabase[i].getPassword() == passwordToLog) {
                DriverInterface.currentDriver = DriverInterface.driversDatabase[i];
                flag = 1;
            }
        }
        if (!flag) cout << "\nCheck Login and Password correctness" << endl;
    }

    flag = 1;
    int command;
    Menu:
    if (flag == 1) {
        if (decision == 1) { //Passenger
            cout
                    << "\n\n1) See order history\n2) See payment methods\n3)Update payment methods\n4) See pinned addresses\n5) Update pinned addresses\n6) Order ride\n7) Logout"
                    << endl;
            cout << "\nEnter the number-> ";
            cin >> command;
            int n;
            string from;
            string to;
            int type;
            double price;
            switch (command) {
                case 1:
                    PassengerInterface.seeOrderHistory();
                    goto Menu;
                case 2:
                    PassengerInterface.seePaymentMethods();
                    goto Menu;
                case 3:

                    cout << "\n1) Add new method\n2) Delete method";
                    cin >> n;
                    if (n == 1) {
                        string method;
                        cout << "\nEnter new method-> ";
                        cin >> method;
                        PassengerInterface.addPaymentMethod(method);
                    } else {
                        PassengerInterface.seePaymentMethods();
                        cout << "\nChoose number of method";
                        cin >> n;
                        PassengerInterface.deletePaymentMethod(n);
                    }
                    goto Menu;
                case 4:
                    PassengerInterface.seePinnedAddresses();
                    goto Menu;
                case 5:
                    cout << "\n1) Add new address\n2) Delete address";
                    cin >> n;
                    if (n == 1) {
                        string address;
                        cout << "\nEnter new address-> ";
                        cin >> address;
                        PassengerInterface.addPinnedAddress(address);
                    } else {
                        PassengerInterface.seePinnedAddresses();
                        cout << "\nChoose number of address";
                        cin >> n;
                        PassengerInterface.deletePinnedAddress(n);
                    }
                    goto Menu;
                case 6:
                    cout << "\nEnter your current address->";
                    cin >> from;
                    cout << "\nEnter your destination address-> ";
                    cin >> to;
                    cout << "\n1) Econom\n2) Comfort\n3) ComfortPlus\n4) Business\nEnter car type-> ";
                    cin >> type;
                    price = PassengerInterface.checkRide(from, to, type);
                    cout << "\nYour ride from " << from << " to " << to << " will cost " << price << endl;
                    cout << "\n1) Accept\n2) Decline\n-> ";
                    cin >> n;
                    if (n == 1) {
                        Order newOrder(from, to, price);
                        PassengerInterface.orderRide(newOrder, DriverInterface, type);

                    } else {
                        goto Menu;
                    }
                    goto Menu;
                case 7:
                    flag = 0;
                    goto Login;
            }
        } else {
            cout
                    << "1)\n\n1) See order history\n2) See a car\n3) Update work status\n4) Update ride status\n5) Check available orders\n6) Logout\nEnter command-> ";
            cin >> command;
            switch (command) {
                case 1:
                    DriverInterface.seeOrderHistory(DriverInterface.currentDriver);
                    goto Menu;
                case 2:
                    DriverInterface.seeCar(DriverInterface.currentDriver);
                    goto Menu;
                case 3:
                    DriverInterface.updateWorkStatus(DriverInterface.currentDriver);
                    goto Menu;
                case 4:
                    DriverInterface.updateRideStatus(DriverInterface.currentDriver);
                    goto Menu;
                case 5:
                    DriverInterface.seeAvailableOrders();
                    goto Menu;
                case 6:
                    flag = 0;
                    goto Login;
            };
        }
    } else {
        goto Login;
    }


    inP.close();
    inD.close();
    return 0;
}
