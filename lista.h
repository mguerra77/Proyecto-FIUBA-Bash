#ifndef _LISTA_H_
#define _LISTA_H_

#include "nodo.h"

class Lista {
private:
    Nodo* primero;
    Nodo* ultimo;
    Nodo* cursor;
    int cantidad;
    const int MAX_SIZE = 5;


    // pre: 0 < pos <= cantidad
    // pos: devuelve un puntero al nodo en la posicion pos
    Nodo* obtener_nodo(int pos);


    void reemplazar_mas_antiguo(Dato d);

public:
    // CONSTRUCTOR
    // pre: -
    // pos: construye una Lista
    Lista();

    // pre: Se le pasa un tipo de dato (en el caso del ejercicio, entero).
    // pos: Agrega d a la Lista en la ultima pos.
    void alta(Dato d);

    // pre: 0 < pos <= obtener_cantidad()
    // pos: elimina de la Lista el elemento en la posicion pos 
    void baja(int pos);

    // pre: -
    // pos: devuelve true si la Lista esta vacia
    // devuelve false en caso contrario
    bool esta_vacia();

    // pre: 0 < pos <= obtener_cantidad()
    // pos: devuelve el elemento de la posicion pos 
    Dato consulta(int pos);

    // pre: -
    // pos: devuelve la cantidad de elementos en la lista
    int obtener_cantidad();

    // pre: -
    // pos: devuelve true si hay siguiente, false si no
    bool hay_siguiente();

    // pre: hay_siguiente() == true
    // pos: devuelve el siguiente dato y actualiza el cursor
    Dato siguiente();

    // pre: -
    // pos: vuelve el cursor al inicio
    void reiniciar_cursor();


    //Pre: La lista no debe estar vacía.
    //Post: Devuelve el dato almacenado en el primer nodo de la lista.
    Dato mas_antiguo();

    //Pre: La lista no debe estar vacía.
    //Post: Devuelve el promedio de los datos almacenados en todos los nodos de la lista.
    double promedio();


    // DESTRUCTOR
    // pre: -
    // pos: destruye la Lista y libera toda la memoria utilizada.
    ~Lista();
};


#endif // _LISTA_H_