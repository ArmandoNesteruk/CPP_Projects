#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Wie viele Zahlen? ";
    cin >> n;
\
    if (n <= 0) {
        cout << "Bitte geben Sie eine Zahl groesser als 0 ein." << endl;
        return 1; 
    }

    int* arr = new int[n];   // Speicher für n ints reservieren (Dynamisches Array)

    // Befüllen
    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    // Ausgeben
    cout << "Array-Elemente: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
\
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Alle Werte addieren
    }
\
    double durchschnitt = static_cast<double>(sum) / n; 

    cout << "Summe aller Zahlen: " << sum << endl;
    cout << "Durchschnitt: " << durchschnitt << endl;\

    delete[] arr; // Speicher wieder freigeben! (Sehr wichtig, um Memory Leaks zu vermeiden)
    arr = nullptr; // \Zeiger auf nullptr setzen nach dem Löschen

    return 0;
}