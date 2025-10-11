************************************************************************
Befehl zum Compilen: export DEVKITPRO=/opt/devkitpro && sudo -E make -j6
************************************************************************



renderer.cpp:
Komplett umschreiben (siehe updated_renderer)

player.cpp:
- Steuerung überarbeiten. Soll bereits vorher Button Presses checken und temporär abspeichern












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


