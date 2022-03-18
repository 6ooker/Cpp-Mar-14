#include <iostream>

using namespace std;


                                                    // Ich schreibe hier meinen Code in eine eigene Funktion, die ich "ziehung" nenne
                                                    // Das ist nur meine Vorgehensweise, man könnte den Code auch leicht ändern und direkt in die main() schreiben
void ziehung(int anzahl) {                          // Funktion vom Typ void, da sie nichts Zurückgeben soll, und den Output selber vornimmt
                                                    // Sie nimmt ein Argument vom Typ int, das ich "anzahl" nenne, da der User angeben können soll, wieviele Lottozahlen
                                                    // gezogen werden sollen -> Wichtig: mehr als die Größe des Arrays geht nicht!

    int max_range = 50;                             // Die obere Grenze für den Pool der möglichen Lottozahlen
    int i = 0;                                      // Initialisiere "i" mit 0, um Datenmüll zu vermeiden -> wird als Index benutzt
    int lottozahlen[6];                             // Initialisiere das Array der LZ, mit einer Größe von 6 -> beachten: Index geht von 0 - 5
    bool flag = false;                              // Initalisiere ein "Hilfs-flag", zum späteren Gebrauch -> false = nicht vorhanden, true = vorhanden

    srand(time(NULL));                              // Seed für die später generierten Zufallszahlen


                                                    // DO-WHILE-SCHLEIFE um sicherzustellen das der Code erst mindestens einmal ausgeführt wird,
                                                    // bevor die Schleife überprüft wird
    do {                                            // Ich benutze hier keine FOR-SCHLEIFE, um den Index manuell und nur unter Bedingungen zu erhöhen
                                                    // -> Siehe weiter unten!

        flag = false;                               // Sicherstellen, dass das Flag pro Durchgang sicher auf false steht

        int randnum = rand() % max_range + 1;       // Eine Zufallszahl generieren, mit der Variable "max_range" als obere Grenze und "1" als Untere

        if (i > 0) {                                // Folgender Code wird NUR AUSGEFÜHRT, wenn der Index größer 0 ist, also erst ab dem zweiten Element:
                                                    // Diese Schleife geht den Index der Elemente im Array rückwärts durch (-> "k--"), beginnend ein
            for (int k = i-1; k >= 0; k--) {        // Element VOR dem derzeitigen Index (-> "k = i-1"), und bricht ab sobald k = 0 erreicht (-> " k >= 0")
                if (lottozahlen[k] == randnum) {    // Sollte an der überprüften Stelle k die gebildete Zufallszahl bereits vorhanden sein wird das flag
                    flag = true;                    // auf "true" gesetzt um zu signalisieren, dass die Zahl gedoppelt ist
                }                                   // Diese Schleife dient somit NUR DER ÜBERPRÜFUNG AUF DOPPELTE ZAHLEN
            }
                                                    // Folgender Code soll NUR ausgeführt werden, wenn das flag NICHT NICHT "false" ist ("!flag") -> Genauere Erklärung weiter unten!
            if (!flag) {                            // Das bedeutet nämlich, dass die Zahl noch NICHT vorgekommen ist
                lottozahlen[i] = randnum;           // Dementsprechend schreiben wir hier die Zufallszahl an die Stelle "i", also den derzeitigen Index
                i++;                                // Da erfolgreich eine Zahl in das Array eingetragen wurde müssen wir nun den Index um eins erhöhen
            }                                       // Sollte das flag auf "true" stehen, wird dieser ganze Code nie ausgeführt, sprich die Zufallszahl
        }                                           // wird NICHT in das Array geschrieben, und der Index wird auch NICHT erhöht
                                                    // Der ganze Vorgang beginnt also von Vorn, inklusive einer neuen Zufallszahl

        else {                                      // Aktion wird ausgeführt wenn der Index NICHT GRÖßER 0 ist, sprich beispielsweise exakt 0
            lottozahlen[i] = randnum;               // Somit wird für die Erste LZ (also am Index i = 0) die generierte Zufallszahl eingesetzt
            i = 1;                                  // Da vor dem 0ten Element keine Zahl doppelt vorhanden sein kann braucht man keine Prüfung
        }                                           // i wird dann noch auf "1" gesetzt, damit der obere Codeblock ausgeführt wird

    } while (i < anzahl);                           // Hier ist noch die Abbruchkondition für die ganze DO-WHILE-SCHLEIFE:
                                                    // Sobald "i" nichtmehr KLEINER als die vom User angegebene "anzahl" ist
                                                    // WICHTIG: Kleiner, NICHT Kleiner-oder-Gleich!! -> einfacher Grund ist, dass das Array ja
                                                    // sechs Elemente fasst, aber den Index eben nicht bis "6", sondern nur bis "5" zählt (-> Da die 0 mitgezählt wird)

// ------------------------ Hier ist der Code, der das Array tatsächlich füllt vorbei ---------------------------------------------------------------------------


// ------------------------ Der unten stehende Code gibt die Zahlen im Array nur aus ----------------------------------------------------------------------------

    for (int h = 0; h < anzahl; h++) {              // Diese Schleife geht einfach in einser-schritten die Elemente des Arrays durch
        cout << lottozahlen[h] << "  ";             // und gibt sie durch Leerzeichen getrennt aus
    }                                               // "h" ist einfach nur die Variable die hier den Index übernimmt, sie beginnt bei 0 und zählt hoch
}                                                   // bis sie KLEINER als die genannte "anzahl" ist -> über cout geben wir dann pro Index einfach "die Zahl
                                                    // an der Stelle 'h' im Array" (lottozahlen[h]) aus


