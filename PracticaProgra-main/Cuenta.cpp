#include "libreria.hpp"

class Cuenta
{ // clase realizada por luis, con algunos metodos de latasa
protected:
    float Fondos;

public:
    string Nombre_Usuario, Numero_Tarjeta; // nombre_usuario es realmente el dni del propietario (un nombre no podria ser pk)
    vector<Activo> activos;

    struct Cliente
    {
        // Propiedades del cliente
        string dni, nombre, apellido1, apellido2, contrasenna;
        vector<Cuenta> cuentas;

        Cliente() {}

        Cliente(string d, string n, string a1, string a2, string c)
        {
            dni = d;
            nombre = n;
            apellido1 = a1;
            apellido2 = a2;
            contrasenna = c;
        }

        // Métodos de la clase Cliente
        string getDNI() const { return dni; }

        void setDNI(string newDNI) { dni = newDNI; }

        string getNombre() const { return nombre; }

        void setNombre(string newNombre) { nombre = newNombre; }

        string getApell1() const { return apellido1; }

        void setApell1(string newApell1) { apellido1 = newApell1; }

        string getApell2() const { return apellido2; }

        void setApell2(string newApell2) { apellido2 = newApell2; }

        string getPass() const { return contrasenna; }

        void setPass(string newPass) { contrasenna = newPass; }

        void toString() const
        {
            cout << "DNI: " << dni << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Apellido1: " << apellido1 << endl;
            cout << "Apellido2: " << apellido2 << endl;
            cout << "Contrasenna: " << contrasenna << endl;
        }
    };

    Cuenta() {}

    Cuenta(string n, string num, float f)
    {
        Nombre_Usuario = n;
        Numero_Tarjeta = num;
        Fondos = f;
    }

    bool fondosSuficientes(float cantidad)
    {
        return cantidad <= Fondos;
    }

    pair<bool, Cuenta> cuentaCorrecta(vector<Cliente> clientes, string num)
    {
        bool estado = false;
        Cuenta elegida;
        if (num.length() == 16)
        {
            for (int i = 0; i <= clientes.size(); i++)
            {
                for (int j = 0; j <= clientes.at(i).cuentas.size(); j++)
                {
                    if (clientes.at(i).cuentas.at(j).Numero_Tarjeta == num)
                    {
                        estado = true;
                        elegida = clientes.at(i).cuentas.at(j);
                    }
                }
            }
        }

        return make_pair(estado, elegida);
    }

    void transferirFondos(int cantidad, Cuenta cta)
    {
        float nuevosFondos;
        Fondos -= cantidad;
        setFondos(Fondos);
        nuevosFondos = cantidad + cta.Fondos;
        cta.setFondos(nuevosFondos);
    }

    void hacer_Transferencia(vector<Cliente> clientes)
    {
        float cantidad;
        string num_Cuenta;
        bool estado;

        // Solicitar al usuario el número de cuenta del destinatario y la cantidad
        cout << "Ingrese el numero de tarjeta del destinatario: ";
        cin >> num_Cuenta;

        auto resultado = cuentaCorrecta(clientes, num_Cuenta);

        estado = resultado.first;
        Cuenta &elegida = resultado.second;

        if (estado)
        {
            cout << "Ingrese la cantidad a transferir: ";
            cin >> cantidad;
            if (fondosSuficientes(cantidad))
            {
                transferirFondos(cantidad, resultado.second);
                cout << "Transferencia realizada con exito." << endl;
            }
        }

        else
            cout << "Parece que ha ingresado mal el numero de cuenta.";
    }

    void añadir_Fondos()
    {
        float cantidad;
        string respuesta;
        cout << "Escriba la cantidad de fondos que desee anadir: " << endl;
        cin >> cantidad;
        cout << "Hemos entendido que desea anadir " << cantidad << " fondos a su cuenta. \nEs esto correcto? (s para si; n para no): ";
        cin >> respuesta;
        if (respuesta == "s")
        {
            Fondos += cantidad;
            setFondos(Fondos);
            cout << "Se han anadido " << cantidad << " correctamente a su cuenta." << endl;
        }
        else
        {
            cout << "De acuerdo. No se ha realizado la operacion.";
        }
    }

