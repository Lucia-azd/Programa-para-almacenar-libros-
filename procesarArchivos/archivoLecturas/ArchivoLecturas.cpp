#include "ArchivoLecturas.h"

/// ------------------- Constructor -------------------

///Construcctor
///
/// \param listaEscritores
ArchivoLecturas::ArchivoLecturas(Lista<Escritor*>* listaEscritores_) : ProcesarArchivos(){
    listaEscritores = listaEscritores_;
    tipoLectura = TEXTO_VACIO;
    titulo = TEXTO_VACIO;
    subtema = TEXTO_VACIO;
    auxiliarReferencia = TEXTO_VACIO;

    descripcion = nullptr;
    autor = nullptr;

    minutosLectura = DATO_VACIO;
    anio = DATO_VACIO;
    referencia = DATO_VACIO;
    genero = DATO_VACIO;
}

/// ------------------- Metodos Generales -------------------

///Apertura archivo
void ArchivoLecturas::aperturaArchivo() {

    archivo.open(RUTA_LECTURAS, ios::in);

    if (archivo.fail()) {
        cout<< INICIAL<<COLOR_ERROR<<"No se pudo abrir el archivo"<<FINAL << endl;
        exit(1);
    }
}

///ProcesarDatos
void ArchivoLecturas::procesarDatos() {

    switch (indice) {
        case INDICE_TIPO_LECTURA:
            tipoLectura = texto;
            break;
        case INDICE_TITULO:
            titulo = texto;
            break;
        case INDICE_MINUTOS_LECTURA:
            minutosLectura = stoi(texto);
            break;
        case INDICE_ANIO_PUBLICACION:
            anio = stoi(texto);
            break;
        case INDICE_SUBTEMA:
            establecerSubtema(texto);
            if (subtema == NOVELA_HISTORICA) {
                getline(archivo, texto);
                establecerDescripcion(texto);
            }
            break;
        case INDICE_AUTOR:
            if (texto == AUTOR_ANONIMO){
                autor = nullptr;
            } else {
                convertirReferencia();
                asignarAutor();
            }
            break;
        default:
            indice = 0;
    }
    indice++;
}

///Convertir genero
void ArchivoLecturas::convertirGenero(){
    if (subtema == "DRAMA"){
        genero = genero::DRAMA;
    } else if (subtema == "COMEDIA"){
        genero = genero::COMEDIA;
    } else if(subtema == "FICCION"){
        genero = genero::FICCION;
    } else if(subtema == "SUSPENSO"){
        genero = genero::SUSPENSO;
    } else if(subtema == "TERROR"){
        genero = genero::TERROR;
    } else if(subtema == "ROMANTICA"){
        genero = genero::ROMANTICA;
    } else {
        genero = genero::HISTORICA;
    }
}


///Crear Poema
///
/// \return Poema*
Poema* ArchivoLecturas::crearPoema() {
    return new Poema(stoi(subtema), titulo, minutosLectura, anio, autor);
}

///Crear Cuento
///
/// \return Cuento*
Cuento* ArchivoLecturas::crearCuento() {
    return new Cuento(subtema, titulo, minutosLectura, anio, autor);
}

///Crear Novela
///
/// \return Novela*
Novela* ArchivoLecturas::crearNovela() {
    convertirGenero();
    return new Novela(genero, titulo, minutosLectura, anio, autor);
}

///Crear NovelaHistorica
///
/// \return NovelaHistorica*
NovelaHistorica* ArchivoLecturas::crearNovelaHistorica() {
    convertirGenero();
    return new NovelaHistorica (descripcion, genero, titulo, minutosLectura, anio, autor);
}

///Crear Lectura
///
/// \return Lectura*
Lectura* ArchivoLecturas::crearLectura() {
    Lectura* lectura;
    if (tipoLectura == POEMA) {
        lectura = crearPoema();
    } else if (tipoLectura == CUENTO) {
        lectura = crearCuento();
    } else {
        if (subtema == NOVELA_HISTORICA) {
            lectura = crearNovelaHistorica();
        } else {
            lectura = crearNovela();
        }
    }
    return lectura;
}

///Convertir referencia
void ArchivoLecturas::convertirReferencia() {
    auxiliarReferencia = texto[1];
    if (texto[2] != ')'){
        auxiliarReferencia += texto[2];
    }
    establecerReferencia(stoi(auxiliarReferencia));
}

///Asignar autor
void ArchivoLecturas::asignarAutor(){
    autor = listaEscritores -> consulta(referencia);
}

///Procesar archivoLecturas
///
/// \param listaLecturas
Lista<Lectura*> ArchivoLecturas::procesarArchivoLecturas(){

    Lista<Lectura*> listaLecturas;

    aperturaArchivo();

    while (!archivoFinalizado()){
        leerLinea();
        procesarDatos();

        if (indiceReiniciado()){
            listaLecturas.altaOrdenada(crearLectura(), true);
        }
    }
    cerrarArchivo();

    return listaLecturas;
}

/// ------------------- Setters -------------------

///Establecer referencia
///
/// \param referencia_
void ArchivoLecturas::establecerReferencia(int referencia_) {
    referencia = referencia_;
}

///Establecer tipo Lectura
///
/// \param tipoLectura_
void ArchivoLecturas::establecerTipoLectura(string tipoLectura_) {
    tipoLectura = move(tipoLectura_);
}

///Establecer titulo
///
/// \param titulo_
void ArchivoLecturas::establecerTitulo(string titulo_) {
    titulo = move(titulo_);
}

///Establecer subtema
///
/// \param subtema_
void ArchivoLecturas::establecerSubtema(string subtema_) {
    subtema = move(subtema_);
}

///Establecer descripcion
///
/// \param descripcion_
void ArchivoLecturas::establecerDescripcion(string descripcion_){

    long unsigned int longitudDescripcion = descripcion_.length();

    descripcion = new char[longitudDescripcion + 2];

    for(int i = 0; i < int(longitudDescripcion); i++){
        descripcion[i] = descripcion_[i];
    }
    descripcion[longitudDescripcion] = '\0';
}

///Establecer autor
///
/// \param autor_
void ArchivoLecturas::establecerAutor(Escritor* autor_){
    autor = autor_;
}

///Establecer minutosLectura
///
/// \param minutosLectura_
void ArchivoLecturas::establecerMinutosLectura(int minutosLectura_){
     minutosLectura = minutosLectura_;
}

///Establecer anio
///
/// \param anio_
void ArchivoLecturas::establecerAnio(int anio_){
    anio = anio_;
}

///------------------- Getters -------------------

///Obtener tipo lectura
///
/// \return string
string ArchivoLecturas::obtenerTipoLectura(){
    return tipoLectura;
}