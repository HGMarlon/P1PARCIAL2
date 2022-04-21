//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

//Clases
#include "Clslogin.h"

using namespace std;



int obtenerUsuario( const char * const );
void crearArchivoUsuarios();
void nuevoUsuario( fstream& );

int main(){
    int obtenerUsuario( const char * const );
    int iingresoUsuario;
    char snombreUsuario[ 20 ];
    int isesion = 0;
    int a=1;
    int codigo;
    int codigoa=0;
    string accion="";
    string ingresoUsuario;


    fstream archivoUsuarios("registrousuarios.dat", ios::in | ios::out | ios::binary);


    if ( !archivoUsuarios ){
            cerr << "No se pudo abrir el archivo." << endl;
            crearArchivoUsuarios();
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 0 );
        }

    cout<<"Marlon Estuardo Hernandez Giron 9491-21-7312"<<endl;
    cout<<""<<endl;
    cout<<"BIENVENIDO AL LOGIN"<<endl;
    cout<<"1. Iniciar sesion "<<endl;
    cout<<"2. Registrarse "<<endl;
    cin>>isesion;
    if(isesion==2)
    {
        nuevoUsuario(archivoUsuarios);
    }

   system("cls");
   cout<<"Ingrese su nombre de usuario :";
   cin>>snombreUsuario;
   string nombreUsuario;

   int numeroUsuario = obtenerUsuario("Escriba su codigo : ");


   archivoUsuarios.seekg(
      ( numeroUsuario - 1 ) * sizeof( Clslogin ) );


   Clslogin usuario;
   archivoUsuarios.read( reinterpret_cast< char * >( &usuario ),
      sizeof( Clslogin ) );



   if ( usuario.mobtenerIngreso() != 0 )
    {
        nombreUsuario=usuario.mobtenernombreUsuario();
    }


   else
   {
       cerr <<"No esta registrado." << endl;
   }
   if (nombreUsuario==snombreUsuario)
    {
        cout<<"Acceso concedido";
        a=0;
    }
    else
    {
        cout <<"Acceso denegado";
        getch();
    }

    if(a==0){

        getch();
}
}

void nuevoUsuario( fstream &insertarEnArchivo )
{

   int aingresoUsuario = obtenerUsuario( "Escriba el codigo de ingreso " );


   insertarEnArchivo.seekg(
      ( aingresoUsuario - 1 ) * sizeof( Clslogin ) );


   Clslogin usuario;
   insertarEnArchivo.read( reinterpret_cast< char * >( &usuario ),
      sizeof( Clslogin ) );


   if ( usuario.mobtenerIngreso() == 0 ) {

      char m_snombreUsuario[ 20 ];


      cout << "Escriba el nombre : " << endl;
      cin >> setw( 20 ) >> m_snombreUsuario;


      usuario.mestablecernombreUsuario( m_snombreUsuario );
      usuario.mestablecerIngreso( aingresoUsuario );


      insertarEnArchivo.seekp( ( aingresoUsuario - 1 ) *
         sizeof( Clslogin ) );


      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &usuario ),
         sizeof( Clslogin ) );

   }
   else
      cerr << "La cuenta #" << aingresoUsuario
           << " ya contiene informacion." << endl;

}

void crearArchivoUsuarios()
{
    ofstream archivoUsuarios("registrousuarios.dat", ios::out | ios::binary);
    if(!archivoUsuarios)
    {
        cerr<<"No se abrio el archivo"<<endl;
        exit(1);
    }
    Clslogin usuarioEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoUsuarios.write(reinterpret_cast<const char * > (&usuarioEnBlanco), sizeof(Clslogin));
    }
}

int obtenerUsuario( const char * const indicador )
{
   int m_iingresoUsuario;

   do {
      cout << indicador << " (1 - 100): ";
      cin >> m_iingresoUsuario;

   } while ( m_iingresoUsuario < 1 || m_iingresoUsuario > 100 );

   return m_iingresoUsuario;

}

