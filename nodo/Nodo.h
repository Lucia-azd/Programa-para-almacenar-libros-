#ifndef TP2_ALGO_JUAREZ_NODO_H
#define TP2_ALGO_JUAREZ_NODO_H

template < class Dato >
class Nodo {

private:
///Atributos
    Dato dato;
    Nodo<Dato>* siguiente;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Nodo.
    Nodo (Dato dato);

///Constructor
///@PRE: -
///@POS: -
    Nodo () = default;

/// ------------------- Setters -------------------

///Cambiar siguiente
///@PRE: -
///@POS: Reapunta el siguiente de Nodo al Nodo pasado por parametro.
    void cambiarSiguiente (Nodo<Dato>* nodo);

///------------------- Getters -------------------

///Obtener dato
///@PRE: -
///@POS: Devuelve el dato del Nodo.
    Dato obtenerDato () const;

///Obtener siguiente
///@PRE: -
///@POS: Devuelve el siguiente Nodo al que apunta Nodo.
    Nodo<Dato>* obtenerSiguiente ();

};

///*-------------------------*
///*  DEFINICION DE METODOS  *
///*-------------------------*

/// ------------------- Constructor -------------------

///Constructor
///
/// \tparam Dato
/// \param dato_
template < class Dato >
Nodo<Dato>::Nodo (Dato dato_) {
    dato = dato_;
    siguiente = nullptr;
}

/// ------------------- Setters -------------------

///Cambiar siguiente
///
/// \tparam Dato
/// \param nodo
template < class Dato >
void Nodo<Dato>::cambiarSiguiente (Nodo<Dato>* nodo) {
    siguiente = nodo;
}

///------------------- Getters -------------------

///Obtener dato
///
/// \tparam Dato
/// \return Dato
template < class Dato >
Dato Nodo<Dato>::obtenerDato () const{
    return dato;
}

///Obtener siguiente
///
/// \tparam Dato
/// \return Nodo<Dato>*
template < class Dato >
Nodo<Dato>* Nodo<Dato>::obtenerSiguiente () {
    return siguiente;
}

#endif //TP2_ALGO_JUAREZ_NODO_H
