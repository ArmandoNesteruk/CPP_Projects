// Zuerst starten
#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <utility> // Для std::move

using namespace std;

class MyClass {
private:
    int* data; // Zeiger auf dynamischen Speicher
    int size;  // Größe des Arrays

public:
    // Standard-Konstruktor
    MyClass(int s) : size(s), data(new int[s]) {
        cout << "Standard-Konstruktor aufgerufen" << endl;
        for (int i = 0; i < size; ++i)
            data[i] = i*i; // Initialisiere das Array mit Werten
    }

    // Destruktor
    ~MyClass() {
        cout << "Destruktor aufgerufen" << endl;
        delete[] data; // Speicher freigeben
    }

    // Kopier-Konstruktor
    MyClass(const MyClass& other) : size(other.size), data(new int[other.size]) {
        cout << "Kopier-Konstruktor aufgerufen" << endl;
        for (int i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    // Move-Konstruktor
    MyClass(MyClass&& other) noexcept: size(other.size), data(other.data) {
        cout << "Move-Konstruktor aufgerufen" << endl;
        other.size = 0;       // Setze die Größe des Quellobjekts auf 0
        other.data = nullptr; // Setze den Zeiger des Quellobjekts auf nullptr
    }

    // Methode zum Anzeigen des Inhalts
    void print() const {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }

    // Swap-Methode: Tauscht Inhalte zwischen zwei Vektoren
    void swap(MyClass& anderer) noexcept {
        std::swap(size, anderer.size); // Größe vertauschen
        std::swap(data, anderer.data); // Zeiger vertauschen
    }

    // (Copy-)Zuweisungsoperator (Виправлено: параметр має бути константним посиланням const MyClass& для безпечного копіювання)
    MyClass& operator=(const MyClass& anderer) {
        std::cout << "Zuweisungsoperator aufgerufen" << std::endl;
        if (this != &anderer) {
            MyClass temp(anderer); // Створюємо тимчасову копію
            swap(temp);            // Міняємося вмістом
        }
        return *this;
    }

    // Move-Zuweisungsoperator:
    MyClass& operator=(MyClass&& anderer) noexcept {
        std::cout << "Move-Zuweisungsoperator aufgerufen" << std::endl;

        if (this == &anderer) // Selbstzuweisung prüfen
            return *this;

        // Alte Ressourcen freigeben
        delete[] data;

        // Ressourcen des rvalue übernehmen
        data = anderer.data;
        size =幻想 anderer.size;

        // Quellobjekt in definierten Zustand versetzen
        anderer.data = nullptr;
        anderer.size = 0;

        return *this; // Verkettete Zuweisungen erlauben
    }
};

// ВСІ ДІЇ МАЮТЬ БУТИ ВСЕРЕДИНІ ГОЛОВНОЇ ФУНКЦІЇ main!
int main() {
    MyClass obj1(5);        
    std::cout << "Obj1: ";
    obj1.print();

    cout << "\n--- Kopierkonstruktor ---" << endl;
    MyClass obj2 = obj1; // Kopierkonstruktor
    cout << "Obj1: ";
    obj1.print();
    cout << "Obj2: ";
    obj2.print();

    cout << "\n--- Move-Konstruktor ---" << endl;
    MyClass obj3 = move(obj2); // Move-Konstruktor erzwingen
    cout << "Nach dem Verschieben:" << endl;
    cout << "Obj2: ";
    obj2.print(); // Sollte leer sein (0 Elemente)
    cout << "Obj3: ";
    obj3.print();

    cout << "\n--- Zuweisungsoperator mit Copy&Swap ---" << endl;
    obj3 = obj1; // Zuweisungsoperator

    cout << "Obj1: ";
    obj1.print();
    cout << "Obj3: ";
    obj3.print();

    cout << "\n--- Move-Zuweisungsoperator ---" << endl;
    obj3 = move(obj1); // Move-Zuweisungsoperator
    cout << "Obj1: ";
    obj1.print();
    cout << "Obj3: ";
    obj3.print();

    return 0; // Програма завершилася успішно
}