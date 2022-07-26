#ifndef TP2_ALGO_JUAREZ_PROCESARARCHIVOS_H
#define TP2_ALGO_JUAREZ_PROCESARARCHIVOS_H

#include <string>
#include <fstream>

#include "../lectura/cuento/Cuento.h"
#include "../lectura/novela/Novela.h"
#include "../lectura/poema/Poema.h"
#include "../lectura/novela/novelaHistorica/NovelaHistorica.h"
#include "../lista/Lista.h"
#include "../escritor/Escritor.h"


class ProcesarArchivos {

protected:
///Atributos
    ifstream archivo;

    string texto;

    int indice;

public:
///Metodos

/// ------------------- Constructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa a ProcesarArchivos.
    ProcesarArchivos();

/// ------------------- Metodos Generales -------------------

///Procesar datos
///@PRE: El archivo debe estar abierto.
///@POS: Asigna el dato obtenido a su correspondiente atributo.
    virtual void procesarDatos () {};

///Apertura archivo
///@PRE: El archivo debe estar cerrado.
///@POS: Abre el archivo si es posible, en caso contrario muestra mensaje de error.
    virtual void aperturaArchivo () {};

///Indice reiniciado
///@PRE: -
///@POS: Devuelve true si el atributo indice vale 1, false en cualquier otro caso.
    bool indiceReiniciado () const;

///Cerrar archivo
///@PRE: El archivo debe estar abierto.
///@POS: Cierra el archivo.
    void cerrarArchivo ();

///Archivo finalizado
///@PRE: El archivo debe estar abierto.
///@POS: Devuelve true si el archivo ya fue leido, false en caso contrario.
    bool archivoFinalizado ();

////Leer linea
///@PRE: El archivo debe estar abierto.
///@POS: Convierte el contenido de la linea del archivo en string.
    void leerLinea ();

/// ------------------- Setters -------------------

///Establecer texto
///@PRE: -
///@POS: Establece el valor del atributo texto.
    void establecerTexto (string texto);

};

#endif //TP2_ALGO_JUAREZ_PROCESARARCHIVOS_H
