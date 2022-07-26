#ifndef TP2_ALGO_JUAREZ_LISTA_H
#define TP2_ALGO_JUAREZ_LISTA_H

#include "../nodo/Nodo.h"
#include "../constantes.h"

template < class Dato >
class Lista {

private:
///Atributos
    Nodo<Dato>* primero;
    Nodo<Dato>* cursor;
    int cantidad;

public:

///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de una clase Lista.
    Lista ();

///Destructor
///@PRE: -
///@POS: Libera la memoria dinamica que usa la lista y elimina sus elementos.
    ~Lista ();

///Metodos

/// ------------------- Metodos Generales -------------------

///Baja
///@PRE: -
///@POS: Elimina el primer elemento de la lista, apunta el puntero primero al siguiente y si no hay mas Nodos en la cola, resetea primero a nullptr.
    void baja ();

///Alta
///@PRE: -
///@POS: Agrega el elemento pasado por parametro a la lista.
    void alta (Dato elemento);

///Alta ordenada
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion o minutos de lectura (de menor a mayor).
///@POS: Agrega el elemento pasado por parametro respetando el orden de la lista.
    void altaOrdenada (Dato elemento, bool altaPorAnio);

///Baja
///@PRE: La lista debe ser de Lecturas.
///@POS: Devuelve los anios de publicacion del elemento al que apunta el cursor si es un alta ordenada por anio de publicacion,
///      o los minutos de lectura si es un alta ordenada por minutos de lectura.
    int actualizarDatoCursorAlta(bool altaPorAnio);

///Comparar
///@PRE: Los datos a comparar deben ser numeros.
///@POS: Devuelve 0 si los datos a comparar pasados por parametros son iguales,
///     -1 si el datoElemento es menor al datoCursor,
///     o 1 si el datoElemento es mayor al datoCursor.
    int comparar(int datoCursor, int datoElemento);

///Consulta
///@PRE: -
///@POS: Devuelve el dato del elemento que se encuentra en la posicion pasada por parametro.
    Dato consulta (int posicion);

///Vacia
///@PRE: -
///@POS: Devuelve true si la cantidad de elementos de la lista es cero, o false en caso contrario.
    bool vacia ();

///Listar intervalo
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion o minutos de lectura (de menor a mayor).
///@POS: Muestra por pantalla todas las lecturas que su anio de publicacion esten dentro de los anios pasados por parametro.
    void listarIntervalo (int desde, int hasta);

///Obtener cantidad
///@PRE: -
///@POS: Devuelve la cantidad de elementos de la lista.
    int obtenerCantidad ();

///baja ordenada
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion (de menor a mayor).
///@POS: Da de baja el elemento con los datos iguales a los pasados por parametro.
    void bajaOrdenada (int anioPublicacion, string titulo);

///mostrar elementos de la lista
///@PRE: -
///@POS: Muestra por pantalla los elementos de la lista.
    void mostrarElementos ();

///Reiniciar cursor
///@PRE: -
///@POS: Reapunta el cursor al primer elemento.
    void reiniciarCursor ();

///Iterar lista
///@PRE: -
///@POS: Itera toda la lista devolviendo cada elemento.
    Dato iterarLista ();

///Dato primero
///@PRE: -
///@POS: Devuelve el dato del primer elemento de la lista.
    Dato datoPrimero ();

private:

///Apuntar cursor
///@PRE: -
///@POS: Reapunta el cursor, si la lista esta vacia al primer elemento (nullptr), o si no al nuevo elemento agregado.
    void apuntarCursor (Nodo<Dato>* nuevo);

///Alta omparacion inicial mayor
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion o minutos de lectura (de menor a mayor).
///@POS: Busca el lugar que le corresponde al elemento a agregar, comparandolo con los elemendos mayores al cursor actual de la lista y lo agrega.
    void altaComparacionInicialMayor(Nodo<Dato>* nuevo, int datoElemento, bool altaPorAnio);

///Alta comparacion inicial menor
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion o minutos de lectura (de menor a mayor).
///@POS: Busca el lugar que le corresponde al elemento a agregar, comparandolo con los elemendos menores al cursor actual de la lista y lo agrega.
    void altaComparacionInicialMenor(Nodo<Dato>* nuevo, int datoElemento, bool altaPorAnio);

///Alta comparacion inicial igual
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion o minutos de lectura (de menor a mayor).
///@POS: Agrega el nuevo elemento a la lista.
    void altaComparacionInicialIgual(Nodo<Dato>* nuevo);

///Alta primer elemento
///@PRE: -
///@POS: Agrega el nuevo elemento pasado por parametro al inicio de la lista.
    void altaPrimerElemento(Nodo<Dato>* nuevo);

///Caso ultimo elemento
///@PRE: -
///@POS: Agrega el nuevo elemento pasado por parametro al final de la lista.
    void altaUltimoElemento(Nodo<Dato>* nuevo);

///Elemento encontrado
///@PRE: La lista debe ser de Lecturas.
///@POS: Si el anio de publicacion y el titulo de lo que apunta el cursor es igual a los pasados por parametro devuelve true, caso contrario false.
    bool elementoEncontrado(int datoElemento, string titulo);

///Baja Comparacion Incial Igual Menor
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion (de menor a mayor).
///@POS: Busca el elemento a eliminar entre los elementos con un anio de publicacion menor al cursor actual de la lista y lo elimina.
    void bajaComparacionInicialIgualMenor(int anioPublicacion, string titulo);

///Baja Comparacion Inicial Mayor
///@PRE: La lista debe ser de Lecturas y estar ordenada por anio de publicacion (de menor a mayor).
///@POS: Busca el elemento a eliminar entre los elementos con un anio de publicacion mayor al cursor actual de la lista y lo elimina.
    void bajaComparacionInicialMayor(int anioPublicacion, string titulo);

/// ------------------- Getters -------------------

///ObtenerNodo
///@PRE: -
///@POS: Devuelve el nodo que se encuentra en la posicion pasada por parametro.
    Nodo<Dato>* obtenerNodo (int posicion);
};

