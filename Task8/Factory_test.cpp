#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>
#include "Factory.cpp"

BOOST_AUTO_TEST_CASE(test_sports_car_creation)
{
    // Creare fabrica SportsCar
    std::unique_ptr<CarFactory> sportsCarFactory = std::make_unique<SportsCarFactory>();

    // Creare SportsCar
    std::unique_ptr<Car> sportsCar = sportsCarFactory->CreateCar();

    BOOST_CHECK(sportsCar != nullptr); // Verificam ca masina a fost creata cu succes
    BOOST_CHECK(dynamic_cast<SportsCar*>(sportsCar.get()) != nullptr); // Verificam ca masina este de tipul corect
}

BOOST_AUTO_TEST_CASE(test_family_car_creation)
{
    // Creare fabrica FamilyCar
    std::unique_ptr<CarFactory> familyCarFactory = std::make_unique<FamilyCarFactory>();

    // Creare FamilyCar
    std::unique_ptr<Car> familyCar = familyCarFactory->CreateCar();

    BOOST_CHECK(familyCar != nullptr); // Verificam ca masina a fost creata cu succes
    BOOST_CHECK(dynamic_cast<FamilyCar*>(familyCar.get()) != nullptr); // Verificam ca masina este de tipul corect
}

BOOST_AUTO_TEST_CASE(test_drive_car)
{
    // Creare fabrica SportsCar
    std::unique_ptr<CarFactory> sportsCarFactory = std::make_unique<SportsCarFactory>();

    // Creare SportsCar
    std::unique_ptr<Car> sportsCar = sportsCarFactory->CreateCar();

    // Verificare conducere SportsCar
    BOOST_CHECK_NO_THROW(DriveCar(std::move(sportsCar))); // Nu ar trebui sa arunce exceptie
}


//g++ Factory_test.cpp -o Factory_test -lboost_unit_test_framework       //comanda executare teste in terminal