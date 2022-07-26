#include "Menu.h"

/// ------------------- Constructor -------------------

///Constructor
///
/// \param listaLecturas
/// \param listaEscritores
Menu::Menu (Lista<Lectura*>* listaLecturas, Lista<Escritor*>* listaEscritores){
    this -> listaLecturas = listaLecturas;
    this -> listaEscritores = listaEscritores;
    datoUsuario = TEXTO_VACIO;
    opcion = DATO_VACIO;
    operacionExitosa = false;
    datoEncontrado = false;
    escritorActual = nullptr;
    lecturaActual = nullptr;
}

/// ------------------- Metodos Generales -------------------

/// ---------------------------- SECCION MENU GENERAL ----------------------------

///Mostrar Menu
void Menu::mostrarMenu (){
    cout << INICIAL<<BRILLANTE<<MAGENTA<< "       Menú       -      Ingrese la opción deseada:" <<FINAL << "\n" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::AGREGAR_LECTURA << "  - " <<FINAL << " Agregar una lectura" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::QUITAR_LECTURA << "  - " <<FINAL << " Quitar una lectura" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::AGREGAR_ESCRITOR << "  - " <<FINAL << " Agregar un escritor" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::CAMBIAR_FALLECIMIENTO_ESCRITOR << "  - " <<FINAL << " Modificar año de fallecimiento de un escritor" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::LISTAR_ESCRITORES << "  - " <<FINAL << " Mostrar todos los escritores" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::SORTEAR_LECTURA << "  - " <<FINAL << " Elegir una lectura aleatoria" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::LISTAR_LECTURAS << "  - " <<FINAL << " Mostrar todas las lecturas" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::LISTAR_LECTURAS_ANIOS << "  - " <<FINAL << " Mostrar las lecturas publicadas entre determinados años" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::LISTAR_LECTURAS_ESCRITOR << "  - " <<FINAL << " Mostrar las lecturas de un determinado escritor" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::LISTAR_NOVELAS_GENERO << " -  " <<FINAL << "Mostrar las novelas de un determinado genero" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::ARMAR_COLA << " -  " <<FINAL << "Armar una cola ordenada por tiempo de lectura (menor a mayor)" << endl;

    cout << INICIAL<<COLOR_OPCION<< opcion::SALIR << " -  " <<FINAL << "Salir" << endl;

    cout << "\n" << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
    cin >> opcion;

    opcionUsuario();
}

///Mensaje Exito
void Menu::mensajeExito(){
    cout << "\n" <<INICIAL<<AZUL<< "——————————————————————————————————————————————————————————————————" <<FINAL << "\n" << endl;
    cout <<INICIAL<<COLOR_EXITO << "Éxito! seleccione otra opción o coloque 12 para salir" <<FINAL << "\n" << endl;
}

///Mensaje Error
void Menu::mensajeError(string error){
    cout << "\n" <<INICIAL<<AZUL<< "——————————————————————————————————————————————————————————————————" <<FINAL << "\n" << endl;
    cout << "\n" <<INICIAL<<COLOR_ERROR << " Error! " << error << " - seleccione otra opción o coloque 12 para salir" <<FINAL << "\n" << endl;
}

///Verificar operacion
///
/// \param error
void Menu::verificarOperacion(string error){
    if ( operacionExitosa ){
        mensajeExito();
    }else{
        mensajeError(move(error));
    }
    operacionExitosa = false;
    datoEncontrado = false;
}

