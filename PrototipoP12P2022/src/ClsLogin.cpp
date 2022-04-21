#include "ClsLogin.h"

//librerias
#include<conio.h>
#include<iomanip>
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

//constructor
Clslogin::Clslogin(int ivalorIngreso, string svalorUsuario)
{
    mestablecerIngreso(ivalorIngreso);
    mestablecernombreUsuario(svalorUsuario);
}

//Funciones de la clave del empleado
int Clslogin::mobtenerIngreso() const
{
    return m_iingresoUsuario;
}

void Clslogin::mestablecerIngreso (int iingreso)
{
    m_iingresoUsuario = iingreso;
}

//Funciones del nombre del empleado
string Clslogin::mobtenernombreUsuario() const
{
    return m_snombreUsuario;
}

void Clslogin::mestablecernombreUsuario( string scadenaUsuario )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorUsuario = scadenaUsuario.data();
   int ilongitud = strlen( svalorUsuario );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreUsuario, svalorUsuario, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreUsuario[ ilongitud ] = '\0';

}

Clslogin::~Clslogin()
{
    //dtor
}
