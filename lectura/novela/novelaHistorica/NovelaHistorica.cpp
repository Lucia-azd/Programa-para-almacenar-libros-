#include "NovelaHistorica.h"

/// ------------------- Constructor y Destructor -------------------

///Constructor
///
/// \param tema_
/// \param genero
/// \param titulo
/// \param minutos
/// \param anioPublicacion
/// \param autor
NovelaHistorica::NovelaHistorica(char* tema_, int genero, string titulo, int minutos, int anioPublicacion, Escritor *autor) :
        Novela (genero, move(titulo), minutos, anioPublicacion, autor) {
    tema = tema_;
}

///Destructor
///
///
NovelaHistorica::~NovelaHistorica() {
    delete [] tema;
}

/// ------------------- Metodos Generales -------------------

///Mostrar lectura
void NovelaHistorica::mostrar () {
    cout << "\n" <<INICIAL<<AZUL<< "——————————————————————————————————————————————————————————————————" <<FINAL << "\n" << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Novela Historica: " <<FINAL << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Titulo: " <<FINAL << obtenerTitulo() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Minutos de lectura: " <<FINAL << obtenerMinutos() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Anio de publicacion: " <<FINAL << obtenerAnioPublicacion() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Genero: " <<FINAL; mostrarGenero(); cout << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Tema: " <<FINAL << obtenerTema() << endl;
    mostrarAutor();
}

/// ------------------- Getters -------------------

///Obtener tema
///
/// \return char*
char* NovelaHistorica::obtenerTema (){
    return tema;
}