///Opcion usuario
void Menu::opcionUsuario(){
    switch (opcion) {
        case opcion::AGREGAR_LECTURA:
            agregarLectura();
            verificarOperacion("");
            break;
        case opcion::QUITAR_LECTURA:
            quitarLectura();
            verificarOperacion("La lista de lecturas esta vacia o esa lectura no existe");
            break;
        case opcion::AGREGAR_ESCRITOR:
            agregarEscritor();
            verificarOperacion("");
            break;
        case opcion::CAMBIAR_FALLECIMIENTO_ESCRITOR:
            modificarEscritor();
            verificarOperacion("No existe un escritor con ese nombre y apellido");
            break;
        case opcion::LISTAR_ESCRITORES:
            listarEscritores();
            verificarOperacion("No hay escritores para mostrar. Seleccione la opción de 'agregar escritor' si desea agregar uno");
            break;
        case opcion::SORTEAR_LECTURA:
            sortearLectura();
            verificarOperacion("No hay lecturas para mostrar. Seleccione la opción de 'agregar lectura' si desea agregar uno");
            break;
        case opcion::LISTAR_LECTURAS:
            listarLecturas();
            verificarOperacion("No hay lecturas para mostrar. Seleccione la opción de 'agregar lectura' si desea agregar uno");
            break;
        case opcion::LISTAR_LECTURAS_ANIOS:
            listarLecturasAnios();
            verificarOperacion("No existen las lecturas entre esos años");
            break;
        case opcion::LISTAR_LECTURAS_ESCRITOR:
            listarLecturasEscritor();
            verificarOperacion("No existen las lecturas de ese escritor");
            break;
        case opcion::LISTAR_NOVELAS_GENERO:
            listarNovelasGenero();
            verificarOperacion("No existen las lecturas de ese genero de novelas");
            break;
        case opcion::ARMAR_COLA:
            armarCola();
            verificarOperacion("");
            break;
        case opcion::SALIR:
            Salir();
            break;
        default:
            mensajeError("Opción seleccionada inexistente. "
                         "Por favor seleccione una opción de las que figuran en pantalla");
    }
}

///Obtener opcion
///
/// \return int
int Menu::obtenerOpcion() const {
    return opcion;
}

/// ---------------------------- SECCION MENU LECTURAS ----------------------------

/// --------->>> AGREGAR LECTURA

///Pedir descripcion
void Menu::pedirDescripcion(){
    cout << "\n" <<INICIAL<<SUBRAYADO <<"Coloque el tema de la Novela Historica:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
    cin.ignore();
    getline(cin, datoUsuario);
    lectura.establecerDescripcion(datoUsuario);
}

///Pedir subtema
void Menu::pedirSubtema() {
    if (lectura.obtenerTipoLectura() == NOVELA) {
        pedirGenero();

    } else if (lectura.obtenerTipoLectura() == "C") {
        cout << "\n" <<INICIAL<<SUBRAYADO <<"Coloque el título del libro en donde está publicado el Cuento:" <<FINAL<< endl;
        cout << INICIAL<<BRILLANTE<<MAGENTA <<"——> " <<FINAL;
        cin.ignore();
        getline(cin, datoUsuario);
        lectura.establecerSubtema(datoUsuario);

    }else {
        cout << "\n" <<INICIAL<<SUBRAYADO <<"Coloque la cantidad de versos del Poema:" <<FINAL << endl;
        cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
        cin.ignore();
        getline(cin, datoUsuario);
        lectura.establecerSubtema(datoUsuario);
    }
}

///Pedir genero
void Menu::pedirGenero(){
    do{
    cout << "\n" <<INICIAL<<SUBRAYADO <<"Seleccione el numero correspondiente al genero de la Novela:" <<FINAL << endl;
    mostrarGeneros();
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> opcion;
    if (opcion < genero::DRAMA || opcion > genero::HISTORICA){
        cout <<INICIAL<<COLOR_ERROR << "Por favor, ingrese una opcion valida." <<FINAL << endl;
    }
    } while(opcion < genero::DRAMA || opcion > genero::HISTORICA);

    switch (opcion) {
        case genero::DRAMA: lectura.establecerSubtema("DRAMA"); break;
        case genero::COMEDIA: lectura.establecerSubtema("COMEDIA"); break;
        case genero::FICCION: lectura.establecerSubtema("FICCION"); break;
        case genero::SUSPENSO: lectura.establecerSubtema("SUSPENSO"); break;
        case genero::TERROR: lectura.establecerSubtema("TERROR"); break;
        case genero::ROMANTICA: lectura.establecerSubtema("ROMANTICA"); break;
        case genero::HISTORICA: lectura.establecerSubtema("HISTORICA");
            pedirDescripcion(); break;
        default: break;
    }
}

