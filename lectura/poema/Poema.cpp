#include "Poema.h"

/// ------------------- Constructor -------------------

///Constructor
///
/// \param versos_
/// \param titulo
/// \param minutos
/// \param anioPublicacion
/// \param autor
Poema::Poema (int versos_, string titulo, int minutos, int anioPublicacion, Escritor* autor) :
    Lectura (move(titulo), minutos, anioPublicacion, autor) {
    versos = versos_;
}

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
void Poema::mostrar () {
    cout << "\n" <<INICIAL<<AZUL<< "——————————————————————————————————————————————————————————————————" <<FINAL << "\n" << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Poema: " <<FINAL << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Titulo: " <<FINAL << obtenerTitulo() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Minutos de lectura: " <<FINAL << obtenerMinutos() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Anio de publicacion: " <<FINAL << obtenerAnioPublicacion() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<<"Cantidad de versos: " <<FINAL << obtenerVersos() << endl;
    mostrarAutor();
}

/// ------------------- Getters -------------------

///Obtener versos
///
/// \return int
int Poema::obtenerVersos() const {
    return versos;
}