# Homework_2
Homework 2 Paradigmas

Compilacion ejercicio 1:
g++ ej1.hpp -Wall -g -o ej1h -Wextra
g++ ej1.cpp -Wall -g -o ej1c -Wextra
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej1c

Compilacion ejercicio 2:
g++ ej2.hpp -Wall -g -o ej2h -Wextra
g++ ej2.cpp -Wall -g -o ej2c -Wextra
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej2c

Compilacion ejercicio 3:
g++ ej3.hpp -Wall -g -o ej3h -Wextra
g++ ej3.cpp -Wall -g -o ej3c -Wextra
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej3c

Compilacion ejercicio 4:
g++ ej4.hpp -Wall -g -o ej4h -Wextra
g++ ej4.cpp -Wall -g -o ej4c -Wextra
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ej4c