///Pedir Lectura
void Menu::pedirTipoLectura(){
    do {
    cout <<INICIAL<<SUBRAYADO << "Tipo de lectura. Por favor seleccione el numero correspondiente:" <<FINAL << endl;
    cout << INICIAL<<COLOR_OPCION<< "1. " <<FINAL<< "Novela" << endl;
    cout << INICIAL<<COLOR_OPCION<< "2. " <<FINAL<< "Cuento" << endl;
    cout << INICIAL<<COLOR_OPCION<< "3. " <<FINAL<< "Poema" << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> opcion;
    if (opcion < tipo_lectura_opcion::TIPO_NOVELA || opcion > tipo_lectura_opcion::TIPO_POEMA){
        cout <<INICIAL<<COLOR_ERROR<< "Por favor, ingrese una opcion valida." <<FINAL <<endl;
    }} while (opcion < tipo_lectura_opcion::TIPO_NOVELA || opcion > tipo_lectura_opcion::TIPO_POEMA);

    switch (opcion) {
        case tipo_lectura_opcion::TIPO_NOVELA:
            lectura.establecerTipoLectura(NOVELA);
            break;
        case tipo_lectura_opcion::TIPO_CUENTO:
            lectura.establecerTipoLectura(CUENTO);
            break;
        case tipo_lectura_opcion::TIPO_POEMA:
            lectura.establecerTipoLectura(POEMA);
            break;

        default:
            cout <<INICIAL<<COLOR_ERROR<< "Por favor, ingrese una opcion valida." <<FINAL <<endl;
            break;
    }
}

///Pedir datos lectura
void Menu::pedirDatosLectura(){
    cout <<INICIAL<<BRILLANTE<<AMARILLO << "Ingrese los datos de la lectura a agregar y de su escritor:" <<FINAL << endl;

    cout <<INICIAL<<SUBRAYADO <<"Titulo:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
    cin.ignore();
    getline(cin, datoUsuario);
    lectura.establecerTitulo(datoUsuario);

    pedirTipoLectura();

    pedirSubtema();

    cout <<INICIAL<<SUBRAYADO <<"Minutos estimados para su lectura:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
    lectura.establecerMinutosLectura(stoi(datoUsuario));

    cout <<INICIAL<<SUBRAYADO <<"Año de su publicación:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
    lectura.establecerAnio(stoi(datoUsuario));
}

void Menu::verificarEscritorAnonimo(){
    cout <<INICIAL<<SUBRAYADO<< "¿Es el escritor de la lectura ANONIMO? Ingrese el numero correspondiente: "<< FINAL<<endl;
    cout <<INICIAL<<COLOR_OPCION<< "1. " <<FINAL <<"Si\n" <<INICIAL<<COLOR_OPCION<< "2. " <<FINAL << "No" << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
}

///Agregar Lectura
void Menu::agregarLectura(){
    pedirDatosLectura();

    do { verificarEscritorAnonimo();
    } while (datoUsuario != ACEPTAR && datoUsuario != RECHAZAR);

    if (datoUsuario == RECHAZAR){
        agregarEscritor();}
    else {
        escritorActual = nullptr;
    }

    lectura.establecerAutor(escritorActual);
    listaLecturas->altaOrdenada(lectura.crearLectura(), true);
    operacionExitosa = true;
}

/// --------->>> QUITAR LECTURA

///Quitar Lectura
void Menu::quitarLectura(){

    if ( !listaLecturas->vacia() ){
        string titulo;
        int anio;

        cout <<INICIAL<<SUBRAYADO<< "Ingrese el titulo de la lectura que desea eliminar:" <<FINAL << endl;
        cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
        cin.ignore();
        getline(cin, titulo);

        cout <<INICIAL<<SUBRAYADO<< "Ingrese el año en que fue publicado la lectura a eliminar:" <<FINAL << endl;
        cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> anio;

        listaLecturas->bajaOrdenada( anio, titulo );
        operacionExitosa = true;
    }
}

