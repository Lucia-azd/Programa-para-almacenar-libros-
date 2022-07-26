#include "ArchivoEscritores.h"


/// ------------------- Constructor -------------------

///Constructor
ArchivoEscritores::ArchivoEscritores() : ProcesarArchivos() {
    nombreApellido = TEXTO_VACIO;
    nacionalidad = TEXTO_VACIO;
    anioNacimiento = DATO_VACIO;
    anioFallecimiento = DATO_VACIO;
}

/// ------------------- Metodos Generales -------------------


///Apertura archivo
void ArchivoEscritores::aperturaArchivo() {

    archivo.open(RUTA_ESCRITORES ,ios::in);

    if(archivo.fail()){
            cout<< INICIAL<<COLOR_ERROR<<"No se pudo abrir el archivo"<<FINAL << endl;
            exit(1);
    }
}

///Procesar datos
void ArchivoEscritores::procesarDatos() {

    comprobarFaltaDatos();

    switch (indice) {
        case INDICE_REFERENCIA:
            break;
        case INDICE_NOMBRE_APELLIDO:
            nombreApellido = texto;
            break;
        case INDICE_NACIONALIDAD:
            nacionalidad = texto;
            break;
        case INDICE_NACIMIENTO:
            anioNacimiento = stoi(texto);
            break;
        case INDICE_FALLECIMIENTO:
            anioFallecimiento = stoi(texto);
            break;
        default:
            indice = 0;
    }
    indice++;
}

///Comprobar falta de datos
void ArchivoEscritores::comprobarFaltaDatos() {

    if (texto == TEXTO_VACIO){
        if (indice == INDICE_NACIMIENTO) {
            anioNacimiento = DATO_VACIO;
            anioFallecimiento = DATO_VACIO;
            indice += 2;
        } else if (indice == INDICE_FALLECIMIENTO) {
            anioFallecimiento = DATO_VACIO;
            indice++;
        }
    }
}

///Crear Escritor
///
/// \return Escritor*
Escritor* ArchivoEscritores::crearEscritor() {
    return new Escritor(nombreApellido, nacionalidad, anioNacimiento, anioFallecimiento);
}

///Procesar ArchivoEscritores
///
/// \return Lista
Lista<Escritor*> ArchivoEscritores::procesarArchivoEscritores(){

    Lista<Escritor*> listaEscritores;

    aperturaArchivo();

    while (!archivoFinalizado()) {
        leerLinea();
        procesarDatos();

        if (indiceReiniciado()) {
            listaEscritores.alta(crearEscritor());
        }
    }
    cerrarArchivo();

    return listaEscritores;
}

/// ------------------- Setters -------------------

///Establecer anioFallecimiento
///
/// \param anioFallecimiento
void ArchivoEscritores::establecerAnioFallecimiento(int anioFallecimiento_){
    anioFallecimiento = anioFallecimiento_;
}

///Establecer nombreApellido
///
/// \param nombreApellido
void ArchivoEscritores::establecerNombreApellido(string nombreApellido_){
    nombreApellido = move(nombreApellido_);
}

///Establecer nacionalidad
///
/// \param nacionalidad
void ArchivoEscritores::establecerNacionalidad(string nacionalidad_){
    this -> nacionalidad = move(nacionalidad_);
}

///Establecer anioNacimiento
///
/// \param anioNacimiento
void ArchivoEscritores::establecerAnioNacimiento(int anioNacimiento_){
    anioNacimiento = anioNacimiento_;
}

///------------------- Getters -------------------

///ObtenerNombreApellido
///
/// \return string
string ArchivoEscritores::obtenerNombreApellido(){
    return nombreApellido;
}
