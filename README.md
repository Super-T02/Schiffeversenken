# Schiffeversenken
Das Spiel Schiffeversenken

## Benutzerdokumentation
Um das Spiel zu starten, muss die SchiffeVersenken.exe Datei (**Pfad: .../cmake-build-debug/Schiffeversenken.exe**) ausgeführt werden und eine beliebige Taste der Tastatur gedrückt werden. Es erscheint ein Spielfeld und am unteren Ende des Bildschirms eine Eingabe für SpielerA, um seine Schiffe zu platzieren, SpielerB muss dementsprechend wegschauen. Um ein Schiff zu platzieren, muss der Spieler das Startfeld und das Endfeld seines gewünschten Schiffes einegben (zB. *A1* 'Enter' *A6*). Das Startfeld muss **links** beziehungsweise **über** dem Endfeld sein. Das Schiff darf **nicht** direkt auf, diagonal oder neben einem anderen Schiff platziert werden und selbstverständlich nicht die Spielfeldränder überschreiten. Die geforderte Länge des einzugebenden Schiffs steht in der Message unter dem Spielfeld. Bereits mit Schiffen besetzte Felder sind mit einem S belegt, alle anderen sind leer. Wenn SpielerA seine Schiffe platziert hat, macht SpielerB dasselbe.
Nach dem Platzieren der Schiffe werden nun zwei Felder nebeneinander angezeigt und die Spieler können abwechselnd auf Felder schießen, auf denen sie ein Schiff vermuten. Die Anzeige ist dabei folgendermaßen:
- nicht beschossene Felder: leeres Feld
- Fail / Wasser / Niete: O
- Schiff / Hit / Treffer: X
- Versenktes Schiff: #

Das Spiel ist gewonnen, wenn alle Schiffe eines Spielers versenkt sind. Es wird der Sieger angezeigt, im Verliererfeld die verbleibenden Schiffe eingefügt und die Frage nach einem erneuten Spiel gestellt.

## Entwicklerdokumentation
Damit das Spiel richtig compiliert wird, wird ein CMake Compiler benötigt.
Um das Spiel zu starten, muss die SchiffeVersenken.exe Datei ausgeführt werden und eine beliebige Taste der Tastatur gedrückt werden. Nachdem beide Spieler ihre Schiffe platziert haben, beginnt die Spielphase. 
Das Spiel ist grundsätzlivh aufgeteilt in die Spielphasen Start, Spiel und End. Jede Spielphase enthält eine manager-Datei, welche die Logik und die Grafik der jeweiligen Phase aufruft.
In der Startphase können beide Spieler ihre Schiffe platzieren.
