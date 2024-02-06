#include <iostream>
#include <memory>

class Car {
public:
    Car(int id) : id(id) {
        std::cout << "Car #" << id << " constructed" << std::endl;
    }

    ~Car() {
        std::cout << "Car #" << id << " destructed" << std::endl;
    }

    void Drive() {
        std::cout << "Car #" << id << " is driving" << std::endl;
    }

private:
    int id;
};



int main() {
//Raw pointers
    //Car* uniqueVW = new Car(666);
    //uniqueVW->Drive();

    //Car* VW = new Car(1);
    //VW->Drive();

    //Car* Arteon = new Car(2);
    //Arteon->Drive();

    //delete uniqueVW;
    //delete VW;
    //delete Arteon;

    std::cout << "Utilizarea unique, smart pointers" << std::endl;
    std::unique_ptr<Car> uniqueVW(new Car(666));
    uniqueVW->Drive();
    // obiect cu durata de viata unica
    // este un smart pointer care detine ownership-ul exclusiv al unui obiect.
    // nu poti crea copie a unique pointer, nu poate fi shared



    std::cout << "Utilizarea shared, smart pointers" << std::endl;
    std::shared_ptr<Car> VW = std::make_shared<Car>(100);
    std::shared_ptr<Car> Arteon = VW;  // partajarea aceluiasi obiect
    VW->Drive();
    Arteon->Drive();
    //std::shared_ptr<Car> Arteon = std::make_shared<Car>(200);
    //Arteon->Drive();
    // permite partajarea aceluiasi obiect intre mai multi pointeri: VW si Arteon
    // Contorizeaza referintele la obiect si sterge obiectul numai atunci când nu exista nicio referinta activa la el.
    // Daca mai multe std::shared_ptr detin acelasi obiect, acesta va fi sters doar atunci când ultimul std::shared_ptr care îl detine este distrus.



    std::cout << "Utilizarea weak, smart pointers" << std::endl;
    std::weak_ptr<Car> weakPtr = VW;                //weak pointer created from a shared pointer using the std::weak_ptr class
    std::shared_ptr<Car> Tiguan = weakPtr.lock();  // Conversie la shared_ptr pentru utilizare temporara // lock returneaza null daca obiectul este deja distrus
    if (weakPtr.expired()) {
        // true daca obiectul monitorizat a fost distrus
        std::cout << "Obiectul a fost deja distrus." << std::endl;
    }
    else {
        Tiguan->Drive();
    }
    // weak_ptr este un smart pointer care nu creste contorul de referinte si nu prelungeste durata de viata a obiectului la care refera.
    // Util pentru a evita ciclurile de referinte în situatiile în care std::shared_ptr este utilizat, iar partajarea ownership-ului poate crea cicluri care împiedica eliberarea memoriei.


    // Nu este nevoie sa sterem manual obiectele, smart pointerii se ocupa de asta automat
    return 0;
}
