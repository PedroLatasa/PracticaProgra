#include "libreria.hpp"

void interfaz()
{
    srand(time(NULL)); // planta semilla para calcular randoms
    vector<Cliente> clientes;
    // vector<Cuenta> cuentas;
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
                    int eleccion;
                    cout << "Inicio de sesion exitoso." << endl;
                    Cliente &actual = clientes.at(posicionCliente);
                    do
                    {
                        eleccion = menuPrincipal();
                        if (actual.cuentas.size() > 1 && eleccion != 0 && eleccion != 6) //casos para los que querremos que el usuario eliga sobre que cuenta operar
                        {
                            Cuenta &cta = actual.cuentas.at(eligeCuenta(actual)); // eleccion del usuario sobre que cuenta quiere operar
                            operaciones(eleccion, cta, actual);
                        }
                        else
                        {
                            Cuenta &cta = actual.cuentas.at(0);
                            operaciones(eleccion, cta, actual);
                        };
                        guardaDatos(clientes, numCuentas);
                    } while (eleccion != 0);
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
                    numCuentas++; // cuando se crea un nuevo registro, habremos creado una nueva cuenta tambien
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
            cerr << endl << e.what() << endl;
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

    cout << "\nSelecciona una opcion: ";
    cin >> opcion;
    if (opcion < 0 || opcion > 2)
    {
        throw runtime_error("Opcion no valida. Hasta luego!\n");
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
        cout << "\t0. Cerrar sesion\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 6)
        {
            cout << "Opción invalida" << endl;
        }
    } while (eleccion < 0 || eleccion > 6);
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
            cout << "Opción invalida" << endl;
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
        cout << "\n\t1. Cambiar DNI.\n";
        cout << "\t2. Cambiar nombre.\n";
        cout << "\t3. Cambiar el primer apellido.\n";
        cout << "\t4. Cambiar el segundo apellido.\n";
        cout << "\t0. Volver atras.\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 4)
        {
            cout << "Opción invalida" << endl;
        }
    } while (eleccion < 0 || eleccion > 4);
    return eleccion;
}

void cambiarDatos(int opcion, Cliente &c)
{
    string DNI, nombre, apellido1, apellido2;
    switch (opcion)
    {
    case 1:
        cout << "Ingrese su nuevo DNI: ";
        cin >> DNI;
        if (esDNIValido(DNI))
        {
            c.setDNI(DNI);
            cout << "El DNI ha sido correctamente actualizado.";
        }
        else
        {
            cout << "El DNI introducido no es valido.";
        }
        break;

    case 2:
        cout << "Ingrese su nuevo nombre: ";
        cin >> nombre;
        c.setNombre(nombre);
        cout << "El nombre ha sido correctamente actualizado.";
        break;

    case 3:
        cout << "Ingrese su nuevo primer apellido: ";
        cin >> apellido1;
        c.setApell1(apellido1);
        cout << "Su primer apellido ha sido correctamente actualizado.";
        break;

    case 4:

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

void cambiarInfo(int opcion, Cliente &c)
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
        cout << "Dese cambiarla? s:para si; n:para no: ";
        cin >> respuesta;
        if (respuesta == "s")
        {
            c.setPass(pedirContrasenna());
            cout << "Se ha cambiado su contrasenna.";
        }
    }

    break;
    case 3:
    {
        int respuesta2;
        int respuesta3;
        string num_cuenta;
        cout << "Ahora mismo tiene las siguientes cuentas a su nombre: " << endl;
        for (int i = 0; i < int(c.cuentas.size()); i++)
        {
            cout << i + 1 << ". " << c.cuentas.at(i).Numero_Tarjeta << endl;
        }
        cout << "Desea annadir o eliminar alguna cuenta?" << endl;
        cout << "1: annadir ; 2: eliminar: ";
        cin >> respuesta2;
        if (respuesta2 == 1)
        {
            c.cuentas.push_back(Cuenta());                // Crear una cuenta vacía asociada al nuevo cliente
            c.cuentas.back().Nombre_Usuario = c.getDNI(); // Usar el nombre como nombre de usuario por ahora
            num_cuenta = generarNumeroTarjeta();
            c.cuentas.back().Numero_Tarjeta = num_cuenta; // Simplemente incrementar el número de tarjeta
            c.cuentas.back().setFondos(0);
            cout << "Su cuenta ha sido annadida con numero: " << num_cuenta << endl;
        }
        else if (respuesta2 == 2)
        {
            cout << "Ahora mismo dispone de las siguientes cuentas: " << endl;
            for (int i = 0; i < int(c.cuentas.size()); i++)
            {
                cout << i + 1 << ". " << c.cuentas.at(i).Numero_Tarjeta << endl;
            }
            if (c.cuentas.size() > 1)
            {
                cout << "Desea la cuenta que desea eliminar marcando su numero(1,2,3..): ";
                cin >> respuesta3;
                respuesta3--;

                for (int i = 0; i < int(c.cuentas.size()); i++)
                {
                    if (respuesta3 == i)
                    {
                        c.cuentas.erase(c.cuentas.begin() + i);
                        break;
                    }
                }
                cout << "Su cuenta ha sido eliminada." << endl;
            }

            else
            {
                cout << "Lo siento pero solo dispone de una cuenta." << endl;
                cout << "No puede eliminar su unica cuenta. " << endl;
            }
        }
        else
        {
            cout << "Respuesta invalida.";
        }
    }
    break;

    case 0:
        break;

    default:
        cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        break;
    }
}

