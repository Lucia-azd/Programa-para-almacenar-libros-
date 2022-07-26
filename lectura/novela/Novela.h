#ifndef TP2_ALGO_JUAREZ_NOVELA_H
#define TP2_ALGO_JUAREZ_NOVELA_H

#include "../Lectura.h"

class Novela : public Lectura {

protected:
///Atributos
    int genero;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Novela.
    Novela (int genero, string titulo, int minutos, int anioPublicacion, Escritor* autor);

///Destructor
///@PRE: -
///@POS: -
    ~Novela () override = default;

/// ------------------- Metodos Generales -------------------

///Mostrar lecturas
///@PRE: -
///@POS: Muestra por pantalla los datos de Novela.
    void mostrar () override;

///Mostrar genero
///@PRE: -
///@POS: Muestra por pantalla el genero de la Novela.
    void mostrarGenero () const;

/// ------------------- Getters -------------------

///Obtener Genero
///@PRE: -
///@POS: Devuelve el genero de la Novela.
    int obtenerGenero () const;

};


#endif //TP2_ALGO_JUAREZ_NOVELA_H
