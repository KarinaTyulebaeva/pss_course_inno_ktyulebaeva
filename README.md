The main system work with 2 objects (PassengerGateway, DriverGateway) as interfaces for users.
Each object have current user - logined user to the system. And interface work for this current user, using it as a parametr for different methods.

In the begining of the program we create 2 interfaces: PassengerInterface (which will use currentPassenger) and DriverInterface(which will use currentDriver). Then we read data from the input file and load it to the interfaces data bases (vectors).

After it, we create Login process, which will determine current user.

main system:

-Login: Login process.
-Menu: Menu bar with options for user.

PassengerGateway:

-void seeOrderHistory(): show order history for current user.

-void seePaymentMethods(): show payment methods for current user.

-void addPaymentMethod(string newMethod): add new payment method.

-void deletePaymentMethod(int number): delete n-th payment method.

-void seePinnedAddresses(): show pinned addresses for current user.

-void addPinnedAddress(string newAddress): add new pinned addresses.

-void deletePinnedAddress(int number): delete n-th pinned addresses

-double checkRide(string from, string to, int carType): calculate the cost for template order.

-void orderRide(Order order, DriverGateway DriverInterface, int type): order ride if current user agree with the cost of 'checkRide'. Check available driver from drivers data base and order him, otherwise, add this order to the list of available orders.

-void StartRide(Order order, Driver driver, DriverGateway DriverInterface, int type): add order to the order history of current user and ordered driver. Implement additions for different car type.

-void FinishRide(Order order, Driver driver, DriverGateway DriverInterface): finish order.

-void askCurrentCoordinates(): show coordinates of the car during the ride. They are random..

DriverGateway:

-void seeOrderHistory(Driver driver): show order history for current driver.

-void updateWorkStatus(Driver driver): update driver's work status (from 1 to 0 and vice versa).

-void updateRideStatus(Driver driver): update driver's ride status (from 1 to 0 and vice versa).

-void seeCar(Driver driver): show data of the personal car of the current driver.

-void StartOrder( Driver driver ,Order order): update ride status, add order to the history and start.

-void FinishOrder(Driver driver): update ride status and finish order.

-void seeAvailableOrders(): show all available orders and allow to take them.