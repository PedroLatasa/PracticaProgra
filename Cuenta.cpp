#include "libreria.hpp"

class Cuenta
{ // clase realizada por luis, con algunos metodos de latasa
private:
    float Fondos;

public:
    string Nombre_Usuario, Numero_Tarjeta; // nombre_usuario es realmente el dni del propietario (un nombre no podria ser pk)

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
                else{
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
             << "Saldo actual: " << getFondos() << endl;
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
