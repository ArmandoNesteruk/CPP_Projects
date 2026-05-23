// Zuerst starten
#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

class Vektor {
    private:
        int* data;
        std::size_t size;
    
    public:
        // Konstruktor
        Vektor(std::size_t n) : size(n), data(new int[n]) {
            for (std::size_t i = 0; i < size; ++i) data[i] = i; 
            std::cout << "Konstruktor\n";
        }
    
        // *** Kopierkonstruktor ***
        Vektor(const Vektor& other) : size(other.size), data(new int[other.size]) {
            std::copy(other.data, other.data + size, data);
            std::cout << "Kopierkonstruktor\n";
        }
    
        // *** Hilfsfunktion für copy&swap ***
        void swap(Vektor& other) {
            std::swap(size, other.size);
            std::swap(data, other.data);
            std::cout << "Hilfsfunktion fuer copy&swap\n";
        }
    
        // *** Zuweisungsoperator mit copy&swap ***
        Vektor& operator=(Vektor other) { // Übergabe per Wert = Kopie erzeugt
            std::cout << "Zuweisungsoperator (copy&swap)\n";
            this->swap(other);            // Inhalt sicher austauschen
            return *this;
        } 
    
        // Destruktor
        ~Vektor() {
            delete[] data;
            std::cout << "Destruktor\n";
        }
};


int main() {
    Vektor a(5);     // normaler Konstruktor
    std::cout << "========\n";
    
    Vektor b = a;    // Kopierkonstruktor
    std::cout << "========\n";
    
    Vektor c(5);     
    std::cout << "========\n";
    
    c = a;           // Zuweisungsoperator (copy&swap)
    std::cout << "========\n";

    return 0;
}