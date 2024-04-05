#include <iostream>
#include "lista.h"
int main() {
    Lista miLista;

    miLista.alta(10);
    miLista.alta(20);
    miLista.alta(30);
    miLista.alta(40);
    miLista.alta(50);

    std::cout << "Cantidad de elementos en la lista: " << miLista.obtener_cantidad() << std::endl;

    std::cout << "Valor más antiguo en la lista: " << miLista.mas_antiguo() << std::endl;

    std::cout << "Promedio de todos los elementos en la lista: " << miLista.promedio() << std::endl;

    return 0;
}