#ifndef TP2_ALGO_JUAREZ_ARCHIVOESCRITORES_H
#define TP2_ALGO_JUAREZ_ARCHIVOESCRITORES_H

#include "../ProcesarArchivos.h"
#include "../../constantes.h"


class ArchivoEscritores : public ProcesarArchivos {

private:
///Atributos
    string nombreApellido, nacionalidad;
    int anioNacimiento, anioFallecimiento;

public:
///Metodos

/// ------------------- Constructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de ArchivoEscritores.
    ArchivoEscritores();

/// ------------------- Metodos Generales -------------------

///Apertura archivo
///@PRE El archivo debe estar cerrado.
///@POS Abre el archivo si es posible, en caso contrario muestra mensaje de error.
    void aperturaArchivo () override;

///Procesar Datos
///@PRE Debe haberse leido una linea del archivo.
///@POS Asigna el dato obtenido a su correspondiente atributo.
    void procesarDatos () override;

///Comprobar falta datos
///@PRE Debe haberse leido una linea del archivo.
///@POS Acomoda indice y establece datos en el caso de desconocerlos en el archivo.
    void comprobarFaltaDatos ();

///Crear escritor
///@PRE Los atributos deben tener contenido.
///@POS Instancia y devuelve un objeto del tipo Escritor.
    Escritor* crearEscritor ();

///Procesar archivo escritores
///@PRE -
///@POS Carga la lista pasada por parametro con los datos obtenidos del archivo txt.
    Lista<Escritor*> procesarArchivoEscritores ();

/// ------------------- Setters -------------------

///Establecer anio fallecimiento.
///@PRE -
///@POS Establece el valor del atributo anioFallecimiento.
    void establecerAnioFallecimiento (int anioFallecimiento);

///Establecer nombre y apellido.
///@PRE -
///@POS Establece el valor del atributo nombreApellido.
    void establecerNombreApellido (string nombreApellido);

///Establecer nacionalidad.
///@PRE -
///@POS Establece el valor del atributo nacionalidad.
    void establecerNacionalidad (string nacionalidad);

///Establecer anio Nacimiento.
///@PRE -
///@POS Establece el valor del atributo anioNacimiento.
    void establecerAnioNacimiento (int anioNacimiento);

///------------------- Getters -------------------

///Obtener nombre y apellido
///PRE: -
///POS: Devuelve el dato del atributo nombreApellido.
    string obtenerNombreApellido ();
};

#endif //TP2_ALGO_JUAREZ_ARCHIVOESCRITORES_H
