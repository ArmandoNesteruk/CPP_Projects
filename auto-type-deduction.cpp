// Zuerst starten
#include <iostream>
#include <string>
#include <typeinfo> // ОБОВ'ЯЗКОВО: додано для роботи typeid

using namespace std;

// Hier beliebige Werte für x, c und d eingeben (empfohlen ist int, char und double)
auto x = 0;
auto c = 'a';
auto d = 0.5;

// Ausgabecode muss in der main-Funktion stehen!
int main() {
    // i = int     c = char     d = double     l = long
       
    cout << "auto x = " << x << " -> Typ: " << typeid(x).name() << endl;
    cout << "auto c = " << c << " -> Typ: " << typeid(c).name() << endl;
    cout << "auto d = " << d << " -> Typ: " << typeid(d).name() << endl;

    return 0;
}