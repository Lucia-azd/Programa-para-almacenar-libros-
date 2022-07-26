#ifndef TP2_ALGO_JUAREZ_ESCRITOR_H
#define TP2_ALGO_JUAREZ_ESCRITOR_H

#include "../paletaDeColores.h"

class Escritor {

private:
///Atributos
    string nombreApellido;
    string nacionalidad;
    int anioNacimiento;
    int anioFallecimiento;

public:
///Metodos

/// ------------------- Constructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Escritor.
    Escritor (string nombreApellido, string nacionalidad, int anioNacimiento, int anioFallecimiento);

///Constructor - para poder pasar como Dato a los templates de la lista
///necesito un constructor por defecto que no reciba argumentos
///@PRE: -
///@POS: -
    Escritor () = default;

/// ------------------- Metodos Generales -------------------

///Mostrar escritor
///@PRE: -
///@POS: Muestra por pantalla los datos del Escritor.
    void mostrar ();

/// ------------------- Setters -------------------

///Modificar anioFallecimiento
///@PRE: -
///@POS: Modifica el anio de fallecimiento del Escritor.
    void modificarFallecimiento (int anioFallecimiento);

/// ------------------- Getters -------------------

///Obtener NombreApellido
///@PRE: -
///@POS: Devuelve el nombre y apellido del Escritor.
    string obtenerNombreApellido();

///Obtener Nacionalidad
///@PRE: -
///@POS: Devuelve la nacionalidad del Escritor.
    string obtenerNacionalidad();

///Obtener AnioNacimiento
///@PRE: -
///@POS: Devuelve el anio de nacimiento del Escritor.
    int obtenerAnioNacimiento() const;

///Obtener AnionFallecimiento
///@PRE: -
///@POS: Devuelve el anio de fallecimiento del Escritor.
    int obtenerAnioFallecimiento() const;

};

#endif //TP2_ALGO_JUAREZ_ESCRITOR_H
