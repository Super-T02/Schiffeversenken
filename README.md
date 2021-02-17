# Schiffeversenken
Das bekannte Spiel Schiffeversenken für 2 Spieler auf einem PC.

*Dies ist eine Projektarbeit von Maximilian Nagel und Tom Freudenmann für das Modul Programmieren I.*

## Benutzerdokumentation
Um das Spiel zu starten, muss die SchiffeVersenken.exe Datei (**Pfad: .../cmake-build-debug/Schiffeversenken.exe**) ausgeführt werden und eine beliebige Taste der Tastatur gedrückt werden. Es erscheint ein Spielfeld und am unteren Ende des Bildschirms eine Eingabe für SpielerA, um seine Schiffe zu platzieren, SpielerB muss dementsprechend wegschauen. Um ein Schiff zu platzieren, muss der Spieler das Startfeld und das Endfeld seines gewünschten Schiffes einegben (zB. *A1* 'Enter' *A6*). Das Startfeld muss **links** beziehungsweise **über** dem Endfeld sein. Das Schiff darf **nicht** direkt auf, diagonal oder neben einem anderen Schiff platziert werden und selbstverständlich nicht die Spielfeldränder überschreiten. Die geforderte Länge des einzugebenden Schiffs steht in der Message unter dem Spielfeld. Bereits mit Schiffen besetzte Felder sind mit einem S belegt, alle anderen sind leer. Wenn SpielerA seine Schiffe platziert hat, macht SpielerB dasselbe.
Nach dem Platzieren der Schiffe werden nun zwei Felder nebeneinander angezeigt und die Spieler können abwechselnd auf Felder schießen, auf denen sie ein Schiff vermuten. Die Anzeige ist dabei folgendermaßen:
- nicht beschossene Felder: leeres Feld
- Fail / Wasser / Niete: O
- Schiff / Hit / Treffer: X
- Versenktes Schiff: #

Das Spiel ist gewonnen, wenn alle Schiffe eines Spielers versenkt sind. Es wird der Sieger angezeigt, im Verliererfeld die verbleibenden Schiffe eingefügt und die Frage nach einem erneuten Spiel gestellt.

## Entwicklerdokumentation
Damit das Spiel richtig compiliert wird, wird ein **CMake Compiler** benötigt.
Die Spielfelder der zwei Player sind als Array der Größe 14 abgespeichert und werden in der Main mit dem Status neutral befüllt. Der äußere Ring dient als Puffer.
Es wurden drei Enums initialisiert: 
- Die Status der Array werden als Zahlen von 0 bis 5 deklariert.
- SpielerA ist als 1 und SpielerB als 2 deklariert.
- Die xKoordinate der Arrays wird statt mit Buchstaben von A bis L mit Zahlen von 1 bis 12 deklariert.
```C
enum FELDNUMBER { A = 1, B, C, D, E, F, G, H, I, J, K, L };
enum SCHIFFSTATUS {neutral = 0, ship, fail, hit, destroyed, alreadyTyped};
enum PLAYER {PLAYER_A = 1, PLAYER_B};
```
Das Spiel ist grundsätzlich aufgeteilt in die Spielphasen Start, Spiel und End. Jede Spielphase enthält eine manager-Datei, welche die Logik und die Grafik der jeweiligen Phase aufruft.
### Startphase
In der Startphase können beide Spieler ihre Schiffe platzieren. Dabei werden die Vorraussetzungen geprüft (Start links über Ende, keine direkt benachbarten Schiffe, kein Verlassen des Spielfelds)

#### setShip
Die Methode setShip liefert 0 zurück, falls das Schiff platziert werden kann, 1 falls nicht. In der Methode werden logikStart und scanKoordinate aufgerufen.
```C 
int setShip(int player, int shiplength); 
```
#### scanKoordinate
Die Methode scanKoordinate scannt die Eingabe auf gültige Koordinaten; liefert 1 für false und 0 für true.
```C
int scanKoordinate(int* x, int* y);
```
#### grafikStart
Die Methode grafikStart generiert die Konsolenausgabe einer matrixförmigen Tabelle.
```C
void grafikStart(int player[ARRAYSIZE][ARRAYSIZE], int actualPlayer);
```
#### logikStart
Die Rückgabe der Methode logikStart ist gleichbedeutend mit der von setShip, in logikStart wird das Array mit den Schiffen besetzt, falls gültig. Die Methode boarderCheck wird aufgerufen.
```C
int logikStart(int xStart, int yStart, int xEnd, int yEnd, int player, int shiplength);
```
#### boarderCheck
Die Methode boarderCheck prüft, ob ein Schiff nach den Platzierregeln platziert werden darf. 0 für true, 1 für false.
```C
int boarderCheck(int xStart, int yStart, int xEnd, int yEnd, int x, int y, int vertikal, int player);
```


### Spielphase
In der Spielphase können beide Spieler gegnerische Felder angreifen. Dabei werden die Felder betrachtet und im Falle eines Treffers auf versenkt überprüft.
#### grafikPlay
Die Methode grafikPlay zeigt beide Spielfelder in der Konsole tabellenförmig an.
```C
void grafikPlay(int actualPlayer);
```
#### managerPlay
Die Methode managerPlay ruft die einzelnen Funktionen im Modul Play auf, regelt den IO und überwacht das Ende vom Spiel.
```C
int managerPlay();
```
Nach jedem Zug wird das Ende des Spiels überprüft und der Sieger zurückgegeben.
```C
if (numberOfShips_A == 0)
        {
            return PLAYER_B;
        }
        else if(numberOfShips_B == 0)
        {
            return PLAYER_A;
        }
```
#### replace
Die Methode replace passt ein einzelnes Feld des Arrays an den Eingabeparameter Status an.
```C
int replace(int actualPlayer, int status, int x, int y);
```
#### logikPlay
Die Methode logikPlay verarbeitet die eingegebene Koordinate und überprüft den Status im Array. Dieser wird zurückgegeben. Die Methode checkDestroy wird aufgerufen.
```C
int logikPlay(int actualPlayer, int x, int y);
```
#### checkDestroy
Die Methode überprüft bei einem Hit, ob das Schiff vollständig versenkt ist und ersetzt gegebenenfalls den Status im Array. Rückgabewert 0 für true, 1 für false.
```C
int checkDestroy(int actualPlayer, int x, int y);
```

### Endphase
In der Endphase wird das vollständige Spielfeld aussgegeben inklusive der noch nicht getroffenen Schiffsteile. Dies übernimmt die Funktion grafikPlay. Der Sieger wird in der Message einegfügt und es wird nach einem eneuten Spiel gefragt. Es gibt keine eigene logikEnd, die Logik der Endphase wird von der Main übernommen.
