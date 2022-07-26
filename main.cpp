#include "procesarArchivos/archivoEscritores/ArchivoEscritores.h"
#include "procesarArchivos/archivoLecturas/ArchivoLecturas.h"
#include "menu/Menu.h"
#include "constantes.h"

int main() {

    ArchivoEscritores archivoEscritores;

    Lista<Escritor*> listaEscritores = archivoEscritores.procesarArchivoEscritores();
    Lista<Escritor*>* listaEscritoresRef = &listaEscritores;

    ArchivoLecturas archivoLecturas(listaEscritoresRef);

    Lista<Lectura*> listaLecturas = archivoLecturas.procesarArchivoLecturas();
    Lista<Lectura*>* listaLecturasRef = &listaLecturas;

    Menu menu(listaLecturasRef, listaEscritoresRef);

    do{
        menu.mostrarMenu();
    } while ( menu.obtenerOpcion() != opcion::SALIR );

    return 0;
}