/// --------->>> SORTEAR LECTURA

///Sortear Lectura
void Menu::sortearLectura(){
    if ( !listaLecturas->vacia() ) {
        int desde = 1;

        srand((unsigned int)time(nullptr));
        int posicion = rand() % (listaLecturas->obtenerCantidad() - desde + 1) + desde;

        listaLecturas->consulta(posicion)->mostrar();

        operacionExitosa = true;
    }
}

///--------->>> LISTAR LECTURAS

///Listar Lecturas
void Menu::listarLecturas() {
    if ( !listaLecturas->vacia() ){
        listaLecturas->mostrarElementos();
        operacionExitosa = true;
    }
}

/// --------->>> LISTAR LECTURAS POR ANIO

///Listar Lecturas por anio
void Menu::listarLecturasAnios(){
    int anioHasta;
    int anioDesde;

    cout <<INICIAL<<CIAN<< "Ingrese desde que año de publicación son las lecturas que quiere ver:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> anioDesde;

    cout <<INICIAL<<CIAN<< "Ingrese hasta que año de publicación son las lecturas que quiere ver:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> anioHasta;

    if( !listaLecturas->vacia() ) {
        listaLecturas->listarIntervalo(anioDesde, anioHasta);
        operacionExitosa = true;
    }
}

/// --------->>> LISTAR LECTURAS POR ESCRITOR

///Listar Lecturas por Escritor
void Menu::listarLecturasEscritor(){
    cout <<INICIAL<<SUBRAYADO<< "Ingrese el nombre y apellido del escritor que quiere ver sus lecturas:" <<FINAL<< endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
    cin.ignore();
    getline(cin, datoUsuario);

    if( !listaLecturas->vacia() ){
        listaLecturas->reiniciarCursor();

        for (int i = 1; i <= listaLecturas->obtenerCantidad(); i++){
            lecturaActual = listaLecturas->iterarLista();
            escritorActual = lecturaActual->obtenerAutor();

            string nombreApellidoActual = escritorActual ? escritorActual->obtenerNombreApellido() : AUTOR_ANONIMO;


            if ( datoUsuario == nombreApellidoActual){
                lecturaActual->mostrar();
                operacionExitosa = true;
            }
        }
    }
}

/// --------->>> LISTAR LECTURAS POR NOVELA

///Mostrar generos
void Menu::mostrarGeneros() {
    cout <<INICIAL<<COLOR_OPCION<< genero::DRAMA <<FINAL << " - DRAMA" <<endl;
    cout <<INICIAL<<COLOR_OPCION<< genero::COMEDIA <<FINAL << " - COMEDIA" <<endl;
    cout <<INICIAL<<COLOR_OPCION<< genero::FICCION <<FINAL << " - FICCION" <<endl;
    cout <<INICIAL<<COLOR_OPCION<< genero::SUSPENSO <<FINAL << " - SUSPENSO" <<endl;
    cout <<INICIAL<<COLOR_OPCION<< genero::TERROR <<FINAL << " - TERROR" <<endl;
    cout <<INICIAL<<COLOR_OPCION<< genero::ROMANTICA <<FINAL << " - ROMANTICA" <<endl;
    cout <<INICIAL<<COLOR_OPCION<< genero::HISTORICA <<FINAL << " - HISTORICA" <<endl;
}

///Listar Novelas por genero
void Menu::listarNovelasGenero(){
    cout <<INICIAL<<SUBRAYADO<< "Elija el NUMERO que corresponda al genero de las novelas que quiere ver:" <<FINAL << endl;

    mostrarGeneros();
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;cin >> datoUsuario;

    if( !listaLecturas -> vacia() ) {
        listaLecturas -> reiniciarCursor();
        for (int i = 1; i <= listaLecturas -> obtenerCantidad(); i++) {
            lecturaActual = listaLecturas -> iterarLista();

            if ( stoi(datoUsuario) == ((Novela *) lecturaActual) -> obtenerGenero() ){
                lecturaActual -> mostrar();
                operacionExitosa = true;
            }
        }
    }
}