///*-------------------------*
///*  DEFINICION DE METODOS  *
///*-------------------------*

/// ------------------- Constructor y Destructor -------------------

///Constructor
///
/// \tparam Dato
template < class Dato >
Lista<Dato>::Lista () {
    primero = nullptr;
    cursor = nullptr;
    cantidad = 0;
}

///Destructor
///
/// \tparam Dato
template < class Dato >
Lista<Dato>::~Lista () {

    cursor = nullptr;

    while (!vacia()) {
        Nodo<Dato>* borrarNodo = primero;
        Dato borrarDato = primero -> obtenerDato();

        if (cantidad > 1) {
            primero = primero -> obtenerSiguiente();

        }else {
            primero = nullptr;
        }

        delete borrarNodo;
        delete borrarDato;
        cantidad--;
    }
}

/// ------------------- Metodos Generales -------------------

///Baja
///
/// \tparam Dato
template < class Dato >
void Lista<Dato>::baja () {
    Nodo<Dato>* borrar = primero;

    if (cantidad > 1) {
        primero = primero -> obtenerSiguiente();

    }else if (cantidad <= 1 && cantidad != 0) {
        primero = nullptr;
    }
    cantidad--;
    delete borrar;
}

///Alta
///
/// \tparam Dato
/// \param elemento
template < class Dato >
void Lista<Dato>::alta(Dato elemento) {

    auto nuevo = new Nodo<Dato>(elemento);

    if ( vacia() ) {
        nuevo -> cambiarSiguiente(primero);
        primero = nuevo;
    } else {
        nuevo -> cambiarSiguiente(cursor->obtenerSiguiente());
        cursor -> cambiarSiguiente(nuevo);
    }
    apuntarCursor(nuevo);
    cantidad++;
}

