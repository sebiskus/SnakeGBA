## Snake GBA

************************************************************************
Befehl zum Compilen: export DEVKITPRO=/opt/devkitpro && sudo -E make -j6

Python3, DEVKITARM und WONDERFUL_TOOLCHAIN müssen installiert sein (siehe Butano repo: https://github.com/GValiente/butano)
************************************************************************

**TODO und issues**

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
- Spielende ("Gewonnen!") implementieren
- Richtiges Pause-Menü implementieren
- 



_issues:_

- Speed Geschwindigkeit nur noch die Hälfte. Doppelte frame times prüfen
- Seed fixen
- Hintergrund ist pink (auch wenn`s cool ist)
- Musik fixen
- Speicher System programmieren + Highscores

- Info in bn::info verlagern

*OPTIONAL*

palette.cpp
- Mehr Grafikstyle
- mission_scanner() => Prüft welche Missionen verfügbar sind und welche geschafft wurden.

menu.cpp
- Richtiges Menü inkl. language Options implementieren