/// ---------------------------- SECCION MENU ESCRITORES ----------------------------

/// --------->>> AGREGAR ESCRITOR

///Buscar Escritor
void Menu::buscarEscritor(){
    int contador = 1;
    listaEscritores->reiniciarCursor();

    while ( contador <= listaEscritores->obtenerCantidad() && !datoEncontrado ){
        escritorActual = listaEscritores->iterarLista();
        if(escritorActual->obtenerNombreApellido() == escritor.obtenerNombreApellido()){
            datoEncontrado = true;
        }else {
            escritorActual = nullptr;
            contador++;
        }
    }
}

///Pedir datos Escritor
void Menu::pedirDatosEscritor(){
    cout <<INICIAL<<SUBRAYADO<< "Nacionalidad:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
    escritor.establecerNacionalidad(datoUsuario);

    cout <<INICIAL<<SUBRAYADO<< "Año de nacimiento:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
    escritor.establecerAnioNacimiento(stoi(datoUsuario));

    cout <<INICIAL<<SUBRAYADO<< "Año de fallecimiento:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
    escritor.establecerAnioFallecimiento(stoi(datoUsuario));
}

///Agregar Escritor
void Menu::agregarEscritor(){

    cout <<INICIAL<<BRILLANTE<<AMARILLO<< "Ingrese los datos del escritor a agregar:" <<FINAL << endl;
    cout <<INICIAL<<SUBRAYADO<< "Nombre y apellido:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
    cin.ignore();
    getline(cin, datoUsuario);
    escritor.establecerNombreApellido(datoUsuario);

    buscarEscritor();

    if ( !escritorActual ) {
        pedirDatosEscritor();
        escritorActual = escritor.crearEscritor();
        listaEscritores->alta(escritorActual);
    } else {
        cout <<INICIAL<<BRILLANTE<<CIAN<< "Escritor ya existente!" <<FINAL<< endl;
    }
    operacionExitosa = true;
}

/// --------->>> MODIFICAR ESCRITOR

///Tiene anio de fallecimiento
///
/// \return bool
bool Menu::tieneAnioFallecimiento(){
    return escritorActual->obtenerAnioFallecimiento() != DATO_VACIO;
}

///Confirmar cambio de fallecimiento
void Menu::confirmarCambioFallecimiento() {

    bool opcionErronea = false;

    do {
        if (opcionErronea) cout << "\nSeleccione una opcion valida por favor. (Coloque el numero correspondiente a su eleccion)" << endl;

        cout <<INICIAL<<SUBRAYADO<< "Ese escritor ya tiene un anio de fallecimiento ¿quiere modificarlo igual?:" <<FINAL <<endl;
        cout <<INICIAL<<COLOR_OPCION<< "1. " <<FINAL <<"Si\n" <<INICIAL<<COLOR_OPCION<< "2. " <<FINAL << "No" << endl;
        cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;
        opcionErronea = true;

    } while (datoUsuario != ACEPTAR && datoUsuario != RECHAZAR);

    if ( datoUsuario == ACEPTAR  ) modificarAnio();
}

///Modificar anio de fallecmiento
void Menu::modificarAnio() {
    cout <<INICIAL<<SUBRAYADO<< "Ingrese el nuevo año de fallecimiento:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;

    escritorActual->modificarFallecimiento(stoi(datoUsuario));
}

///Modificar Escritor
void Menu::modificarEscritor(){

    cout <<INICIAL<<SUBRAYADO<< "Ingrese el nombre y apellido del escritor que quiere modificar:" <<FINAL << endl;
    cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL;
    cin.ignore();
    getline(cin, datoUsuario);
    escritor.establecerNombreApellido(datoUsuario);
    buscarEscritor();

    if ( escritorActual != nullptr ){
        tieneAnioFallecimiento() ? confirmarCambioFallecimiento() : modificarAnio();
        operacionExitosa = true;
    }
}

/// --------->>> LISTAR ESCRITORES

