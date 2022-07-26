#include "Novela.h"

/// ------------------- Constructor -------------------

///Constructor
///
/// \param genero_
/// \param titulo
/// \param minutos
/// \param anioPublicacion
/// \param autor
Novela::Novela (int genero_, string titulo, int minutos, int anioPublicacion, Escritor* autor) :
        Lectura (move(titulo), minutos, anioPublicacion, autor) {
    genero = genero_;
}

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
void Novela::mostrar () {
    cout << "\n" <<INICIAL<<AZUL<< "——————————————————————————————————————————————————————————————————" <<FINAL << "\n" << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Novela: " <<FINAL << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Titulo: " <<FINAL << obtenerTitulo() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Minutos de lectura: " <<FINAL << obtenerMinutos() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Anio de publicacion: " <<FINAL << obtenerAnioPublicacion() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Genero: " <<FINAL; mostrarGenero(); cout << endl;
    mostrarAutor();
}

///Mostrar generos
void Novela::mostrarGenero() const {
    switch (genero) {
        case genero::DRAMA: cout << "Drama"; break;

        case genero::COMEDIA: cout << "Comedia"; break;

        case genero::FICCION: cout << "Ficcion"; break;

        case genero::SUSPENSO: cout << "Suspenso"; break;

        case genero::TERROR: cout << "Terror"; break;

        case genero::ROMANTICA: cout << "Romantica"; break;

        case genero::HISTORICA: cout << "Historica"; break;
    }
}

/// ------------------- Getters -------------------

///Obtener genero
///
/// \return int
int Novela::obtenerGenero () const {
    return genero;
}
