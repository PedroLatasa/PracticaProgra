#include "libreria.hpp"

class Cuenta
{ // clase realizada por luis, con algunos metodos de latasa
private:
    float Fondos;
public:
    string Nombre_Usuario, Numero_Tarjeta; // nombre_usuario es realmente el dni del propietario (un nombre no podria ser pk)

    Cuenta() {}
    
    void hacer_Transferencia()
    {
        float cantidad = 0;
        string num_Cuenta = " ";

        // Solicitar al usuario el número de cuenta del destinatario y la cantidad
        cout << "Ingrese el numero de tarjeta del destinatario: ";
        cin >> num_Cuenta;

        cout << "Ingrese la cantidad a transferir: ";
        cin >> cantidad;

        
    }

    void añadir_Fondos()
    {
        float cantidad = 0;
        string respuesta; 
        cout << "Escriba la cantidad de fondos que desee anadir: " << endl;
        cin >> cantidad;
        cout << "Hemos entendido que desea anadir " << cantidad << " fondos a su cuenta. \nEs esto correcto? (s para si; n para no): ";
        cin >> respuesta; 
        if (respuesta == "s"){
            Fondos += cantidad;
            cout << "Se han anadido " << cantidad << " correctamente a su cuenta." << endl;

        }
        else{
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
        if (respuesta == "s"){
            
            //meter posible try catch para comprobar que se realizar la retirada
            //que la cantidad sea menor que los fondos

            Fondos -= cantidad;
            cout << "Se han extraido " << cantidad << " correctamente de su cuenta." << endl;
        }
        else{
            cout << "De acuerdo. No se ha realizado la operacion.";
        }
    }

    void getString()
    {
        cout << endl << "Numero de la tarjeta: " << Numero_Tarjeta << endl 
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