///Listar Escritores
void Menu::listarEscritores(){
    if ( !listaEscritores->vacia() ) {
        listaEscritores->mostrarElementos();
        operacionExitosa = true;
    }
}

/// ---------------------------- SECCION ARMAR COLA ----------------------------

///Armar Cola
void Menu::armarCola(){

    Cola<Lectura*> colaLecturas;
    Lista<Lectura*> listaParaCola;
    listaLecturas->reiniciarCursor();

    for (int i = 1; i <= listaLecturas->obtenerCantidad(); i++) {
        lecturaActual = listaLecturas->iterarLista();
        lecturaActual->mostrar();
        menuLecturaLeida();

        if (datoUsuario == LECTURA_NO_LEIDA){
            listaParaCola.altaOrdenada(lecturaActual, false);
        }
    }

    while (!listaParaCola.vacia()){
        colaLecturas.alta(listaParaCola.datoPrimero());
        listaParaCola.baja();
    }

    Cola<Lectura*>* colaLecturasRef = &colaLecturas;
    menuCola(colaLecturasRef);
    operacionExitosa = true;
}

///Menu lectura leida
void Menu::menuLecturaLeida(){
    bool opcionErronea = false;

    do {
        if (opcionErronea) cout <<INICIAL<<COLOR_ERROR<< "Seleccione una opcion valida por favor." <<FINAL << endl;

        cout <<INICIAL<<SUBRAYADO<< "¿Usted leyó la lectura? Coloque el numero correspondiente:" <<FINAL << endl;
        cout <<INICIAL<<COLOR_OPCION << "1." <<FINAL << " Si" << endl;
        cout <<INICIAL<<COLOR_OPCION << "2." <<FINAL << " No" << endl;
        cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> datoUsuario;

        opcionErronea = true;

    } while (datoUsuario != LECTURA_LEIDA && datoUsuario != LECTURA_NO_LEIDA);
}

///Menu Cola
///
/// \param colaLecturas
void Menu::menuCola(Cola<Lectura*>* &colaLecturas) {
    cout <<INICIAL<<COLOR_EXITO<< "Cola creada con exito!" <<FINAL << endl;

    while (opcion != menu_cola::VOLVER_MENU_GENERAL){
        opcionesCola();
        cout << INICIAL<<COLOR_FLECHA<< "——> " <<FINAL; cin >> opcion;

        switch (opcion) {
            case menu_cola::MOSTRAR_ELEMENTO:
                if (!colaLecturas->vacia()) {
                    colaLecturas->consulta()->mostrar();
                } else {
                    cout <<INICIAL<<COLOR_ERROR<< "No se encuentran elementos para mostrar!" <<FINAL <<endl;
                }
                break;
            case menu_cola::ELIMINAR_ELEMENTO:
                if (!colaLecturas->vacia()){
                    colaLecturas->baja();
                } else {
                    cout <<INICIAL<<COLOR_ERROR<< "No se encontraron elementos para eliminar!" <<FINAL << endl;
                }
                break;
            case menu_cola::VOLVER_MENU_GENERAL:
                break;
            default:
                cout <<INICIAL<<COLOR_ERROR<< "Opcion invalida. Por favor seleccione una opcion valida:" <<FINAL << endl;
                break;
        }
    }
}

///Opciones Cola
void Menu::opcionesCola(){
    cout << "\n" <<INICIAL<<SUBRAYADO<< "Por favor, seleccione una opcion:" <<FINAL << endl;
    cout <<INICIAL<<COLOR_OPCION<< "1."<<FINAL <<" Mostrar primer elemento." << endl;
    cout <<INICIAL<<COLOR_OPCION<< "2."<<FINAL <<" Primer elemento ya fue leido." << endl;
    cout <<INICIAL<<COLOR_OPCION<< "3."<<FINAL <<" Volver al Menu" << endl;
}

/// ---------------------------- SECCION SALIR ----------------------------

///Salir
void Menu::Salir(){
    cout << "\n" <<INICIAL<<COLOR_CIERRE<< "Fin de programa. Gracias por elegirnos!" <<FINAL << endl;
}