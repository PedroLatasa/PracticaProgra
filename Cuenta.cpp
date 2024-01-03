#include "libreria.hpp"

class Cuenta { // clase realizada por luis, con algunos metodos de latasa
    private:

    public:
        string Nombre_Usuario, Numero_Tarjeta;
        float Fondos;

        void hacer_Transferencia() {
        }

        void añadir_Fondos() {
            float cantidad;
            cout << "Escriba la cantidad de fondos que desee añadir: " << endl;
            cin >> cantidad;
            Fondos += cantidad;
        }

        void retirar_Fondos() {
            float cantidad;
            cout << "Escriba la cantidad de fondos que desee retirar: " << endl;
            cin >> cantidad;
            Fondos -= cantidad;
        }

        void getName() {
            cout << "El nombre de usuario es " + string(Nombre_Usuario) << endl;
        }
        
        // Cuenta() {}
};
