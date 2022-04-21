#ifndef CLSLOGIN_H
#define CLSLOGIN_H
//librerias
#include<string>
#include<iostream>

using std::string;

class Clslogin
{
    public:
        Clslogin( int = 0, string = "");

        /*Funciones de los atibutos
            Fuciones de la clave del empleado*/
        void mestablecerIngreso( int ) ;
        int mobtenerIngreso() const;

        //Funciones del nombre del empleado
        void mestablecernombreUsuario( string );
        string mobtenernombreUsuario() const;

        virtual ~Clslogin();

    protected:

    private:

        //Atributos
        int m_iingresoUsuario;
        char m_snombreUsuario[ 20 ];
};

#endif // CLSLOGIN_H
