#ifndef TP2_ALGO_JUAREZ_NOVELAHISTORICA_H
#define TP2_ALGO_JUAREZ_NOVELAHISTORICA_H

#include "../Novela.h"

class NovelaHistorica : public Novela {

private:
///Atributos
    char* tema;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de NovelaHistorica.
    NovelaHistorica (char* tema, int genero, string titulo, int minutos, int anioPublicacion, Escritor* autor);

///Destructor
///@PRE: -
///@POS: Libera la memoria dinamica usada por su atributo tema.
    ~NovelaHistorica () override;

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
///@PRE: -
///@POS: Muestra por pantalla los datos de Novela Historica.
    void mostrar () override;

/// ------------------- Getters -------------------

///Obtener tema
///@PRE: -
///@POS: Devuelve el tema de la Novela Historica.
    char* obtenerTema ();

};


#endif //TP2_ALGO_JUAREZ_NOVELAHISTORICA_H
