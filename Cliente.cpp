#include "libreria.hpp"
#include<vector>

class Cliente {
    protected:
        string dni, nombre, apellido1, apellido2, contrasenna;
        vector<Cuenta> cuentas;
    public:

        Cliente (string d, string n, string a1, string a2, string c, vector<Cuenta> ct){
            string dni = d;
            nombre = n;
            apellido1 = a1;
            apellido2 = a2;
            contrasenna = c;
            cuentas = ct;

        }
        // Cliente() {}
};

class Cliente_Inversor : private Cliente{
    vector<Activo> activos;
    float rentabilidad;

    public:
        void muestra_rentabilidad(){
            cout << "La rentabilidad de " << nombre << " " << apellido1 << " " << apellido2 << " es de: " << rentabilidad << "%. " << endl;
        }

};