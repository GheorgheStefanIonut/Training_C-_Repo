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

int main() {
    // Crearea fabricii de masini sport
    std::unique_ptr<CarFactory> sportsCarFactory = std::make_unique<SportsCarFactory>();

    // Crearea unei masini sport
    std::unique_ptr<Car> sportsCar = sportsCarFactory->CreateCar();

    // Conducerea masinii sport
    DriveCar(std::move(sportsCar));

    // Crearea fabricii de masini familiale
    std::unique_ptr<CarFactory> familyCarFactory = std::make_unique<FamilyCarFactory>();

    // Crearea unei masini familiale
    std::unique_ptr<Car> familyCar = familyCarFactory->CreateCar();

    // Conducerea masinii familiale
    DriveCar(std::move(familyCar));

    return 0;
}