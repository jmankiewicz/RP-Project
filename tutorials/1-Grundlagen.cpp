/* # Einführung
 *
 * Willkommen in unserem C/C++ Tutorial!
 * Hier sehen wir bereits die Schreibweise eines mehrzeiligen Kommentars.
 * Eröffnet wird er mit einem / und einem *,  geschlossen umgekehrt mit einem * und 
 * einem /. Die Sterne am Anfang jeder neuen Zeile sind nicht notwendig,  haben 
 * sich aber eingebürgert zur Hervorhebung.
 */

// Einzeilige Kommentare hingegen schreibt man mit //.

/* ## Die Macht der Kommentare
 * Ein gut kommentierter Quelltext spricht aber nicht nur von gute Stil, sondern
 * mit den Kommentarzeichen kann man auch schnell einzelne Zeilen oder ganze Blöcke 
 * von Quellcode temporär ausschalten. Weiterhin gibt es Programme die die 
 * Kommentare auswerten und daraus automatisch eine Referenz für das Programm 
 * erstellen. Ein bekanntes solches Dokumentationsprogramm heißt Doxygen und 
 * empfiehlt sich für jedes größere Projekt.
 *
 * ## Wie wird aus einem Quelltext ein Programm
 * Betrachten wir aber nun am Beispiel einer ganz einfachen C/C++ Datei den
 * Weg zu einer ausführbaren Datei. Nachdem wir unseren Code geschrieben
 * haben gibt es drei Programm die in einer festen Reihenfolge den Text
 * verarbeiten:
 * 
 * 1. Präprozessor
 * 2. Kompiler
 * 3. Linker
 * 
 * Der Präprozessor dient dazu den zumeist aus verschiedenen Dateien 
 * bestehenden Quelltext eines großen Programmes zusammenzusetzen. Er bindet 
 * z.B. auch alle extern genutzen Quelltexte ein. Außerdem kann er oft im Text 
 * benutzte Konstanten oder häufige komplizierte Ausrücke für uns einsetzen wenn 
 * wir es ihm beibringen und uns somit Zeit und Nerven sparen.
 * Merke: Anweisungen an den Prärpozessor beginnen meist mit einem "#".
 * 
 * Der Compiler erzeugt aus dem Quelltext Maschienencode der direkt vom 
 * Prozessor verarbeitet werden kann. Anders als z.B. bei Java oder anderen 
 * sogenannten _interpretierten Sprachen_ wird das Programm also nicht bei 
 * jedem Ausführen sondern nur einmalig beim Erzeugen der Programmdatei 
 * übersetzt.
 * 
 * Der Linker setzt schlussendlich die verschiedenen vom Compilier übersetzten 
 * binären Anweisungsdateien zu einer großen Programmdatei zusammen. Dabei holt 
 * er dann noch die binären Übersetzungen von eingebundenen Bibliotheken dazu.
 * 
 * ## Etwas Präprozessor-Syntax
 *
 * Bevor wir direkt mit dem Programmieren anfangen, wollen wir ein paar sehr nützliche
 * und notwendige PP-Anweisungen ansehen.  Wie erwähnt beginnen die nativen 
 * Präprozessor-Anweisungen mit einem "#". Es ist aber auch möglich Makros und 
 * Konstanten zu definieren, welche Quelltext generieren und nicht mit # beginnen.  
 *
 * ### Makro-Definition
 *
 * Hier definieren wir ein Makro, welches uns den kleineren von zwei Werten zurück
 * gibt. Später im Quelltext könnten wir dann einfach min(zahl1, zahl2)
 * schreiben und bekämen das Minimum zurück.
 * Der Syntax für Makros ist nicht immer trivial, da der PP ganz anders
 * agieren muß als der Compiler.Es lohnt sich die gute Dokumentation der
 * Präprozessor-Syntax früh zu Rate zu ziehen. Das erspart Frustration,
 * glaubt es mir.
 */

#define min(X, Y)  ((X) < (Y) ? (X) : (Y))

/* ### Konstanten-Definition
 *
 * Hier definieren wir eine Konstante zur späteren Verwendung. Wenn wir
 * nun im Quelltext konstante1 schreiben würde der Wert 123.456 an der
 * Stelle eingefügt werden.
 */

#define konstante1 123.456

/* 
 * ### Includes
 *
 * Mit der folgenden Anweisung wird der Präprozessor beauftragt die 
 * Quelltextdatei "iostream" zu suchen und an dieser Stelle einzubinden. Diese 
 * Datei enthält die wichtigsten Funktionen zur Ein- und Ausgabe für C++. Für C 
 * heißt die zu suchende Datei "stdio". Die spitzen Klammern bedeuten dabei 
 * nicht nur im aktuellen Pfad sondern auch in den systemweit bekannten 
 * Bibliotheksverzeichnissen zu suchen. Anführungszeichen würden eine Suche in 
 * unserem lokalen Verzeichnis führen. 
 * 
 */

#include <iostream>
//# include <iostream> //Auch gültig,  da überschüssige Leerzeichen ignoriert werden.
 
 /*### Wetere Präprozessor-Anweisungen
 *
 * Der PP versteht noch einige weitere, praktische Anweisungen,
 * z.B. Conditionals wie if, else usw. Diese werden wir später kennen-
 * lernen. Jetzt wollen wir aber mal anfagen.
 */

