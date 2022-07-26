#include "Cuento.h"

/// ------------------- Constructor -------------------

///Constructor
///
/// \param libro_
/// \param titulo
/// \param minutos
/// \param anioPublicacion
/// \param autor
Cuento::Cuento (string libro_, string titulo, int minutos, int anioPublicacion, Escritor* autor) :
        Lectura (move(titulo), minutos, anioPublicacion, autor) {
    libro = move(libro_);
}

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
void Cuento::mostrar () {
    cout << "\n" <<INICIAL<<AZUL<< "——————————————————————————————————————————————————————————————————" <<FINAL << "\n" << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Cuento: " <<FINAL << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Titulo: " <<FINAL << obtenerTitulo() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Minutos de lectura: " <<FINAL << obtenerMinutos() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Anio de publicacion: " <<FINAL << obtenerAnioPublicacion() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Titulo de publicacion: " <<FINAL << obtenerLibro() << endl;
    mostrarAutor();

}

/// ------------------- Getters -------------------

///Obtener libro
///
/// \return string
string Cuento::obtenerLibro () {
    return libro;
}
