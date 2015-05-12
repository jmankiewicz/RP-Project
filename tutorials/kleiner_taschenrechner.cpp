#include <iostream> //Wir schreiben C++, also soll der PP die iostream einfügen

using namespace std; //Nutze den Standard-Namensraum. Dazu später mehr.


/*
 * Hier ein kleiner einfacher Taschenrechner, der zwei Zahlen multipliziert oder addiert.
 * Hierbei führen wir Klassen, die switch- und die goto-Anweisung ein.
 * Außerdem wie man auf die Funktionen innerhalb einer Klasse zugreift.
 * Beginnen wir mit der Klasse:
*/
class calculator {
public:

    float multiply(float zahl1, float zahl2) //Klassen-Funktion multiply
    {
        return zahl1*zahl2;
    }

    float add (float zahl1, float zahl2) //Klassen-Funktion add
    {
        return zahl1+zahl2;
    }
};
/*
 * Die Klasse wird mit class Leerzeichen "Klassenname", gefolgt von einem Block erzeugt und mit einem ";" abgeschlossen.
 * unsere Klasse calculator hat zwei Funktionen: multiply() und add(), die jeweils zwei floats übernehmen und dann
 * multiplizieren bzw addieren und das Ergebnis zurückgeben.
*/

int main()
{
    float num1 = 1;
    float num2 = 1;
    jump:       //So sieht ein Sprungmarker für die goto-Anweisung aus "name:"

    cout << "Do you want no add two numbers [1] or to multiply two numbers [2] ?" << endl;

    int select = 0;
    
    /*
     *Unsere oben definierte Klasse ist ein neuer Datentyp. Nun müssen wir davon ein Exemplar erzeugen. Das funktioniert wie bei allen Variablen:
     */
    
    calculator calc;

    cin >> select;

    switch (select)     // Dies ist die switch-Anweisung. Der übergebene int-Wert lässt das Programm zum
                        // entsprechenden case springen. Im Prinzip genau das Selbe wie in der goto-Anweisung.
    {
        default: cout << "Choose an operation!";        // Der default-operator kommt im switch immer dann zum tragen,
                                                        // wenn kein passender case zur verfügung steht.

                goto jump;  // Dies ist die goto-Anweisung.
                            //Das Programm "springt" einfach zum genannten Sprungmarker (hier "jump").

        case 1: cout << "Type in two numbers!";
                cin >> num1 >> num2;
                cout << "The result is " << calc.add (num1, num2) << " !";
        break;      // der break- Opperator lässt das Programm wieder einen Block höher springen. (man verlässt die {} ).

        case 2: cout << "Type in two numbers!";
                cin >> num1 >> num2;
                cout << "The result is " << calc.multiply (num1, num2) << " !";
        break;
    }

    // Nice to know: Einzig der String-Opperator, die class-Anweisung und die std namespace-Anweisungen sind
    // C++-Anwendungen, der Restliche code ist C!
    return 0;
}

