#ifndef TP2_ALGO_JUAREZ_POEMA_H
#define TP2_ALGO_JUAREZ_POEMA_H

#include "../Lectura.h"

class Poema : public Lectura{

private:
///Atributos
    int versos;

public:
///Metodos

/// ------------------- Constructor y Destrcutor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Poema.
    Poema (int versos, string titulo, int minutos, int anioPublicacion, Escritor* autor);

///Destructor
///@PRE: -
///@POS: -
    ~Poema () override = default;

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
///@PRE: -
///@POS: Muestra por pantalla los datos de Poema.
    void mostrar () override;

/// ------------------- Getters -------------------

///Obtener versos
///@PRE: -
///@POS: Devuelve la cantidad de versos del Poema.
    int obtenerVersos () const;

};


#endif //TP2_ALGO_JUAREZ_POEMA_H
