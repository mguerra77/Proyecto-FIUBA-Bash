#include "lista.h"
#include <iostream>

Lista::Lista() {
    primero = nullptr;
    cursor = primero;
    ultimo = nullptr;
    cantidad = 0;
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* pn = primero;
    for (int i = 1; i < pos; i++)
        pn = pn->obtener_siguiente();
    return pn;
}

void Lista::alta(Dato d) {
    Nodo* nuevo = new Nodo(d);
    if (esta_vacia()) {
        primero = nuevo;
        ultimo = nuevo;
        cursor = nuevo;
        cantidad++;
    } else {
        if (cantidad < MAX_SIZE) {
            ultimo->cambiar_siguiente(nuevo);
            ultimo = nuevo;
            ultimo->cambiar_siguiente(primero);
            cantidad++;
        } else {
            reemplazar_mas_antiguo(d);
        }
    }
}

void Lista::reemplazar_mas_antiguo(Dato d) {
    primero->cambiar_dato(d);
    primero = primero->obtener_siguiente();
    ultimo = ultimo->obtener_siguiente();
}

void Lista::baja(int pos) {
    Nodo* borrar = primero;
    if (pos == 1) {
        primero = borrar->obtener_siguiente();
        ultimo->cambiar_siguiente(primero);
        reiniciar_cursor();
    } else {
        Nodo* anterior = obtener_nodo(pos-1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }

    if (cursor == borrar)
        siguiente();
    delete borrar;
    cantidad--;
}

Dato Lista::consulta(int pos) {
    Nodo* pn = obtener_nodo(pos);
    return pn->obtener_dato();
}

bool Lista::esta_vacia() {
return (cantidad == 0);
}

int Lista::obtener_cantidad() {
return cantidad;
}

bool Lista::hay_siguiente() {
    return (cursor != nullptr);
}

Dato Lista::siguiente() {
    Dato dato = cursor->obtener_dato();
    cursor = cursor->obtener_siguiente();
    return dato;
}

void Lista::reiniciar_cursor() {
    cursor = primero;
}


Dato Lista::mas_antiguo() {
    if (esta_vacia()) {
        throw std::runtime_error("La lista está vacía.");
    }
    return primero->obtener_dato();
}

double Lista::promedio() {
    if (cantidad == 0) {
        throw std::runtime_error("La lista está vacía.");
    }

    double suma = 0.0;
    Nodo* actual = primero;
    for (int i = 0; i < cantidad; ++i) {
        suma += actual->obtener_dato();
        actual = actual->obtener_siguiente();
    }

    return suma / cantidad;
}

Lista::~Lista() {
    while (!esta_vacia())
        baja(1);
}