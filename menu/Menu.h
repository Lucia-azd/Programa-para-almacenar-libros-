#ifndef TP2_ALGO_JUAREZ_MENU_H
#define TP2_ALGO_JUAREZ_MENU_H

#include <ctime>

#include "../constantes.h"
#include "../lista/Lista.h"
#include "../lectura/Lectura.h"

#include "../procesarArchivos/archivoEscritores/ArchivoEscritores.h"
#include "../procesarArchivos/archivoLecturas/ArchivoLecturas.h"

#include "../cola/Cola.h"

class Menu {

private:
///Atributos
    int opcion;
    string datoUsuario;
    bool operacionExitosa, datoEncontrado;

    Escritor* escritorActual;
    Lectura* lecturaActual;

    Lista<Lectura*>* listaLecturas;
    Lista<Escritor*>* listaEscritores;

    ArchivoLecturas lectura;
    ArchivoEscritores escritor;

public:

///Metodos

/// ------------------- Constructor -------------------

///Constructor
///@PRE: -
///@POS: Construye e inicializa los atributos de Menu.
    Menu(Lista<Lectura*>* listaLecturas, Lista<Escritor*>* listaEscritores);

/// ------------------- Metodos Generales -------------------

/// ---------------------------- SECCION MENU GENERAL ----------------------------

///Mostrar Menu
///@PRE: -
///@POS: Muestra por pantalla el menu con sus opciones.
    void mostrarMenu ();

///Mensaje Exito
///@PRE: -
///@POS: Muestra por pantalla el menu con sus opciones.
    static void mensajeExito ();
    
///Mensaje Error
///@PRE: -
///@POS: Muestra por pantalla un mensaje de error personalizado con el mensaje pasado por parametro.
    static void mensajeError (string error);

///Verificar operacion
///@PRE: -
///@POS: Verifica si la operacion que el usuario pidio que el programa realice se realizo con exito o no;
    void verificarOperacion (string error);

///Opcion Usuario
///@PRE: -
///@POS: Decide que metodo realizar segun la opcion que coloco el usuario.
    void opcionUsuario ();

///Obtener opcion
///@PRE: -
///@POS: Devuelve la opcion elegida por el usuario.
    int obtenerOpcion () const;

/// ---------------------------- SECCION MENU LECTURAS ----------------------------

/// --------->>> AGREGAR LECTURA

///Pedir descripcion de novela historica
///@PRE: -
///@POS: Pide la descripcion de la novela a agregar en el caso que sea HISTORICA.
    void pedirDescripcion ();

///Pedir subtema
///@PRE: Si el dato a pedir es de tipo string debe colocar un string. Si es un int debe colocar un int. Respetar el tipo de dato de la solicitud.
///@POS: Pide el subtema correspondiente al tipo de lectura a agregar.
    void pedirSubtema ();

///Pedir Genero
///@PRE: -
///@POS: Pide al usuario el genero de la novela a agregar.
    void pedirGenero ();

///Pedir Tipo Lectura
///@PRE: -
///@POS: Pide al usuario el tipo de lectura a agregar.
    void pedirTipoLectura ();

///Pedir datos lectura
///@PRE: Si el dato a pedir es de tipo string debe colocar un string. Si es un int debe colocar un int. Respetar el tipo de dato de la solicitud.
///@POS: Pide los datos de la lectura a agregar.
    void pedirDatosLectura ();

///Verificar escritor anonimo
///@PRE: -
///@POS: Verifica si el escritor de la lectura sera anonimo.
    void verificarEscritorAnonimo();

///Agregar Lectura
///@PRE: - 
///@POS: Agrega la lectura deseada con su respectivo escritor a la lista de lecturas.
    void agregarLectura ();

/// --------->>> QUITAR LECTURA

///Quitar Lectura
///@PRE: -
///@POS: Quita la lectura deseada.
    void quitarLectura ();

/// --------->>> SORTEAR LECTURA

///Sortear Lectura
///@PRE: -
///@POS: Muestra por pantalla una lectura aleatoria.
    void sortearLectura ();

///--------->>> LISTAR LECTURAS

///Listar Lecturas
///@PRE: -
///@POS: Muestra por pantalla todas las lecturas de la lista de lecturas.
    void listarLecturas ();

/// --------->>> LISTAR LECTURAS POR ANIO

///Listar Lecturas por rango de años
///@PRE: Los anios ingresados deben ser int. Respetar el tipo de dato de la solicitud.
///@POS: Lista las lecturas entre un determinado intervalo de anios de publicacion.
    void listarLecturasAnios ();

/// --------->>> LISTAR LECTURAS POR ESCRITOR

///Listar Lecturas de un determinado Escritor
///@PRE: El nombre y apellido del escritor a buscar debe ser un string. Respetar el tipo de dato de la solicitud.
///@POS: Lista las lecturas de un determinado escritor.
    void listarLecturasEscritor ();

/// --------->>> LISTAR LECTURAS POR NOVELA

///Mostrar generos
///@PRE: -
///@POS: Muestra por pantalla los generos de Novela.
    static void mostrarGeneros();

///Listar Novelas genero
///@PRE: El genero de las novelas a listar debe ser un int. Respetar el tipo de dato de la solicitud.
///@POS: Lista las novelas de un determinado genero.
    void listarNovelasGenero ();

/// ---------------------------- SECCION MENU ESCRITORES ----------------------------

/// --------->>> AGREGAR ESCRITOR

///Buscar Escritor
///@PRE: -
///@POS: Busca un escritor por nombre y apellido, el escritorActual pasa a ser el escritor encontrado o nullptr en caso que no lo encuentre.
    void buscarEscritor ();

///Pedir datos escritor
///@PRE: Si el dato a pedir es de tipo string debe colocar un string. Si es un int debe colocar un int. Respetar el tipo de dato de la solicitud.
///@POS: Pide los datos del escritor a agregar.
    void pedirDatosEscritor ();

///Agregar Escritor
///@PRE: -
///@POS: Agrega el escritor deseado a la lista de escritores.
    void agregarEscritor ();

/// --------->>> MODIFICAR ESCRITOR

///Tiene anio de fallecimiento
///@PRE: -
///@POS: Verifica si el escritor actual tiene o no anio de fallecimiento.
    bool tieneAnioFallecimiento ();

///Confirmar cambio fallecimiento
///@PRE: -
///@POS: Verifica si el usuario quiere o no modificar un anio de fallecimiento.
    void confirmarCambioFallecimiento ();

///Modificar anio
///@PRE: -
///@POS: Modifica el anio de fallecimiento de un escritor.
    void modificarAnio ();

///Modificar Falleciminto Escritor
///@PRE: -
///@POS: Verifica si el escritor a modificar existe y luego modifica el anio de fallecimiento.
    void modificarEscritor ();

/// --------->>> LISTAR ESCRITORES

///Listar Escritores
///@PRE: -
///@POS: Muestra por pantalla todos los escritores de la lista de escritores. 
    void listarEscritores ();

/// ---------------------------- SECCION ARMAR COLA ----------------------------

///Armar Cola
///@PRE: -
///@POS: Arma una cola ordenada por tiempo de lectura (de menor a mayor).
    void armarCola ();

///Menu Cola
///@PRE: -
///@POS: Decide que metodo realizar segun la opcion que coloco el usuario en el menu Cola.
    void menuCola (Cola<Lectura*>* &colaLecturas);

///Opciones Cola
///@PRE: -
///@POS: Muestra por pantalla las opciones del menu de la cola.
    static void opcionesCola ();

///Menu Lectura leida
///@PRE: -
///@POS: Verifica si la lectura a agregar a la Cola fue leida o no.
    void menuLecturaLeida ();

/// ---------------------------- SECCION SALIR ----------------------------

///Armar Salir
///@PRE: -
///@POS: Sale del programa.
    static void Salir ();

};


#endif //TP2_ALGO_JUAREZ_MENU_H