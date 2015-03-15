/*
 * Willkommen in unserem C/C++ Tutorial!
 * 
 * Hier sehen wir bereits die Schreibweise eines mehrzeiligen Kommentars. 
 * Eröffnet wird er mit einem / und einem *,  geschlossen umgekehrt mit einem * und 
 * einem /. Die Sterne am Anfang jeder neuen Zeile sind nicht notwendig,  haben 
 * sich aber eingebürgert zur Hervorhebung.
 */

// Einzeilige Kommentare hingegen schreibt man mit //.

/* Ein gut kommentierter Quelltext spricht aber nicht nur von gute Stil, sondern 
 * mit den Kommentarzeichen kann man auch schnell einzelne Zeilen oder ganze Blöcke 
 * von Quellcode temporär ausschalten. Weiterhin gibt es Programme die die 
 * Kommentare auswerten und daraus automatisch eine Referenz für das Programm 
 * erstellen. Ein bekanntes solches Dokumentationsprogramm heißt Doxygen und 
 * empfiehlt sich für jedes größere Projekt.
 *
 * Betrachten wir aber nun am Beispiel einer ganz einfachen C/C++ Datei die 
 * Grundlagen der Syntax. 
 * 
 * Zuerst sehen wir,  erkennbar am vorgestellten '#' eine sogenannte 
 * Präprozessor-Anweisung. Es gibt insgesamt drei Programme die unseren 
 * Quelltext  * auf dem weg zum fertigen Programm bearbeiten:
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

/*
 * __Jedes__ C/C++ besitzt eine Funktion "main". Diese Funktion wird vom 
 * Betriebssystem aufgerufen und von da aus übernehmen wir die Kontrolle. Endet 
 * diese Funktion,  so endet auch unser Programm und die Kontrolle geht zurück an
 * das Betriebssystem. Hier fängt also alles an und es endet auch alles.
 * 
 * Schauen wir die Funktionsdefinition an,  so sehen wir folgende Struktur:
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
 */

int main(int argc, char *argv[])
{
  /* Wir deklarieren eine ganzzahlige Variable i. Man bemerke das Semikolon,  welches
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

