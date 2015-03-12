#include <iostream>

using namespace std;

int main()
{
    int bla = 42;
    int blubb = 13;
    int *kind = &bla;
    cout << bla << " - " << kind << " - " << *kind << endl;
    *kind = 24;
    kind = &blubb;
    cout << bla << " - " << kind << " - " << *kind << endl;
    kind = NULL; //Ungültige Adresse
    cout << "Bis hier geht alles gut, aber nun dereferenzieren wir mal..." << endl;
    bla = *kind;
    return 0;
}

