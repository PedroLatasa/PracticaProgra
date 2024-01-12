#include "libreria.hpp"
#include<vector>

class Cliente {
    protected:
        string dni, nombre, apellido1, apellido2, contrasenna;
    public:
        vector<Cuenta> cuentas;

        Cliente(){}

        Cliente (string d, string n, string a1, string a2, string c){
            string dni = d;
            nombre = n;
            apellido1 = a1;
            apellido2 = a2;
            contrasenna = c;
        }

        string getDNI()
        {
            return dni;
        }

        void setDNI(string dni){
            this->dni = dni;
        }

        string getNombre()
        {
            return nombre;
        }

        void setNombre(string nombre){
            this->nombre = nombre;
        }

        string getApell1()
        {
            return apellido1;
        }

        void setApell1(string apell1){
            apellido1 = apell1;
        }

        string getApell2()
        {
            return apellido2;
        }

        void setApell2(string apell2){
            apellido2 = apell2;
        }

        string getPass()
        {
            return contrasenna;
        }

        void setPass(string pass){
            contrasenna = pass;
        }

        void toString(){
            cout << "DNI: " << dni << endl;
            cout << "Nombre: " << nombre << endl;
            cout << "Apellido1: " << apellido1 << endl;
            cout << "Apelllido2: " << apellido2 << endl;
            cout << "Contrasenna: " << contrasenna << endl;

        }

};

class Cliente_Inversor : private Cliente{
    vector<Activo> activos;
    float rentabilidad;

    public:
        void muestra_rentabilidad(){
            cout << "La rentabilidad de " << nombre << " " << apellido1 << " " << apellido2 << " es de: " << rentabilidad << "%. " << endl;
        }

};