///Actualizar dato cursor alta
///
/// \tparam Dato
/// \param altaPorAnio
/// \return int
template < class Dato >
int Lista<Dato>::actualizarDatoCursorAlta(bool altaPorAnio) {
    int datoCursor;

    if (altaPorAnio) {
        datoCursor = (cursor -> obtenerDato()) -> obtenerAnioPublicacion();

    } else {
        datoCursor = (cursor -> obtenerDato()) -> obtenerMinutos();
    }
    return datoCursor;
}


///Alta Ordenada
/// \tparam Dato
/// \param elemento
template < class Dato >
void Lista<Dato>::altaOrdenada(Dato elemento, bool altaPorAnio) {

    auto nuevo = new Nodo<Dato>(elemento);

    if ( vacia() ) {
        altaPrimerElemento(nuevo);

    } else {
        int datoElemento, datoCursor;

        if (altaPorAnio){
            datoElemento = elemento -> obtenerAnioPublicacion();
            datoCursor = (cursor -> obtenerDato()) -> obtenerAnioPublicacion();

        } else{
            datoElemento = elemento -> obtenerMinutos();
            datoCursor = (cursor -> obtenerDato()) -> obtenerMinutos();
        }

        int comparacion = comparar(datoCursor, datoElemento);

        if (comparacion == IGUAL){
            altaComparacionInicialIgual(nuevo);

        } else if (comparacion == MAYOR){
            altaComparacionInicialMayor(nuevo, datoElemento, altaPorAnio);

        } else {
            altaComparacionInicialMenor(nuevo, datoElemento, altaPorAnio);
        }
    }
    apuntarCursor(nuevo);
    cantidad++;
}

///Comparacion inicial igual
///
/// \tparam Dato
/// \param nuevo
template < class Dato >
void Lista<Dato>::altaComparacionInicialIgual(Nodo<Dato>* nuevo){
    nuevo -> cambiarSiguiente(cursor -> obtenerSiguiente());
    cursor -> cambiarSiguiente(nuevo);
}

///Comparacion inicial mayor
///
/// \tparam Dato
/// \param nuevo
/// \param anioPublicacionElemento
template < class Dato >
void Lista<Dato>::altaComparacionInicialMayor(Nodo<Dato>* nuevo, int datoElemento, bool altaPorAnio){

    if (cursor -> obtenerSiguiente() == nullptr){
        altaUltimoElemento(nuevo);
    } else {
        Nodo<Dato>* anterior;
        int datoCursor = actualizarDatoCursorAlta(altaPorAnio);

        while (comparar(datoCursor, datoElemento) == MAYOR) {

            if (cursor -> obtenerSiguiente() == nullptr) {
                altaUltimoElemento(nuevo);
                datoElemento = 0;

            }else {
                anterior = cursor;
                cursor = cursor -> obtenerSiguiente();
                datoCursor = actualizarDatoCursorAlta(altaPorAnio);
            }
        }
        if (datoElemento != 0){
            nuevo -> cambiarSiguiente(cursor);
            anterior -> cambiarSiguiente(nuevo);
        }
    }
}

///Comparacion inicial menor
///
/// \tparam Dato
/// \param nuevo
/// \param anioPublicacionElemento
template < class Dato >
void Lista<Dato>::altaComparacionInicialMenor(Nodo<Dato>* nuevo, int datoElemento, bool altaPorAnio){

    cursor = primero;
    int datoCursor = actualizarDatoCursorAlta(altaPorAnio);

    if (comparar(datoCursor, datoElemento) == MENOR){
        altaPrimerElemento(nuevo);

    } else {
        Nodo<Dato>* anterior;
        while (comparar(datoCursor, datoElemento) == MAYOR || comparar(datoCursor, datoElemento) == IGUAL){
            anterior = cursor;
            cursor = cursor -> obtenerSiguiente();
            datoCursor = actualizarDatoCursorAlta(altaPorAnio);
        }
        nuevo -> cambiarSiguiente(cursor);
        anterior -> cambiarSiguiente(nuevo);
    }
}

