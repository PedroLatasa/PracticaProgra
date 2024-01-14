#include "libreria.hpp"


void interfaz()
{
    vector<Cliente> clientes;
    srand(time(NULL)); // planta semilla para calcular randoms
    int numCuentas = cargaDatosClientes(clientes);
    int opcion;
    do
    {
        try
        {
            opcion = menuInicial();
            switch (opcion)
            {
            case 1:
            {
                int posicionCliente = login(clientes);
                if (posicionCliente != -1)
                { // sera "if(login())", pero hasta que este realizado el metodo en cuestion lo tomamos como true | o esta bien ya asi??
                    int eleccion, aux;
                    cout << "\nInicio de sesion exitoso." << endl;
                    Cliente &actual = clientes.at(posicionCliente);
                    do
                    {
                        eleccion = menuPrincipal();
                        if (int(actual.cuentas.size()) > 1 && eleccion != 0 && eleccion != 6 && eleccion != 7) // casos para los que querremos que el usuario eliga sobre que cuenta operar
                        {
                            Cuenta &cta = actual.cuentas.at(eligeCuenta(actual)); // eleccion del usuario sobre que cuenta quiere operar
                            aux = operaciones(eleccion, clientes, cta, actual, numCuentas);
                            numCuentas = aux;
                        }
                        else
                        {
                            Cuenta &cta = actual.cuentas.at(0);
                            aux = operaciones(eleccion, clientes, cta, actual, numCuentas);
                            numCuentas = aux;
                        }
                        if (eleccion == 1 || eleccion == 2 || eleccion == 3 || eleccion == 4 || eleccion == 5)
                        {
                            guardaDatos(clientes, numCuentas);
                        }
                    } while (eleccion != 0 && eleccion != 7);
                }
                else
                {
                    cout << "Error de inicio de sesion.\n";
                }
            }
            break;

            case 2:
            {
                if (registro(clientes))
                {
                    numCuentas++;
                    guardaDatos(clientes, numCuentas);
                    cout << "Registro exitoso. Ahora puede iniciar sesion.\n\n";
                    // numCuentas = cargaDatosClientes(clientes); // al crear un nuevo usuario tambien se genera una nueva cuenta, por lo que querremos releer la BBDD
                }
                else
                {
                    cout << "\nError en el registro.\n\n";
                }
            }
            break;

            case 0:
                cout << "Gracias por usar nuestro servicio. Hasta luego!\n\n";
                break;
            }
        }
        catch (const exception &e)
        {
            cerr << endl
                 << e.what() << endl;
        }

    } while (opcion != 0);
}

