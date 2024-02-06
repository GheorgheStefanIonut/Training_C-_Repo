#include <iostream>
#include <memory>
#include <mutex>

class SafeSingleton {
private:
    // constructorul este privat pentru a împiedica crearea de instante din afara clasei.
    SafeSingleton() {}

    // pointer static catre instanta unica a Singleton-ului.
    static SafeSingleton* instance;

    // mutex: Un obiect std::mutex utilizat pentru a asigura accesul sigur în threads.
    static std::mutex mutex;

public:
    //metoda pt acesare Singleton instance
    //lock_guard este folosit pentru a asigura blocarea și eliberarea automata a mutex - ului.
        //Se verifica daca instanta exista deja si, daca nu, se creeaza.
        //Se returneaza instanta.
    static SafeSingleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex);

        if (!instance) {
            instance = new SafeSingleton();
        }

        return instance;
    }

    void performOperation() {
        std::cout << "Safe Singleton performing operation." << std::endl;
    }
};

// Safe Singleton asigura safety threads folosind un obiect std::mutex pentru a evita conflictele de acces la resurse între mai multe threaduri.


// Initialize static members.
SafeSingleton* SafeSingleton::instance = nullptr;
std::mutex SafeSingleton::mutex;

int main() 
{
    // Usage of Safe Singleton.
    SafeSingleton* singleton1 = SafeSingleton::getInstance();
    singleton1->performOperation();

    SafeSingleton* singleton2 = SafeSingleton::getInstance();
    singleton2->performOperation();

    // Both instances should point to the same object.
    if (singleton1 == singleton2) {
        std::cout << "Both instances point to the same object." << std::endl;
    }

    return 0;
}