void operaciones(int eleccion, Cuenta &cta, Cliente &c)
{
    switch (eleccion)
    {
    case 1:
        cta.añadir_Fondos();
        break;

    case 2:
        cta.retirar_Fondos();
        break;

    case 3:
        // cta.hacer_Transferencia(clientes);
        break;

    case 4:
        // invertir();
        break;

    case 5:
        cta.getString();
        break;

    case 6:
    {
        int opcion = menuInformacion();
        cambiarInfo(opcion, c);
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
                    if (cta.Nombre_Usuario == c.getDNI())
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
        cout << "Ingrese la contrasena (debe contener al menos 8 caracteres con al menos una mayuscula, una minuscula, un numero y un caracter especial '?'): ";
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
    if (buscarCliente(clientes, dni) == -1) // cuando no se encuentra un cliente con ese dni en nuestra BBDD
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
        nuevoCliente.cuentas.back().setNombre(nuevoCliente.getDNI());      // Usar el nombre como nombre de usuario por ahora
        nuevoCliente.cuentas.back().setNumTarjeta(generarNumeroTarjeta()); // Simplemente incrementar el número de tarjeta
        nuevoCliente.cuentas.back().setFondos(0);                          // Nuevo usuario comienza con saldo cero
        clientes.push_back(nuevoCliente);                                  // Agregar el nuevo cliente al vector de clientes

        registrado = true; // Se registra con éxito y se devuelve true
        return registrado;
    }
    else
    {
        cout << "Este DNI ya esta registrado.";
        return registrado;
    }
}

bool esDNIValido(const string &dni)
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
        cout << i + 1 << "- " << c.cuentas.at(i).Numero_Tarjeta << endl;
    }
    cout << "Elige: ";
    cin >> eleccion;

    return eleccion - 1;
}

void guardaDatos(vector<Cliente> clientes, int numCuentas)
{ // Guarda los datos
    // guardaCuentas(cuentas);
    ofstream archivo, archivo2;
    archivo.open("datosClientes.txt"); // para windows copiar el path
    archivo << clientes.size() << endl;
    archivo2.open("datosCuentas.txt");
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
            archivo2 << clientes.at(i).cuentas.at(j).Numero_Tarjeta;
            archivo2 << " " << clientes.at(i).cuentas.at(j).Nombre_Usuario;
            archivo2 << " " << clientes.at(i).cuentas.at(j).getFondos() << endl;
        }
    }
    archivo.close();
}
