#include "libreria.hpp"

void interfaz()
{
    srand(time(NULL)); // planta semilla para calcular randoms
    vector<Cliente> clientes;
    //vector<Cuenta> cuentas;
    int numCuentas = cargaDatosClientes(clientes);
    int opcion;
    do
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
                do
                {
                    eleccion = menuPrincipal();
                    Cuenta &cta = clientes.at(posicionCliente).cuentas.at(0); // si solo tiene una cuenta, no tendra que elegir (se coge directamente esa, es decir, la 0)
                    if (clientes.at(posicionCliente).cuentas.size() > 1 && eleccion != 0)
                    {
                        cta = clientes.at(posicionCliente).cuentas.at(eligeCuenta(clientes.at(posicionCliente))); // eleccion del usuario sobre que cuenta quiere operar <--OJO: mirar sobrecarga defunciones
                    }
                    operaciones(eleccion, cta);
                    guardaDatos(clientes, numCuentas);
                } while (eleccion != 0);
            }
            else
            {
                cout << "Error de inicio de sesion." << endl;
            }
        }
        break;

        case 2:
        {
            if (registro(clientes))
            {
                numCuentas++; // cuando se crea un nuevo registro, habremos creado una nueva cuenta tambien
                guardaDatos(clientes, numCuentas);
                cout << "Registro exitoso. Ahora puede iniciar sesion." << endl;
                //numCuentas = cargaDatosClientes(clientes); // al crear un nuevo usuario tambien se genera una nueva cuenta, por lo que querremos releer la BBDD   
            }
            else
            {
                cout << "\nError en el registro." << endl;
            }
        }
        break;

        case 0:
            cout << "Gracias por usar nuestro servicio. Hasta luego!" << endl;
            break;

        default:
        {
            cout << "Opcion no valida. Por favor, seleccione una opcion valida." << endl;
        }
        break;
        }

    } while (opcion != 0);
}

int menuInicial()
{
    int opcion;
    do
    {
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
            cout << "Opción invalida." << endl;
        }
    } while (opcion < 0 || opcion > 2);
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
        cout << "\t0. Cerrar sesion\n";

        cout << "\nSelecciona una opcion: ";
        cin >> eleccion;
        if (eleccion < 0 || eleccion > 5)
        {
            cout << "Opción inválida" << endl;
        }
    } while (eleccion < 0 || eleccion > 5);
    return eleccion;
}

void operaciones(int eleccion, Cuenta& cta)
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

    case 0:
    {
        cout << "Sesion cerrada. Hasta luego!" << endl << endl;
    }
    break;

    default:
        cout << "Opcion no valida. Por favor, seleccione una opción valida." << endl;
        break;
    }
}

int cargaDatosClientes(vector<Cliente> &cliente)
{
    int numClientes = 0, numCuentas = 0;
    string dni, apell1, apell2, nombre, pass;
    float saldo = 0;
    ifstream archivo;
    archivo.open("datosClientes.txt"); // para windows copiar el path
    if (archivo.is_open())
    {
        archivo >> numClientes;
        for (int i = 0; i < numClientes; i++)
        {
            Cliente c;
            archivo >> dni;
            archivo >> apell1;
            archivo >> apell2;
            archivo >> nombre;
            archivo >> pass;
            c.setDNI(dni); // mejor constructor...
            c.setPass(pass);
            c.setApell1(apell1);
            c.setApell2(apell2);
            c.setNombre(nombre);

            ifstream archivo2;
            archivo2.open("datosCuentas.txt"); // para windows copiar el path
            if (archivo2.is_open())
            {
                archivo2 >> numCuentas;
                for (int j = 0; j < numCuentas; j++)
                {
                    Cuenta cta;
                    archivo2 >> cta.Numero_Tarjeta;
                    archivo2 >> cta.Nombre_Usuario;
                    archivo2 >> saldo;
                    cta.setFondos(saldo);
                    // if(i == 0) cuentas.push_back(cta); // solo queremos guardar las cuentas 1 vez... en la primera vuelta del loop por ej.
                    if (cta.Nombre_Usuario == c.getDNI())
                        c.cuentas.push_back(cta);
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
    for (int i = 0; i < clientes.size(); i++)
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
    if (buscarCliente(clientes, dni) == -1) //cuando no se encuentra un cliente con ese dni en nuestra BBDD
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
        nuevoCliente.cuentas.push_back(Cuenta());                            // Crear una cuenta vacía asociada al nuevo cliente
        nuevoCliente.cuentas.back().Nombre_Usuario = nuevoCliente.getDNI();  // Usar el nombre como nombre de usuario por ahora
        nuevoCliente.cuentas.back().Numero_Tarjeta = generarNumeroTarjeta(); // Simplemente incrementar el número de tarjeta
        nuevoCliente.cuentas.back().setFondos(0);                            // Nuevo usuario comienza con saldo cero                // Almacenar la contraseña en la cuenta

        clientes.push_back(nuevoCliente); // Agregar el nuevo cliente al vector de clientes

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
    cout << "\n Elige sobre que cuenta operar: ";
    for (int i = 0; i < c.cuentas.size(); i++)
    {
        cout << i << "- " << c.cuentas.at(i).Numero_Tarjeta << endl;
    }
    cout << "Elige: ";
    cin >> eleccion;

    return eleccion;
}

void guardaDatos(vector<Cliente> clientes, int numCuentas)
{ // Guarda los datos
    // guardaCuentas(cuentas);
    ofstream archivo, archivo2;
    archivo.open("datosClientes.txt"); // para windows copiar el path
    archivo << clientes.size() << endl;
    archivo2.open("datosCuentas.txt");
    archivo2 << numCuentas << endl;
    for (int i = 0; i < clientes.size(); i++)
    {
        archivo << clientes.at(i).getDNI();
        archivo << " " << clientes.at(i).getApell1();
        archivo << " " << clientes.at(i).getApell2();
        archivo << " " << clientes.at(i).getNombre();
        archivo << " " << clientes.at(i).getPass() << endl;
        for (int j = 0; j < clientes.at(i).cuentas.size(); j++)
        {
            archivo2 << clientes.at(i).cuentas.at(j).Numero_Tarjeta;
            archivo2 << " " << clientes.at(i).cuentas.at(j).Nombre_Usuario;
            archivo2 << " " << clientes.at(i).cuentas.at(j).getFondos() << endl;
        }
    }
    archivo.close();
}
