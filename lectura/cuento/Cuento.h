#ifndef TP2_ALGO_JUAREZ_CUENTO_H
#define TP2_ALGO_JUAREZ_CUENTO_H

#include "../Lectura.h"

class Cuento : public Lectura {
private:
///Atributos
    string libro;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Cuento.
    Cuento (string libro, string titulo, int minutos, int anioPublicacion, Escritor* autor);

///Destructor
///@PRE: -
///@POS: -
    ~Cuento () override = default;

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
///@PRE: -
///@POS: Muestra por pantalla los datos de Cuento.
    void mostrar () override;

/// ------------------- Getters -------------------

///Obtener libro
///@PRE: -
///@POS: Devuelve el título del libro en donde está publicado el Cuento.
    string obtenerLibro ();

};


#endif //TP2_ALGO_JUAREZ_CUENTO_H