int menuInicial()
{
    int opcion;

    cout << "\t\t\t*********************\n";
    cout << "\t\t\t Bienvenido al banco\n";
    cout << "\t\t\t*********************\n";
    cout << "\n\t1. Iniciar sesion\n";
    cout << "\t2. Crear cuenta bancaria\n";
    cout << "\t0. Salir\n";

    while (true)
    {
        cout << "\nSelecciona una opcion: ";
        cin >> opcion;

        if (cin.fail())
        {
            cout << "No le he entendido. Por favor, ingrese un numero entre 0 y 2." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (opcion >= 0 && opcion <= 2)
        {
            break;
        }
        else
        {
            cout << "No le he entendido. Por favor, ingrese un numero entre 0 y 2." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return opcion;
}

int menuPrincipal()
{
    int eleccion;
    do
    {
        cout << "\n\t*************************\n";
        cout << "\n\t1. Ingresar dinero\n";
        cout << "\t2. Retirar dinero\n";
        cout << "\t3. Realizar transferencia\n";
        cout << "\t4. Inversiones\n";
        cout << "\t5. Informacion de la cuenta\n";
        cout << "\t6. Cambiar informacion de perfil\n";
        cout << "\t7. Darse de baja.\n";
        cout << "\t0. Cerrar sesion\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 7)
        {
            cout << "Opcion invalida" << endl;
        }
    } while (eleccion < 0 || eleccion > 7);
    return eleccion;
}

int menuInformacion()
{
    int eleccion;
    do
    {
        cout << "\n\t*************************\n";
        cout << "\n\t1. Cambiar datos de usuario.\n";
        cout << "\t2. Cambiar contrasenna.\n";
        cout << "\t3. Annadir/Eliminar cuenta.\n";
        cout << "\t0. Volver atras.\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 3)
        {
            cout << "Opcion invalida" << endl;
        }
    } while (eleccion < 0 || eleccion > 3);

    return eleccion;
}

int menuCambiarDatos()
{
    int eleccion;
    do
    {
        cout << "\n\t*************************\n";
        cout << "\t1. Cambiar nombre.\n";
        cout << "\t2. Cambiar el primer apellido.\n";
        cout << "\t3. Cambiar el segundo apellido.\n";
        cout << "\t0. Volver atras.\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 3)
        {
            cout << "Opcion invalida" << endl;
        }
    } while (eleccion < 0 || eleccion > 3);

    return eleccion;
}

void cambiarDatos(int opcion, Cliente &c)
{
    string DNI, nombre, apellido1, apellido2;
    switch (opcion)
    {

    case 1:
        cout << "Ingrese su nuevo nombre: ";
        cin >> nombre;
        c.setNombre(nombre);
        cout << "El nombre ha sido correctamente actualizado.";
        break;

    case 2:
        cout << "Ingrese su nuevo primer apellido: ";
        cin >> apellido1;
        c.setApell1(apellido1);
        cout << "Su primer apellido ha sido correctamente actualizado.";
        break;

    case 3:

        cout << "Ingrese su nuevo segundo apellido: ";
        cin >> apellido2;
        c.setApell2(apellido2);
        cout << "Su segundo apellido ha sido correctamente actualizado.";
        break;

    case 0:
        break;

    default:
        cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
        break;
    }
}

int darseDeBaja(Cliente &c, vector<Cliente> &clientes, int numCuentas)
{
    string respuesta;
    cout << "\nHola " << c.getNombre() << ". Veo que quiere darse de baja." << endl;
    cout << "Si se da de baja tenga en cuenta que eliminaremos todos los datos de usuario." << endl;
    cout << "Ademas debe saber que eliminaremos todas las cuentas que queden a su nombre. " << endl;
    cout << "Por eso le recomendamos que retire los fondos restantes de sus cuentas. " << endl;
    cout << "Desea continuar? (S/N): ";
    cin >> respuesta;
    if (respuesta == "s" || respuesta == "S")
    {
        cout << "De acuerdo a continuacion procederemos a darle de baja como nuestro cliente." << endl;
        cout << "Eliminamos sus cuentas: " << endl;
        for (int i = 0; i < int(c.cuentas.size()); i++)
        {
            cout << i + 1 << ". " << c.cuentas.at(i).getNumTarjeta() << endl;
            c.cuentas.erase(c.cuentas.begin() + i);
            numCuentas--;
        }

        cout << "Eliminamos su cuenta de cliente..." << endl;
        for (int j = 0; j < int(clientes.size()); j++)
        {
            if (clientes.at(j).getDNI() == c.getDNI())
            {
                clientes.erase(clientes.begin() + j);
                break; // salimos del bucle cuando ya hemos borrado al cliente en cuestion
            }
        }

        cout << "Su cuenta ha sido eliminada correctamente. " << endl;
    }
    else
    {
        cout << "Operacion cancelada. " << endl;
    }

    return numCuentas;
}

int cambiarInfo(int opcion, Cliente &c, int numCuentas)
{
    switch (opcion)
    {
    case 1:
    {
        int resultado = menuCambiarDatos();
        cambiarDatos(resultado, c);
    }
    break;

    case 2:
    {
        string respuesta;
        cout << "Su contrasenna actual es: " << c.getPass() << endl;
        cout << "Dese cambiarla?(S/N): ";
        cin >> respuesta;
        if (respuesta == "s" || respuesta == "S")
        {
            c.setPass(pedirContrasenna());
            cout << "Se ha cambiado su contrasenna.";
        }
    }

    break;
    case 3:
    {
        int respuesta2, respuesta3;
        //int respuesta4;
        string num_cuenta;
        cout << "Ahora mismo tiene las siguientes cuentas a su nombre: " << endl;
        for (int i = 0; i < int(c.cuentas.size()); i++)
        {
            cout << i + 1 << ". " << c.cuentas.at(i).getNumTarjeta() << endl;
        }
        cout << "Desea annadir o eliminar alguna cuenta?" << endl;
        cout << "1: annadir ; 2: eliminar: ";
        cin >> respuesta2;
        if (respuesta2 == 1)
        {
            c.cuentas.push_back(Cuenta());       // Crear una cuenta vacía asociada al nuevo cliente
            c.cuentas.back().setDni(c.getDNI()); // Usar el nombre como nombre de usuario por ahora
            num_cuenta = generarNumeroTarjeta();
            c.cuentas.back().setNumTarjeta(num_cuenta); // Simplemente incrementar el número de tarjeta
            c.cuentas.back().setFondos(0);
            numCuentas++;
            cout << "Su cuenta ha sido annadida con numero: " << num_cuenta << endl;
            /*
                cout << "\nDesea crear una cuenta estandar(1) o inversora(2): ";
                do
                {
                    cin >> respuesta4;
                    if (respuesta4 != 1 && respuesta4 != 2)
                    {
                        cerr << "Eleccion no valida. Elija de nuevo: ";
                    }
                } while (respuesta4 != 1 && respuesta4 != 2);
                if (respuesta4 == 1)
                {
                    c.cuentas.push_back(Cuenta());       // Crear una cuenta vacía asociada al nuevo cliente
                    c.cuentas.back().setDni(c.getDNI()); // Usar el nombre como nombre de usuario por ahora
                    num_cuenta = generarNumeroTarjeta();
                    c.cuentas.back().setNumTarjeta(num_cuenta); // Simplemente incrementar el número de tarjeta
                    c.cuentas.back().setFondos(0);
                    numCuentas++;
                    cout << "Su cuenta ha sido annadida con numero: " << num_cuenta << endl;
                }
                else{
                    //da fallo el incluir una CuentaInversora al vector de Cuentas...
                    c.cuentas.push_back(CuentaInversora());
                    c.cuentas.back().setDni(c.getDNI());
                    num_cuenta = generarNumeroTarjeta();
                    c.cuentas.back().setNumTarjeta(num_cuenta);
                    c.cuentas.back().setFondos(0);
                    numCuentas++;
                    cout << "Su cuenta ha sido annadida con numero: " << num_cuenta << endl;
                }
                */
        }
        else if (respuesta2 == 2)
        {
            if (c.cuentas.size() > 1)
            {
                cout << "Desea la cuenta que desea eliminar marcando su numero(1,2,3..): ";
                cin >> respuesta3;
                respuesta3--; // para mostrar por pantalla usamos 1,2,3... como enumeracion de cuenta, pero en el vector seria 0,1,2... Por eso se resta uno a la opcion

                for (int i = 0; i < int(c.cuentas.size()); i++)
                {
                    if (respuesta3 == i)
                    {
                        c.cuentas.erase(c.cuentas.begin() + i);
                        numCuentas--;
                        i = (int)c.cuentas.size(); // forzamos la salida del bucle
                    }
                }

                cout << "Su cuenta ha sido eliminada." << endl;
            }

            else
            {
                cout << endl
                     << "Al parecer solo dispone de una cuenta. " << endl
                     << "Dar de baja su ultima cuenta implica la dada de baja de su usuario en su totalidad." << endl
                     << "Si desea dar de baja el usuario seleccione la opcion 'Darse de baja'(7) en el menu que aparece a continuacion." << endl;
            }
        }
        else
        {
            cout << "\nRespuesta invalida.\n";
        }
    }
    break;

    case 0:
        break;

    default:
        cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        break;
    }

    return numCuentas;
}

bool buscarCuenta(vector<Cliente> &clientes, string num)
{
    bool correctoNum = false;
    for (int i = 0; i < int(clientes.size()); i++)
    {
        for (int j = 0; j < int(clientes.at(i).cuentas.size()); j++)
        {
            if (clientes.at(i).cuentas.at(j).getNumTarjeta() == num)
            {
                correctoNum = true;
                break;
            }
        }
    }

    return correctoNum;
}

void annadirFondos(vector<Cliente> &clientes, string num, float fondos)
{
    for (int i = 0; i < int(clientes.size()); i++)
    {
        for (int j = 0; j < int(clientes.at(i).cuentas.size()); j++)
        {
            if (clientes.at(i).cuentas.at(j).getNumTarjeta() == num)
            {
                clientes.at(i).cuentas.at(j).setFondos(float(clientes.at(i).cuentas.at(j).getFondos()) + fondos);
                break;
            }
        }
    }
}

void realizarTransferencia(vector<Cliente> &clientes, Cuenta &cta)
{
    string numDestinatario;
    float fondos;
    bool estado = false;

    do
    {
        cout << "Ingrese el numero de cuenta del destinatario: ";
        cin >> numDestinatario;
        estado = buscarCuenta(clientes, numDestinatario);
        if (estado)
        {
            cout << "Ingrese la cantidad de fondos que desea transferir :";
            cin >> fondos;
            if (cta.fondos_suficientes(fondos))
            {
                cout << "De acuerdo, traspasamos " << fondos << " a la cuenta " << numDestinatario << endl;
                cta.setFondos(float(cta.getFondos() - fondos));
                annadirFondos(clientes, numDestinatario, fondos);
                cout << "Se han annadido correctamente " << fondos << " a la cuenta: " << numDestinatario;
            }
            else
                cout << "Fondos insuficientes." << endl;
        }

        else
        {
            cout << "No existe nadie con ese numero de cuenta. Pruebe de nuevo." << endl;
        }
    } while (!estado);
}

int operaciones(int eleccion, vector<Cliente> &clientes, Cuenta &cta, Cliente &c, int numCuentas)
{
    int n = numCuentas;
    switch (eleccion)
    {
    case 1:
        cta.añadir_fondos();
        break;

    case 2:
        cta.retirar_fondos();
        break;

    case 3:
        realizarTransferencia(clientes, cta);
        break;

    case 4:
        cta.invertir();
        break;

    case 5:
        cta.getString();
        break;

    case 6:
    {
        int opcion = menuInformacion();
        n = cambiarInfo(opcion, c, numCuentas);
        guardaDatos(clientes, n);
    }
    break;

    case 7:
    {
        n = darseDeBaja(c, clientes, numCuentas);
        guardaDatos(clientes, n);
        cout << "Sesion cerrada. Hasta luego!" << endl
             << endl;
    }
    break;

    case 0:

        cout << "Sesion cerrada. Hasta luego!" << endl
             << endl;
        break;

    default:
        cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
        break;
    }

    return n;
}

int cargaDatosClientes(vector<Cliente> &cliente)
{
    int numClientes = 0, numCuentas = 0;
    string dni, apell1, apell2, nombre, pass, num;
    float saldo = 0;
    ifstream archivo;
    archivo.open("datosClientes.txt"); // para windows copiar el path
    if (archivo.is_open())
    {
        archivo >> numClientes;
        for (int i = 0; i < numClientes; i++)
        {
            // Cliente c;
            archivo >> dni;
            archivo >> apell1;
            archivo >> apell2;
            archivo >> nombre;
            archivo >> pass;
            Cliente c(dni, nombre, apell1, apell2, pass); // creacion objeto Cliente

            ifstream archivo2;
            archivo2.open("datosCuentas.txt"); // para windows copiar el path
            if (archivo2.is_open())
            {
                archivo2 >> numCuentas;
                for (int j = 0; j < numCuentas; j++)
                {
                    archivo2 >> num;
                    archivo2 >> nombre;
                    archivo2 >> saldo;
                    Cuenta cta(num, nombre, saldo); // creacion objeto Cuenta
                    // annadir al vector de cuentas de cliente las cuentas que le pertenezcan:
                    if (cta.getDni() == c.getDNI())
                    {
                        c.cuentas.push_back(cta);
                    }
                }
                archivo2.close();
            }
            else
            {
                cout << "No se ha podido acceder a los datos de cuentas.\n";
            }

            cliente.push_back(c);
        }
        archivo.close();
    }
    else
    {
        cout << "No se ha podido acceder a los datos de clientes.\n";
    }

    return numCuentas;
}

int buscarCliente(vector<Cliente> clientes, string dni)
{
    int pos = -1; // en caso de no encontrar un cliente con dicho dni devuelve -1
    for (int i = 0; i < int(clientes.size()); i++)
    {
        if (clientes.at(i).getDNI() == dni)
        {
            pos = i;
            i = clientes.size();
        }
    }

    return pos;
}

int login(vector<Cliente> clientes)
{
    string dni, password;
    int contador = 0;
    bool isIn = false;
    int posicion;

    do
    {
        cout << "\n\t\t\tLOGIN DE USUARIO\n";
        cout << "\t\t\t-----------------\n";
        cout << "\n\tDNI: ";
        cin >> dni;
        cout << "\tPassword: ";
        cin >> password;

        posicion = buscarCliente(clientes, dni);
        if (posicion != -1 && clientes.at(posicion).getPass() == password)
        {
            isIn = true;
        }

        else if (!isIn)
        {
            cout << "\tError en el DNI o la contrasena. Intente de nuevo." << endl;
            contador++;
        }

    } while (contador < 3 && !isIn);

    if (!isIn)
    {
        posicion = -1;
        cout << "No ha podido acceder al sistema." << endl;
    }

    return posicion;
}

bool cumpleRequisitos(const string password)
{
    bool tieneMayuscula = false;
    bool tieneMinuscula = false;
    bool tieneNumero = false;
    bool tieneCaracterEspecial = false;

    for (char c : password)
    {
        if (isupper(c))
        {
            tieneMayuscula = true;
        }
        else if (islower(c))
        {
            tieneMinuscula = true;
        }
        else if (isdigit(c))
        {
            tieneNumero = true;
        }
        else if (ispunct(c))
        {
            tieneCaracterEspecial = true;
        }
    }

    return tieneMayuscula && tieneMinuscula && tieneNumero && tieneCaracterEspecial;
}

string pedirContrasenna()
{
    string password;
    do
    {
        cout << "Ingrese la contrasena (debe contener al menos 8 caracteres con al menos una mayuscula,";
        cout << " una minuscula, un numero y un caracter especial '?'): ";
        cin >> password;
        if (cumpleRequisitos(password))
        {
            string confirmacion;
            cout << "Ahora confirme la contrasena: ";
            cin >> confirmacion;

            if (password == confirmacion)
            {
                return password;
            }
            else
            {
                cout << "Las contrasenas no coinciden. Intentelo de nuevo." << endl;
            }
        }
        else
        {
            cout << "La contrasena no cumple con los requisitos. Intentelo de nuevo." << endl;
        }
    } while (true);
}

string generarNumeroTarjeta()
{

    string acumular;

    for (int i = 1; i <= 4; i++)
    {
        string cadena = to_string(rand() % 9000 + 1000);
        acumular += cadena;
    }

    return acumular;
}

bool registro(vector<Cliente> &clientes)
{
    bool registrado = false;
    string dni, apell1, apell2, nombre, password;

    cout << "Registro de nuevo usuario\n";
    cout << "Ingrese el DNI del nuevo usuario: ";
    cin >> dni;

    // Verificar si el usuario ya existe
    if (buscarCliente(clientes, dni) == -1 && esDniValido(dni)) // cuando no se encuentra un cliente con ese dni en nuestra BBDD
    {
        cout << "Ingrese el nombre: ";
        cin >> nombre;
        cout << "Ingrese el primer apellido: ";
        cin >> apell1;
        cout << "Ingrese el segundo apellido: ";
        cin >> apell2;
        password = pedirContrasenna();
        Cliente nuevoCliente = {dni, nombre, apell1, apell2, password};

        // Agregar el nuevo cliente y crear una nueva cuenta
        nuevoCliente.cuentas.push_back(Cuenta());                          // Crear una cuenta vacía asociada al nuevo cliente
        nuevoCliente.cuentas.back().setDni(nuevoCliente.getDNI());         // Usar el nombre como nombre de usuario por ahora
        nuevoCliente.cuentas.back().setNumTarjeta(generarNumeroTarjeta()); // Simplemente incrementar el número de tarjeta
        nuevoCliente.cuentas.back().setFondos(0);                          // Nuevo usuario comienza con saldo cero
        clientes.push_back(nuevoCliente);                                  // Agregar el nuevo cliente al vector de clientes

        registrado = true; // Se registra con éxito y se devuelve true
        return registrado;
    }
    else
    {
        cout << "DNI registrado o DNI invalido.";
        return registrado;
    }
}

bool esDniValido(const string &dni)
{
    if (dni.length() != 9)
    {
        return false;
    }

    for (int i = 0; i < 8; ++i)
    {
        if (!isdigit(dni[i]))
        {
            return false;
        }
    }

    if (!isalpha(dni[8]))
    {
        return false;
    }

    return true;
}

int eligeCuenta(Cliente c)
{
    int eleccion;
    cout << "\n Elige sobre que cuenta operar: " << endl;
    for (int i = 0; i < int(c.cuentas.size()); i++)
    {
        cout << i + 1 << "- " << c.cuentas.at(i).getNumTarjeta() << endl;
    }
    cout << "Elige: ";
    cin >> eleccion;

    return eleccion - 1;
}

void guardaDatos(vector<Cliente> clientes, int numCuentas)
{ // Guarda los datos
    ofstream archivo, archivo2;
    archivo.open("datosClientes.txt"); // para windows copiar el path
    archivo << int(clientes.size()) << endl;
    archivo2.open("datosCuentas.txt"); // para windows copiar el path
    archivo2 << numCuentas << endl;
    for (int i = 0; i < int(clientes.size()); i++)
    {
        archivo << clientes.at(i).getDNI();
        archivo << " " << clientes.at(i).getApell1();
        archivo << " " << clientes.at(i).getApell2();
        archivo << " " << clientes.at(i).getNombre();
        archivo << " " << clientes.at(i).getPass() << endl;
        for (int j = 0; j < int(clientes.at(i).cuentas.size()); j++)
        {
            archivo2 << clientes.at(i).cuentas.at(j).getNumTarjeta();
            archivo2 << " " << clientes.at(i).cuentas.at(j).getDni();
            archivo2 << " " << clientes.at(i).cuentas.at(j).getFondos() << endl;
        }
    }
    archivo.close();
}
