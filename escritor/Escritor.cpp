#include "Escritor.h"

/// ------------------- Constructor -------------------

///Constructor
///
/// \param nombreApellido
/// \param nacionalidad
/// \param anioNacimiento
/// \param anioFallecimiento
Escritor::Escritor (string nombreApellido_, string nacionalidad_, int anioNacimiento_, int anioFallecimiento_) {
    nombreApellido = move(nombreApellido_);
    nacionalidad = move(nacionalidad_);
    anioNacimiento = anioNacimiento_;
    anioFallecimiento = anioFallecimiento_;
}

/// ------------------- Metodos Generales -------------------

///Mostrar Escritor
void Escritor::mostrar () {
    cout << INICIAL<<BRILLANTE<<CIAN<< "Autor: " <<FINAL << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Nombre y apellido: " <<FINAL << obtenerNombreApellido() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Nacionalidad: " <<FINAL << obtenerNacionalidad() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Anio nacimiento: " <<FINAL << obtenerAnioNacimiento() << endl;
    cout << INICIAL<<BRILLANTE<<CIAN<< "Anio fallecimiento: " <<FINAL << obtenerAnioFallecimiento() << endl;
    cout << "\n";
}

/// ------------------- Setters -------------------

///Modificar fallecimiento
///
/// \param anioFallecimiento
void Escritor::modificarFallecimiento (int anioFallecimiento_) {
    anioFallecimiento = anioFallecimiento_;
}

///------------------- Getters -------------------

///Obtener nombre y apellido
///
/// \return string
string Escritor::obtenerNombreApellido() {
    return nombreApellido;
}

///Obtener nacionalidad
///
/// \return string
string Escritor::obtenerNacionalidad() {
    return nacionalidad;
}

///Obtener anio de nacimiento
///
/// \return string
int Escritor::obtenerAnioNacimiento() const {
    return anioNacimiento;
}

///Obtener anio de fallecimineto
///
/// \return string
int Escritor::obtenerAnioFallecimiento() const {
    return anioFallecimiento;
}