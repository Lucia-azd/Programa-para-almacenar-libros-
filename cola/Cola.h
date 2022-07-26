#ifndef TP2_ALGO_JUAREZ_COLA_H
#define TP2_ALGO_JUAREZ_COLA_H

#include "../nodo/Nodo.h"

template < class Dato >
class Cola {

private:
///Atributos
    Nodo<Dato>* primero;
    Nodo<Dato>* ultimo;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye dos punteros apuntando a nullptr.
    Cola ();

///Destructor
///@PRE: -
///@POS: Libera la memoria dinamica que usa la cola y elimina sus elementos.
    ~Cola ();

/// ------------------- Metodos Generales -------------------

///Alta
///@PRE: Elemento sea de tipo Dato.
///@POS: Crea un nuevo Nodo de tipo Dato con los atributos de elemento. Reapunta los punteros del Nodo.
    void alta (Dato elemento);

///Baja
///@PRE: Que exista un Nodo en la cola.
///@POS: Elimina el primer Nodo de la cola, apunta el puntero primero al siguiente y si no hay mas Nodos en la cola, resetea primero a nullptr.
    void baja ();

///Consulta
///@PRE: Tienen que existir un Nodo o mas en la lista.
///@POS: Obtiene un Dato a traves de la funcion obtenerDato().
    Dato consulta ();

///Vacia
///@PRE: -
///@POS: Si el puntero ultimo apunta a nullptr, devuelve true. Si no false.
    bool vacia ();

};

///*-------------------------*
///*  DEFINICION DE METODOS  *
///*-------------------------*

/// ------------------- Constructor y Destructor -------------------

///Constructor
///
/// \tparam Dato
template < class Dato >
Cola<Dato>::Cola () {
    primero = nullptr;
    ultimo = nullptr;
}

///Destructor
///
/// \tparam Dato
template < class Dato >
Cola<Dato>::~Cola() {
    while (!vacia()) {
        baja();
    }
}

/// ------------------- Metodos Generales -------------------

///Alta
///
/// \tparam Dato
/// \param elemento
template < class Dato >
void Cola<Dato>::alta (Dato elemento) {

    auto nuevo = new Nodo<Dato>(elemento);

    if (primero) {
        ultimo -> cambiarSiguiente(nuevo);
    } else {
        primero = nuevo;
    }
    ultimo = nuevo;
}

///Baja
///
/// \tparam Dato
template < class Dato >
void Cola<Dato>::baja () {

    Nodo<Dato>* borrar = primero;
    primero = primero -> obtenerSiguiente();

    if (!primero) {
        ultimo = nullptr;
    }

    delete borrar;
}

///Consulta
///
/// \tparam Dato
/// \return Dato
template < class Dato >
Dato Cola<Dato>::consulta () {
    return primero -> obtenerDato();
}

///Vacia
///
/// \tparam Dato
/// \return bool
template < class Dato >
bool Cola<Dato>::vacia () {
    return (ultimo == nullptr);
}

#endif //TP2_ALGO_JUAREZ_COLA_H
