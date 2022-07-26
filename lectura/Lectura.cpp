#include "Lectura.h"

/// ------------------- Constructor -------------------

///Constructor
///
/// \param titulo
/// \param minutos
/// \param anioPublicacion
/// \param autor
Lectura::Lectura(string titulo_, int minutos_, int anioPublicacion_, Escritor* autor_) {
    titulo = move(titulo_);
    minutos = minutos_;
    anioPublicacion = anioPublicacion_;
    autor = autor_;
}

/// ------------------- Metodos Generales -------------------

///Mostrar autor
void Lectura::mostrarAutor(){
    if ( !autor ){
        cout << INICIAL<<BRILLANTE<<CIAN<< "Autor:\n" <<FINAL << AUTOR_ANONIMO << "\n" << endl;
    }else{
        autor->mostrar();
    }
}

/// ------------------- Getters -------------------

///Obtener titulo
///
/// \return string
string Lectura::obtenerTitulo() {
    return titulo;
}

///Obtener minutos de lectura
///
/// \return int
int Lectura::obtenerMinutos() const {
    return minutos;
}

///Obtener anio de publicacion
///
/// \return int
int Lectura::obtenerAnioPublicacion() const {
    return anioPublicacion;
}

///Obtener autor
///
/// \return Escritor*
Escritor* Lectura::obtenerAutor() {
    return autor;
}