///Caso primer elemento
///
/// \tparam Dato
/// \param nuevo
template < class Dato >
void Lista<Dato>::altaPrimerElemento(Nodo<Dato>* nuevo){
    nuevo -> cambiarSiguiente(primero);
    primero = nuevo;
}

///Caso ultimo elemento
///
/// \tparam Dato
/// \param nuevo
template < class Dato >
void Lista<Dato>::altaUltimoElemento(Nodo<Dato>* nuevo){
    cursor -> cambiarSiguiente(nuevo);
    nuevo -> cambiarSiguiente(nullptr);
}

///Comparar
///
/// \tparam Dato
/// \param anioPublicaicioElemento
/// \return int
template < class Dato>
int Lista<Dato>::comparar(int datoCursor, int datoElemento){

    int retorno = IGUAL;

    if (datoElemento < datoCursor){
        retorno = MENOR;

    } else if (datoElemento > datoCursor){
        retorno = MAYOR;

    }
    return retorno;
}

///Listar intervalo
///
/// \tparam Dato
/// \param desde
/// \param hasta
template < class Dato>
void Lista<Dato>::listarIntervalo(int desde, int hasta){

    int datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();
    int comparacionDesde = comparar(datoCursor,desde), comparacionHasta = comparar(datoCursor, hasta);

    if (comparacionDesde == IGUAL || comparacionHasta == MENOR || (comparacionDesde == MENOR && comparacionHasta == MAYOR)){

        cursor = primero;
        datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();
        comparacionHasta = comparar(datoCursor, hasta);
    }

    while ((comparacionHasta == MAYOR || comparacionHasta == IGUAL) && cursor != nullptr){

        if ((cursor->obtenerDato()) -> obtenerAnioPublicacion() >= desde ) {
            (cursor -> obtenerDato()) -> mostrar();
        }
        cursor = cursor -> obtenerSiguiente();

        if (cursor) {
            datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();
            comparacionHasta = comparar(datoCursor, hasta);
        }
    }
    if (cursor == nullptr){
        cursor = primero;
    }
}

///Elemento encontrado
///
/// \tparam Dato
/// \param datoElemento
/// \param titulo
/// \return bool
template < class Dato >
bool Lista<Dato>::elementoEncontrado(int datoElemento, string titulo){
    return (comparar((cursor -> obtenerDato())-> obtenerAnioPublicacion(), datoElemento) == IGUAL && (cursor -> obtenerDato())-> obtenerTitulo() == titulo);
}

///Baja comparacion inicial igual menor
///
/// \tparam Dato
/// \param anioPublicacion
/// \param titulo
template < class Dato >
void Lista<Dato>::bajaComparacionInicialIgualMenor(int anioPublicacion, string titulo) {
    cursor = primero;
    Nodo<Dato>* borrar;

    if (elementoEncontrado(anioPublicacion, titulo)) {

        primero = cursor->obtenerSiguiente();

        borrar = cursor;
        delete borrar;

        cursor = primero;
        cantidad--;

    } else {
        Nodo<Dato> *anterior;
        int datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();

        while (!elementoEncontrado(anioPublicacion, titulo) && comparar(datoCursor, anioPublicacion) != MENOR) {

            anterior = cursor;
            cursor = cursor->obtenerSiguiente();

            datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();
        }

        if (elementoEncontrado(anioPublicacion, titulo)) {

            anterior->cambiarSiguiente(cursor->obtenerSiguiente());

            borrar = cursor;
            delete borrar;

            cursor = anterior;
            cantidad--;
        }
    }
}

