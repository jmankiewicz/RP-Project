#include <iostream>

using namespace std;

int main()
{
    /* Der C/C++-Standard garantiert bei einer neu definierten Variable NICHT, daß sie auf einem sinnvollen Wert steht!
     * Entsprechend sollte man sich zur Angewohnheit machen Variablen bei der Definition einen gültigen Dummy-Wert zu geben.
     * Warum der Standard dafür keine Sorge trägt? --> Geschwindikeit. Wertzuweisungen brauchen viel viel länger als Definitionen.
     * Alle Spielehersteller oder Entwickler von Hoch-Performanz-Anwendungen würden sonst im Strahl kotzen.
     */
    int bla = 42;
    int blubb = 13;
    int *kind = &bla;
    cout << bla << " - " << kind << " - " << *kind << endl;
    *kind = 24;
    kind = &blubb;
    cout << bla << " - " << kind << " - " << *kind << endl;
    kind = NULL; //Ungültige Adresse. NULL bzw. seit c++13 auch nullptr werden als Dummy-Werte für ungenutzte Pointer verwendet.
    cout << "Bis hier geht alles gut, aber nun dereferenzieren wir mal..." << endl;
    bla = *kind; //Segmentation fault! Das Programm stürzt ab, weil wir an ungültiger Stelle nach einem int suchen.
    return 0;
}