/* ## Funktionen in C/C++ 
 *
 * __Jedes__ C/C++ besitzt eine Funktion "main". Diese Funktion wird vom 
 * Betriebssystem aufgerufen und von da aus übernehmen wir die Kontrolle. Endet 
 * diese Funktion,  so endet auch unser Programm und die Kontrolle geht zurück an
 * das Betriebssystem. Hier fängt also alles an und es endet auch alles.
 * Enstprechend ist es grundlegend für uns, Funktionen deklarieren und
 * definieren zu können.
 * 
 * Schauen wir die Funktionsdeklaration an,  so sehen wir folgende Struktur:
 * 
 *   <Rückgabetyp> <Name>( <Parameter )
 *     `int        main ( int argc, char *argv[] )`
 * 
 * Der Rückgabetyp sagt dem Compiler welche Art von Wert die Funktion 
 * zurückliefern wird. Der Name dient zum Aufruf der Funktion und die Parameter 
 * sind Werte die der Funktion beim Aufruf übergeben werden müssen damit sie ihre  
 * Arbeit tun kann. Im Fall von "main" bekommen wir vom Betriebssystem 
 * einmal eine Ganzzahl (int) die uns die Anzahl der beim Funktionsaufruf 
 * angegebenen Argumente angibt und ein Array argv aus dem wir diese Argumente 
 * abrufen können. Damit wollen wir uns aber an anderer Stelle befassen. "main" 
 * __muss__ immer eine Ganzzahl zurückgeben wobei eine 0 für einen erfolgreichen 
 * Abschluß des Programms und eine andere Ganzzahl für einen Fehlercode steht. 
 * Diese Fehlercodes können wir uns selbst ausdenken und z.B. in unserem 
 * Handbuch dem Nutzer mitteilen.
 * 
 *  Es reicht nun aber nicht die Funktion nur zu derklarieren, wir müssen auch definieren
 *  was sie tut. Das geschieht in einem sogenannten Block direkt hinter der Deklaration.
 * 
 *  ## Blocks
 * 
 *  Ein Block ist nich mehr und nicht weniger als ein von geschweiften Klammern eingefasster Quelltextbereich. 
 *  Funktionsdefinitionen werden von einem Block gefolgt, genauso auch z.B. Conditionals wie if und else.
 * 
 *  Wichtig: Was innerhalb eines Blocks deklariert wird, gilt auch nur dort! Mehr dazu an späterer Stelle, wenn
 * wir uns dem Thema der "scopes" also der Gültigkeitsbereiche zuwenden.
 */ 
 
 /* 
 *  # Ein einfaches C/C++ Programm
 * 
 *  Ab hier behandeln wir den Aufbau eines einfachen Quelltexts für ein Programm. 
 * Zu beginn müssen wir die grundlegende Bibliothek einbinden (Hallo Präprozessor!) 
 * und anschließen eine Funktion main mit Rückgabetyp int definieren. Aich ihre Parameter sind vor-
 * geschrieben. C und C++ unterscheiden sich in diesem kleinen Beispiel nur im Vorspann.
 */
 
 // Für C:
 
#include <stdio.h>
 
 //Für C++:
 
#include <iostream>
 
 using namespace std;

//Für beide anschließend:


int main(int argc, char *argv[]) //Deklaration von main und nachfolgend der Block welcher die Anweisungen enthält
{
  /* ## Variablen
   * 
   * Analog zur Deklaration einer Funktion sieht eine Variablen-Deklaration so aus:
   * 
   *  <Wertetyp> <Name>
   *      int                test
   * 
   * Wir deklarieren eine ganzzahlige Variable i. Man bemerke das Semikolon,  welches
   * jede Zeile mit einer Anweisung terminiert. 
   */
  int i;
  /* Mit dem Zuweisungsoperator = weisen wir i den Wert 15 zu */
  i = 15;
  /* Bei j kombinieren wir beide Schritte. Auch das ist zulässig und spart Zeit. */
  int j = 25;
  
  /*
   * C/C++ garantiert __nicht__ für den Wert einer frisch deklarierten Variable! Diese kann
   * prinzipiell jeden Wert annehmen - jenachdem welcher Datenmüll an der soeben von uns 
   * in Beschlag genommenen Stelle im Hauptspeicher noch herumfliegt. Daher sollte man besser
   * Variablen gleich einen sicheren Anfangswert zuweisen um nicht durch eine vergessene 
   * Zuweisung später durch zufällige Werte eine Überraschung zu erleben!
   * 
   * Hier nun mal eine etwas verschrobene Anweisung:
   */
  
  int
  k = 
    i +
    j
  ;

  /*
   * ...ist dasselbe wie `int k = i + j;` da C/C++ überschüssige Leerzeichen und Leerzeilen 
   * ignoriert. Mit dem "return"-Ausdruck geben wir schließlich den Wert vom Typ int zurück. 
   * return ist eine Sprunganweisung und sorgt für den sofortigen Rücksprung aus der Funktion zu
   * ihrem Aufruf. Bei einer Funktion ohne Rückgabe lautet der Rückgabetyp "void" und der Return-
   * Anweisung darf kein Wert übergeben werden. Ende eine Funktion übrigens ohne return und 
   * es wird mit dem Rückgabewert gearbeitet,  führt die zu undefinierten Verhalten - in der 
   * Sprache des C/C++-Standards der Euphemismus für einen wahrscheinlichen Absturz oder fiesen
   * Bug. So wie das zuweisen bei der Variable,  so sollten wir uns also auch das Rückgeben eines 
   * Wertes (sofern es einen Rückgabewert gibt) angewöhnen.
   */
  
  return k; 
}

/* # Fazit
 * Soweit so unspannend. Wir wissen nun ein wenig über die Grundlagen von C++ und haben
 * einen kurzen Blick auf die Struktur des Quelltexts geworfen. Die nachfolgendne Beispiele werden
 * deutlich Quelltext-zentrierter sein. Da werden uns diese wenigen aber wichtigen Vorkenntnisse 
 * beim Einstieg helfen.
