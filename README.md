# Number Guessing Game (C++)

Interaktywna gra konsolowa napisana w C++.
Zadaniem gracza jest odgadnąć losową liczbę, a wyniki zapisywane są w tablicy wyników.

# Funkcjonalności
# Rozgrywka

trzy poziomy trudności: łatwy (1–50), średni (1–100), trudny (1–200)

walidacja danych wejściowych

losowe komunikaty motywujące

# Tryb zakładów

gracz może obstawić, w ilu próbach odgadnie liczbę

jeśli zmieści się w limicie — wygrywa zakład

# Tablica wyników

zapis do pliku scoreboard.txt

sortowanie wyników po liczbie prób (rosnąco)

wyświetlanie TOP 5

filtrowanie po poziomie trudności

# Struktura projektu
main.cpp
gameplay.cpp
scoreboardoperations.cpp
fileoperations.cpp
functions.hpp
scoreboard.txt

# Kompilacja
Linux / macOS
g++ main.cpp gameplay.cpp scoreboardoperations.cpp fileoperations.cpp -o game
./game

Windows (MinGW)
g++ main.cpp gameplay.cpp scoreboardoperations.cpp fileoperations.cpp -o game.exe
game.exe

# Przykładowy scoreboard.txt
Gracjan,latwy,3
Ola,sredni,7
Kamil,trudny,12
