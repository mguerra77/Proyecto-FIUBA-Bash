#ifndef _NODO_H_
#define _NODO_H_

typedef int Dato;

class Nodo {
private:
    
    // ATRIBUTOS

    Dato dato;
    Nodo* siguiente;

public:

    // CONSTRUCTORES

    // pos: Construye un Nodo con un dato d y siguiente en nullptr.
    Nodo(Dato d);
    // pos: Construye un Nodo con un dato d y siguiente en pn.
    Nodo(Dato d, Nodo* pn);

    // METODOS

    //Post: Devuelve el dato almacenado en el nodo.
    Dato obtener_dato();

    //Post: Devuelve un puntero al siguiente nodo, o un puntero nulo si el nodo actual es el último en la lista.
    Nodo* obtener_siguiente();

    //Pre: Se pasa un dato (d) que se desea almacenar en el nodo.
    //Postcondición: Actualiza el dato almacenado en el nodo con el valor proporcionado.
    void cambiar_dato(Dato d);

    //Pre: Se pasa como argumento un puntero a un nodo (pn).
    //Post: Establece el siguiente nodo en la secuencia como el nodo apuntado por el puntero pn.
    void cambiar_siguiente(Nodo* pn);
};

#endif // _NODO_H_