///Baja comparacion inicial mayor
///
/// \tparam Dato
/// \param anioPublicacion
/// \param titulo
template < class Dato >
void Lista<Dato>::bajaComparacionInicialMayor(int anioPublicacion, string titulo){

    Nodo<Dato>* borrar;
    Nodo<Dato>* anterior = cursor;

    cursor = cursor->obtenerSiguiente();

    int datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();

    while (cursor != nullptr && !elementoEncontrado(anioPublicacion, titulo) && comparar(datoCursor, anioPublicacion) != MENOR) {

        anterior = cursor;
        cursor = cursor->obtenerSiguiente();

        if (cursor) {
            datoCursor = (cursor->obtenerDato())->obtenerAnioPublicacion();
        }
    }
    if (cursor != nullptr && elementoEncontrado(anioPublicacion, titulo)) {

        anterior->cambiarSiguiente(cursor->obtenerSiguiente());

        borrar = cursor;
        delete borrar;

        cursor = anterior;
        cantidad--;
    }
    if (cursor == nullptr){
        cursor = primero;
    }
}

///Baja ordenada
///
/// \tparam Dato
/// \param posicion
template < class Dato >
void Lista<Dato>::bajaOrdenada (int anioPublicacion, string titulo) {

    if (cantidad == 1 && elementoEncontrado(anioPublicacion, titulo)) {
            baja();

    } else {
        int comparacion = comparar((cursor->obtenerDato())->obtenerAnioPublicacion(), anioPublicacion);

        if (comparacion == IGUAL || comparacion == MENOR){
            bajaComparacionInicialIgualMenor(anioPublicacion, titulo);

        } else {
            bajaComparacionInicialMayor(anioPublicacion, titulo);
        }
    }
}

///Mostrar elementos
///
/// \tparam Dato
template < typename Dato >
void Lista<Dato>::mostrarElementos () {
    cursor = primero;

    while(cursor != nullptr) {
        (cursor -> obtenerDato()) -> mostrar();
        cursor = cursor -> obtenerSiguiente();
    }
    cursor = primero;
}

///Consulta
///
/// \tparam Dato
/// \param posicion
/// \return Dato
template < class Dato >
Dato Lista<Dato>::consulta (int posicion) {
    Nodo<Dato>* auxiliar = obtenerNodo(posicion);
    cursor = auxiliar;
    return auxiliar -> obtenerDato();
}

///Vacia
///
/// \tparam Dato
/// \return bool
template < class Dato >
bool Lista<Dato>::vacia () {
    return (cantidad == 0);
}

///Obtener cantidad
///
/// \tparam Dato
/// \return int
template < class Dato >
int Lista<Dato>::obtenerCantidad () {
    return cantidad;
}

///Apuntar cursor
///
/// \tparam Dato
/// \param nuevo
template < class Dato >
void Lista<Dato>::apuntarCursor (Nodo<Dato>* nuevo) {

    if ( vacia() ) {
        cursor = primero;
    } else {
        cursor = nuevo;
    }
}

///Iterar lista
///
/// \tparam Dato
/// \return Dato
template<class Dato>
Dato Lista<Dato>::iterarLista() {
    Nodo<Dato>* nodoCursor = cursor;

    if (cursor->obtenerSiguiente() != nullptr){
        cursor = cursor -> obtenerSiguiente();
    }

    return nodoCursor->obtenerDato();
}

///Dato primero
///
/// \tparam Dato
/// \return Dato
template<class Dato>
Dato Lista<Dato>::datoPrimero() {
    return primero -> obtenerDato();
}

///Reiniciar cursor
///
/// \tparam Dato
template<class Dato>
void Lista<Dato>::reiniciarCursor() {
    cursor = primero;
}

/// ------------------- Getters -------------------

///Obtener Nodo
///
/// \tparam Dato
/// \param posicion
/// \return Nodo<Dato>*
template < class Dato >
Nodo<Dato>* Lista<Dato>::obtenerNodo (int posicion) {

    Nodo<Dato>* auxiliar = primero;
    int contador = 1;

    while (contador < posicion) {
        auxiliar = auxiliar -> obtenerSiguiente();
        contador++;
    }
    return auxiliar;
}

#endif //TP2_ALGO_JUAREZ_LISTA_H