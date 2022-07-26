#ifndef TP2_ALGO_JUAREZ_ARCHIVOLECTURAS_H
#define TP2_ALGO_JUAREZ_ARCHIVOLECTURAS_H


#include "../ProcesarArchivos.h"
#include "../../constantes.h"

class ArchivoLecturas : public ProcesarArchivos {

private:
///Atributos
    Lista<Escritor*>* listaEscritores;

    string tipoLectura, titulo, subtema, auxiliarReferencia;

    char* descripcion;

    Escritor* autor;

    int minutosLectura, anio, referencia, genero;

public:
///Metodos

/// ------------------- Constructor y Destructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de ArchivoLecturas.

    ArchivoLecturas(Lista<Escritor*> *listaEscritores);

///Constructor - para poder pasar como Dato a los templates de la lista
///necesito un constructor por defecto que no reciba argumentos
///@PRE: -
///@POS: -
    ArchivoLecturas () = default;

/// ------------------- Metodos Generales -------------------

///Apertura archivo
///@PRE El archivo debe estar cerrado.
///@POS Abre el archivo si es posible, en caso contrario muestra mensaje de error.
    void aperturaArchivo () override;

///Procesar datos
///@PRE El archivo debe estar abierto.
///@POS Asigna el dato obtenido a su correspondiente atributo.
    void procesarDatos () override;

///Crear poema
///@PRE Los atributos deben tener contenido.
///@POS Instancia un objeto del tipo Poema y devuelve un puntero al mismo.
    Poema* crearPoema ();

///Crear cuento
///PRE Los atributos deben tener contenido.
///@POS Instancia un objeto del tipo Cuento y devuelve un puntero al mismo.
    Cuento* crearCuento ();

///Crear novela
///@PRE Los atributos deben tener contenido.
///@POS Instancia un objeto del tipo Novela y devuelve un puntero al mismo.
    Novela* crearNovela ();

///Crear novela historica
///@PRE Los atributos deben tener contenido.
///@POS Instancia un objeto del tipo NovelaHistorica y devuelve un puntero al mismo.
    NovelaHistorica* crearNovelaHistorica ();

///Crear lectura
///@PRE Los atributos deben tener contenido.
///@POS Crea un objeto del tipo Lectura y devuelve un puntero al mismo.
    Lectura* crearLectura ();

///Convertir referencia
///@PRE: -
///@POS: Convierte el numero que se encuentra en la referencia de tipo string a tipo int.
    void convertirReferencia ();

///procesar archivoLecturas
///@PRE: -

///@POS: Realiza el proceso para leer y almacenar datos de un archivo.
    Lista<Lectura*> procesarArchivoLecturas();

///Asignar autor
///@PRE: -
///@POS: Asigna al atributo autor el autor que se encuntra en la posicion igual a la referencia
///      en la lista de escritores.
    void asignarAutor ();

///Convertir genero.
///@PRE: -
///@POS: Convierte el genero en tipo string a su constante int determinada.
    void convertirGenero ();

/// ------------------- Setters -------------------

///Establecer referencia
///@PRE: -
///@POS: Establece el valor del atributo referencia.
    void establecerReferencia (int referencia);

///Establecer tipo lectura.
///@PRE: -
///@POS: Establece el valor del atributo TipoLectura.
    void establecerTipoLectura (string tipoLectura);

///Establecer titulo.
///@PRE -
///@POS Establece el valor del atributo Titulo.
    void establecerTitulo (string titulo);

///Establecer subtema.
///@PRE -
///@POS Establece el valor del atributo Subtema.
    void establecerSubtema (string subtema);

///Establecer descripcion.
///@PRE -
///@POS Establece el valor del atributo descripcion.
    void establecerDescripcion (string descripcion);

///Establecer autor.
///@PRE -
///@POS Establece el valor del atributo autor.
    void establecerAutor (Escritor* autor);

///Establecer MinutosLectura.
///PRE: -
///POS: Establece el valor del atributo minutosLectura.
    void establecerMinutosLectura (int minutosLectura);

///Establecer Anio.
///@PRE -
///@POS Establece el valor del atributo anio.
    void establecerAnio (int anio);

///------------------- Getters -------------------

///Obtener tipo de dato
///PRE: -
///POS: Devuelve el atributo TipoLectura
    string obtenerTipoLectura ();
};



#endif //TP2_ALGO_JUAREZ_ARCHIVOLECTURAS_H