    void retirar_Fondos()
    {
        float cantidad;
        string respuesta;

        cout << "Escriba la cantidad de fondos que desee retirar: " << endl;
        cin >> cantidad;

        cout << "Hemos entendido que desea retirar " << cantidad << " fondos a su cuenta. \nEs esto correcto? (s para si; n para no): ";
        cin >> respuesta;

        if (respuesta == "s")
        {
            if (!fondosSuficientes(cantidad))
            {
                cerr << ("Insuficientes fondos"); // cerr es un cout pero dejando claro que es mensaje de error, no uno tradicional
            }
            else
            {
                Fondos -= cantidad;
                setFondos(Fondos);
                cout << "Se han extraido " << cantidad << " correctamente de su cuenta." << endl;
            }
        }
        else
        {
            cout << "De acuerdo. No se ha realizado la operacion." << endl;
        }
    }

    void getString()
    {
        cout << endl
             << "Numero de la tarjeta: " << Numero_Tarjeta << endl
             << "Propiedad de: " << Nombre_Usuario << endl
             << "Saldo actual: " << Fondos << endl;
    }

    string getNumTarjeta()
    {
        return Numero_Tarjeta;
    }

    void setNumTarjeta(string num)
    {
        Numero_Tarjeta = num;
    }

    string getNombre()
    {
        return Nombre_Usuario;
    }

    void setNombre(string nombre)
    {
        Nombre_Usuario = nombre;
    }

    float getFondos()
    {
        return Fondos;
    }

    void setFondos(float fondos)
    {
        Fondos = fondos;
    }
};


class Cuenta_Inversora : protected Cuenta
{
protected:
public:
    Cuenta_Inversora(string n, string num, float f, vector<Activo> act) : Cuenta(n, num, f)
    {
        Nombre_Usuario = n;
        Numero_Tarjeta = num;
        Fondos = f;
        activos = act;
    }

    void invertir()
    {
        int eleccion;
        cout << "¿En que Activo desea invertir?" << endl;
        cout << "Los Bonos dan pagos y los Prestamos tienen interes." << endl;
        cout << "1.- Bonos" << endl;
        cout << "2.- Prestamos" << endl;
        cout << "0.- Salir" << endl;
        switch (eleccion)
        {
        case 1:
            crear_bono();
            break;

        case 2:
            crear_prestamo();
            break;

        case 0:
        {
            cout << "Fin de Actividad. " << endl;
        }
        break;

        default:
            cout << "Opcion, no valida, eliga de nuevo. " << endl;
            break;
        }
        cin >> eleccion;
    }

    void crear_bono()
    {
        float cantidad;
        float pagos;
        float pago_final;
        cout << "Cuanto dinero desea pagar de forma inicial? " << endl;
        cin >> cantidad;
        if (Fondos < cantidad)
        {
            cout << "Fondos Insuficientes, vuelva a ingresar la cantidad. " << endl;
            crear_bono();
        }
        if (cantidad <= 100)
        {
            pagos = cantidad * 0.08;
            pago_final = cantidad * 1.02;
        }
        else if (cantidad <= 300 and cantidad > 100)
        {
            pagos = cantidad * 0.1;
            pago_final = cantidad * 1.03;
        }
        else if (cantidad > 300)
        {
            cout << "Es un placer hacer negocios con usted. " << endl;
            pagos = cantidad * 0.15;
            pago_final = cantidad * 1.05;
        }
        Bono bono(pago_final, cantidad, pagos);
        cout << "El bono con pago inicial de: " << cantidad << " pagos de: " << pagos << " y pago final de: " << pago_final << " ha sido creado" << endl;
        // activos.push_back(bono);
    }

    void crear_prestamo()
    {
        float tipo_interes;
        float desembolso_inicial;
        float promesa_de_pago;
        cout << "¿Cuanto dinero desea prestar?" << endl;
        cin >> desembolso_inicial;
        if (Fondos < desembolso_inicial)
        {
            cout << "Fondos insuficientes, operacion cancelada, vuelva a ingresar la cantidad. " << endl;
            crear_prestamo();
        }
        if (desembolso_inicial <= 100)
        {
            tipo_interes = 0.04;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.02 * desembolso_inicial;
        }
        else if (desembolso_inicial > 100 and desembolso_inicial <= 300)
        {
            tipo_interes = 0.06;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.03 * desembolso_inicial;
        }
        else if (desembolso_inicial > 300)
        {
            cout << "Es un placer hacer negocios con usted. " << endl;
            tipo_interes = 0.08;
            cout << "Su tipo de interes del prestamo es del: " << tipo_interes << endl;
            promesa_de_pago = 1.08 * desembolso_inicial;
        }
        Prestamo prestamo(tipo_interes, promesa_de_pago, desembolso_inicial);
        cout << "El prestamo con desembolso inicial de: " << desembolso_inicial << " tipo de interes del: " << tipo_interes << " y promesa de pago de: "
             << promesa_de_pago << " Ha sido emitido. " << endl;
        // activos.push_back(prestamo);
    }
};

