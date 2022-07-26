#include "ProcesarArchivos.h"


/// ------------------- Constructor -------------------

///Constructor
ProcesarArchivos::ProcesarArchivos() {
    texto = TEXTO_VACIO;
    indice = 1;
}

/// ------------------- Metodos Generales -------------------


///Indice reiniciado
///
/// \return bool
bool ProcesarArchivos::indiceReiniciado() const {
    return (indice == 1);
}

///Cerrar archivo
///
/// \return bool
void ProcesarArchivos::cerrarArchivo(){
    archivo.close();
}

///Archivo finalizado
///
/// \return bool
bool ProcesarArchivos::archivoFinalizado() {
    return (archivo.eof());
}

///Leer linea
void ProcesarArchivos::leerLinea(){
    string lineaLeida;
    getline(archivo,lineaLeida);

    establecerTexto(lineaLeida);
}

/// ------------------- Setters -------------------

///Establecer texto
///
/// \param texto
void ProcesarArchivos::establecerTexto(string texto_) {
    texto = move(texto_);
}
