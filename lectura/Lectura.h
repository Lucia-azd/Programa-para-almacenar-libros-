#ifndef TP2_ALGO_JUAREZ_LECTURA_H
#define TP2_ALGO_JUAREZ_LECTURA_H

#include "../escritor/Escritor.h"
#include "../constantes.h"

class Lectura {
protected:
///Atributos
    string titulo;
    int minutos;
    int anioPublicacion;
    Escritor* autor;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Lectura.
    Lectura (string titulo, int minutos, int anioPublicacion, Escritor* autor);

///Constructor - para poder pasar como Dato a los templates de la lista
///necesito un constructor por defecto que no reciba argumentos
///@PRE: -
///@POS: -
    Lectura() = default;

///Destructor
///@PRE: -
///@POS: -
    virtual ~Lectura () = default;

/// ------------------- Metodos Generales -------------------

///Mostrar Lectura
///@PRE: -
///@POS: -
    virtual void mostrar () {};

///Mostrar autor
///@PRE: -
///@POS: Muestra por pantalla los datos del autor de la Lectura.
    void mostrarAutor();

///Comparar
///@PRE:
///@POS:
    ///int comparar (Lectura lecturaActual); --> PREGUNTAR SI TIENE QUE SER PRIVATE

/// ------------------- Getters -------------------

///Obtener titulo
///@PRE: -
///@POS: Devuelve el titulo de la Lectura.
    string obtenerTitulo ();

///Obtener minutos
///@PRE: -
///@POS: Devuelve los minutos de la Lectura.
    int obtenerMinutos () const;

///Obtener AnioPublicacion
///@PRE: -
///@POS: Devuelve el anio de publicacion de la Lectura.
    int obtenerAnioPublicacion () const;

///Obtener ObtenerAutor
///@PRE: -
///@POS: Devuelve el autor de la Lectura.
    Escritor* obtenerAutor ();

};


#endif //TP2_ALGO_JUAREZ_LECTURA_H