// --------------------------------------------------------------------------------------------------------------------------------------------------------------

/* 
 *                  KLEINE ERLÄUTERUNG ZU IF-ANWEISUNGEN UND MEINEM CODE
 * 
 * 
 *      Eine IF-Anweisung erwartet immer einen boolschen Wert: true/false, 1/0, an/aus, schwarz/weiß.
 * 
 *      Dieser kann auch als eine logische Aussage da stehen, deshalb kann man auch etwas wie
 *          if (1 + 1 = 2)      oder        if (Tag nach Freitag = Samstag)
 *      schreiben. Da diese Aussagen nach der Evaluation "true" sind würde der Codeblock der IF-Anweisung
 *      ausgeführt werden.
 * 
 *      Etwas wie
 *          if (2 + 4 = 200)
 *      würde nicht den Codeblock ausführen, da die Aussage nicht "true" ist.
 * 
 *      Der Code innerhalb des Körpers der IF-Anweisung wird NUR DANN ausgeführt, wenn der boolsche
 *      Wert "true" ist. Mit ELSE-IF kann man noch mehr Möglichkeiten überprüfen und mit ELSE, welches
 *      ja keine Argumente erwartet, eine Option festlegen, die ausgeführt wird falls, und nur falls,
 *      die IF-Anweisung ein "false" bekommt und nichts ausführt, aber das nur am Rande.
 * 
 *      Logische Aussagen können mit logischen Operatoren verknüpft werden, wie AND, OR, XOR, etc.
 *      Diese sind auch in IF-Anweisungen nutzbar, z.B. if (a && b) für eine AND-, oder if (a || b) für
 *      eine OR-Verknüpfung. Das würde aber für jetzt zu tief in die Mathematik führen, also gehe ich
 *      nicht weiter darauf ein.
 *      Auch Gleichheit kann überprüft werden, wie wir es schon oft gemacht haben,
 *      z.B. if (2 + 2 == 2 * 2). Der Operator ist hier das doppelte Gleichheitszeichen "==".
 * 
 *      Was hier nun WIRKLICH wichtig ist, ist die NEGATION. Die Negation dreht die Wahrheit einer
 *      Aussage einfach um: Also währe 2 + 2 = 4, wenn wir es NEGIEREN "false", da die Aussage
 *      eigentlich "true" ist, und wir das einfach umkehren.
 *      Der logische Operator für die Negation ist das Rufzeichen "!", vor eine Aussage gestellt wird
 *      diese negiert.
 *      So wäre dann etwas wie
 *          A -> 2 + 4 = 200
 *          if (!A)
 *      tatsächlich "true" und würde den Code ausführen, da die Aussage A zwar falsch ist, wir sie aber
 *      negieren und so zu richtig ändern.
 * 
 * 
 *      Hier nun die Erklärung zu meinem Code:
 *      Das flag steht quasi für "die Zahl ist schon vorhanden und somit doppelt" und wird deshalb am
 *      Anfang immer auf "false" gesetzt weil wir ja davon ausgehen, dass die Zahl nicht doppelt ist.
 *      Dann wird in der for-Schleife geprüft OB die Zahl schon vorhanden ist. WENN dem so ist, wird
 *      das flag auf "true" gesetzt und signalisiert "Achtung, die Zahl ist doppelt!".
 * 
 *      Der Code     if (!flag)     bedeutet also: nimm den Wert von "flag", und negier ihn.
 *      Nur wenn das ERGEBNIS dieser Negation "true" lautet wird der Codeblock ausgeführt.
 *      Sprich, wenn die Zahl schon vorhanden ist ist flag = "true", wird negiert und ist somit "false"
 *      und die IF-Anweisung wird NICHT ausgeführt, da sie dieses "false" erhält.
 *      Man könnte diesen ganzen scheiß auch 20x verständlicher darstellen mit
 *      if (flag == false)  da dann viel ersichtlicher ist, dass der Code nur dann ausgeführt wird,
 *      wenn das flag auf "false" gesetzt ist.
 *      Die von Bartelt in der Schule und mir hier genutzte Schreibweise ist allerdings deutlich kürzer
 *      und wenn mans verstanden hat auch leichter. Außerdem good-to-know.
 * 
 *      So, vielen Dank für eure Aufmerksamkeit, ich hoffe es war halbwegs verständlich und mehr als
 *      eine Person liest das hier. Schickt mir gerne 200€ an paypal.me/erikkatzenberger
 * 
 */



int main() {

    ziehung(6);                                     // Hier rufen wir einfach unsere Funktion "ziehung" auf und übergeben ihr noch unsere gewünschte Anzahl: 6
                                                    // Wichtig ist hier, dass wir zwar unter 6, aber nicht drüber dürfen, da unser Array ja nur 6 Elemente groß ist!

    return 0;
}