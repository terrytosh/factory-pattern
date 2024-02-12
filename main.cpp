#include <iostream>
#include <string>

class Vehicle {
    public:
        virtual std::string getType() = 0;
};

class Car : public Vehicle {
    public:
        std::string getType() override {
            return "Car";
        }
};

class Bike : public Vehicle {
    public:
        std::string getType() override {
            return "Bike";
        }
};

class Truck : public Vehicle {
    public:
        std::string getType() override {
            return "Truck";
        }
};

class VehicleFactory {
    public:
        virtual Vehicle* createVehicle() = 0;
};

class CarFactory : public VehicleFactory {
    public:
        Vehicle* createVehicle() override{
            return new Car();
        }
};

class BikeFactory : public VehicleFactory {
    public:
        Vehicle* createVehicle() override{
            return new Bike();
        }
};

class TruckFactory : public VehicleFactory {
    public:
        Vehicle* createVehicle() override{
            return new Truck();
        }
};

int main() {
    VehicleFactory* carFactory = new CarFactory();
    VehicleFactory* bikeFactory = new BikeFactory();
    VehicleFactory* truckFactory = new TruckFactory();

    Vehicle* myCar = carFactory->createVehicle();
    Vehicle* myBike = bikeFactory->createVehicle();
    Vehicle* myTruck = truckFactory->createVehicle();

    std::string car = myCar->getType();   // "Car"
    std::string bike = myBike->getType();  // "Bike"
    std::string truck = myTruck->getType(); // "Truck"

    std::cout << car << std::endl;
    std::cout << bike << std::endl;
    std::cout << truck << std::endl;
    
    return 0;
}