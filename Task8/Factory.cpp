#include <iostream>
#include <memory>

// Interfata pentru masini
class Car {
public:
    virtual void Drive() = 0;
    virtual ~Car() = default;
};


class SportsCar : public Car {
public:
    void Drive() override {
        std::cout << "Driving a sports car" << std::endl;
    }
};

class FamilyCar : public Car {
public:
    void Drive() override {
        std::cout << "Driving a family car" << std::endl;
    }
};

// Fabrica abstracta pentru masini
class CarFactory {
public:
    virtual std::unique_ptr<Car> CreateCar() = 0;
    virtual ~CarFactory() = default;
};

class SportsCarFactory : public CarFactory {
public:
    std::unique_ptr<Car> CreateCar() override {
        return std::make_unique<SportsCar>();
    }
};

class FamilyCarFactory : public CarFactory {
public:
    std::unique_ptr<Car> CreateCar() override {
        return std::make_unique<FamilyCar>();
    }
};

// Funcția pentru a conduce o masina
void DriveCar(std::unique_ptr<Car> car) {
    car->Drive();
}
