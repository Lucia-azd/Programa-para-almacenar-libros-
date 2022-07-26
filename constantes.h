#ifndef TP2_ALGO_JUAREZ_CONSTANTES_H
#define TP2_ALGO_JUAREZ_CONSTANTES_H

#include <iostream>

using namespace std;

///Rutas de archivos:
const string RUTA_LECTURAS = "procesarArchivos/archivos/lecturas.txt";
const string RUTA_ESCRITORES = "procesarArchivos/archivos/escritores.txt";


///Archivo Escritores
const string TEXTO_VACIO = "";
const int DATO_VACIO = -1;

///Indices Archivo Escritores
const int INDICE_REFERENCIA = 1;
const int INDICE_NOMBRE_APELLIDO = 2;
const int INDICE_NACIONALIDAD = 3;
const int INDICE_NACIMIENTO = 4;
const int INDICE_FALLECIMIENTO = 5;

///Indices Archivo Lecturas
const int INDICE_TIPO_LECTURA = 1;
const int INDICE_TITULO = 2;
const int INDICE_MINUTOS_LECTURA = 3;
const int INDICE_ANIO_PUBLICACION = 4;
const int INDICE_SUBTEMA = 5;
const int INDICE_AUTOR = 6;

///Generos de novela
enum genero {
    DRAMA = 1,
    COMEDIA ,
    FICCION,
    SUSPENSO,
    TERROR,
    ROMANTICA,
    HISTORICA
    };

/// comparar
const int IGUAL = 0;
const int MENOR = -1;
const int MAYOR = 1;

///Tipos de lecturas:
const string NOVELA = "N";
const string CUENTO = "C";
const string POEMA = "P";
const string NOVELA_HISTORICA = "HISTORICA";

///Autor de Lectura
const string AUTOR_ANONIMO = "ANONIMO";

///Opciones del Menu
enum opcion {
    AGREGAR_LECTURA = 1,
    QUITAR_LECTURA,
    AGREGAR_ESCRITOR,
    CAMBIAR_FALLECIMIENTO_ESCRITOR,
    LISTAR_ESCRITORES,
    SORTEAR_LECTURA,
    LISTAR_LECTURAS,
    LISTAR_LECTURAS_ANIOS,
    LISTAR_LECTURAS_ESCRITOR,
    LISTAR_NOVELAS_GENERO,
    ARMAR_COLA,
    SALIR
    };

///Opciones Tipo Lectura
enum tipo_lectura_opcion {
    TIPO_NOVELA = 1,
    TIPO_CUENTO,
    TIPO_POEMA
    };

///Menu Modificar Fallecimiento de un Escritor
const string ACEPTAR = "1";
const string RECHAZAR = "2";

///Opciones del menu cola
enum menu_cola {
    MOSTRAR_ELEMENTO = 1,
    ELIMINAR_ELEMENTO,
    VOLVER_MENU_GENERAL
    };

///Menu Cola
const string LECTURA_LEIDA = "1";
const string LECTURA_NO_LEIDA = "2";

#endif //TP2_ALGO_JUAREZ_CONSTANTES_H
