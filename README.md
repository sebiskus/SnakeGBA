**Snake GBA**

************************************************************************
Befehl zum Compilen: export DEVKITPRO=/opt/devkitpro && sudo -E make -j6
************************************************************************

player.cpp:
- Steuerung simpler machen

Menü:
- Buttons implementieren inkl. Steuerung
- Funktionen in anderen Menüs verlagern

Score:
- Score System implementieren 
- Individuelle Nutzer
    > Anfangs nur generische Namen implementieren (Player A, B, C)
    > New, Duplicate, Delete user, Wipe everything
    > Danach Tastatureingabe implementieren

Style:
- Animationen einstudieren mit Drehungen, Skalierungen
- Matrizen nochmal anschauen
- Neue Font implementieren

Gameplay:
- Ende einprogrammieren (Gewonnen)
- Richtiges Pause Menü
- 



Bug fixes:
- Speed Geschwindigkeit nur noch die Hälfte. Doppelte frame times prüfen
- Seed fixen
- Hintergrund ist pink (auch wenn`s cool ist)
- Musik fixen
- Speicher System programmieren + Highscores

- Info in bn::info verlagern

renderer.cpp
- Translation Layer von Array => richtige Grafik auf dem GBA Display
-> tiles: 4x4px. Tile drawer = Array-Index * 2 + 1 für die Position

player.cpp
- Enthält Player Logik und die Steuerung

map.cpp
- Enthält Map als Array
- 0 = floor, 1 = wall, 2 = player/snake, 3 = apple
- Vielleicht wird da auch die Position berechnet sowie die spawn() Logik?

game.cpp
- Enthält weitere nützliche Methoden & Berechnungen
-> bspw. delay(), debug Funktionen, startup initialisierung












OPTIONAL

palette.cpp
- Mehr Grafikstyle
- mission_scanner() => Prüft welche Missionen verfügbar sind und welche geschafft wurden.

menu.cpp
- Richtiges Menü inkl. language Options (json)


