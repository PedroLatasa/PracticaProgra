#include "libreria.hpp"

class Cuenta
{ // clase realizada por luis, con algunos metodos de latasa
private:
    float Fondos;

public:
    string Nombre_Usuario, Numero_Tarjeta; // nombre_usuario es realmente el dni del propietario (un nombre no podria ser pk)

   
    Cuenta() {}

    Cuenta(string num, string n, float f)
    {
        Numero_Tarjeta = num;
        Nombre_Usuario = n;
        Fondos = f;
    }

    string getNombre()
    {
        return Nombre_Usuario;
    }

    void setNombre(string nombre)
    {
        Nombre_Usuario = nombre;
    }

    string getNumTarjeta()
    {
        return Numero_Tarjeta;
    }

    void setNumTarjeta(string num)
    {
        Numero_Tarjeta = num;
    }

    float getFondos()
    {
        return Fondos;
    }

    void setFondos(float fondos)
    {
        Fondos = fondos;
    }

    void getString()
    {
        cout << endl
             << "Numero de la tarjeta: " << Numero_Tarjeta << endl
             << "Propiedad de: " << Nombre_Usuario << endl
             << "Saldo actual: " << getFondos() << endl;
    }

    bool fondosSuficientes(float cantidad)
    {
        return cantidad <= Fondos;
    }
    
    void añadir_Fondos()
    {
        float cantidad;
        string respuesta;
        cout << "Escriba la cantidad de fondos que desee anadir: ";
        cin >> cantidad;
        cout << "Hemos entendido que desea anadir " << cantidad << " fondos a su cuenta. \nEs esto correcto? (s para si; n para no): ";
        cin >> respuesta;
        if (respuesta == "s")
        {
            Fondos += cantidad;
            //setFondos(Fondos);
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

        cout << "Escriba la cantidad de fondos que desee retirar: ";
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
                    //setFondos(Fondos);
                    cout << "Se han extraido " << cantidad << " correctamente de su cuenta." << endl;
                } 
        }
        else
        {
            cout << "De acuerdo. No se ha realizado la operacion." << endl;
        }
    }
};
