// Zuerst starten
#include <iostream>
#include <typeinfo>
#include <iomanip>
#include <string>
#include <memory>

using namespace std;

struct Person {
    string name;
    Person(string n) : name(n) {
        cout << "Person " << name << " erstellt\n";
    }
    ~Person() {
        cout << "Person " << name << " geloescht\n";
    }
    void hallo() {
        cout << "Hallo, ich bin " << name << endl;
    }
};

int main() {
    
    // Erzeugung mit make_unique
    cout << "--- Erzeugung ---" << endl;
    unique_ptr<Person> chef = make_unique<Person>("Anna");

    // Zugriff wie bei normalem Zeiger
    // Kurzschreibweise über den Pfeil-Operator ->
    cout << "\nZugriff wie bei normalem Zeiger:" << endl;
    chef->hallo();

    // Zugriff über Dereferenzierung und Punkt-Operator
    cout << "\nZugriff ueber (*chef):" << endl;
    (*chef).hallo();

    /* ...beide Methoden sind identisch */

    // Prüfen ob Zeiger gesetzt ist
    cout << "\nPruefen ob Zeiger gesetzt ist:" << endl;
    if (chef) {
         cout << "Zeiger ist nicht nullptr\n";
    }

    // Reset auf neues Objekt
    cout << "\nReset auf neues Objekt:" << endl;
    chef.reset(new Person("Bernd"));

    // Release (gibt Besitz auf, löscht aber nicht!)
    cout << "\nRelease:" << endl;
    Person* roherZeiger = chef.release(); // chef тепер стає nullptr, а Bernd переходить під контроль roherZeiger

  
    if (!chef) {
        cout << "Der smart pointer 'chef' ist jetzt leer (nullptr).\n";
    }

    cout << "\nManuelle Freigabe:" << endl;
    delete roherZeiger; // manuelle Freigabe notwendig, weil release() genutzt wurde

    // Automatisches Freigeben bei Zerstörung
    return 0;
}