/*
Nombres:
        Luis Rodrigo Montoya Rangel
        Claudio Alberto Ibañez Garduño
Descripcion:
        Progranma que desplega menu para crear archivo txt, abrir y eliminarlo.
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

void presentaMenuGeneral() {
  string contenido;
  int opcion;
do {
system("cls");
    cout << "		Menu principal\n" << endl;
    cout << "[1]Crear archivo de texto" << endl;
    cout << "[2]Abrir archivo de texto" << endl;
    cout << "[3]Eliminar archivo de texto" << endl;
    cout << "[0]Salir del programa\n" << endl;
    cout << "Ingresa la opcion: ";
    cin >> opcion;
    switch (opcion) {
    case 0:
        break;
case 1:{
  cout << "Ingresa el contenido del archivo: ";
  cin.ignore();
  getline(cin, contenido);
  ofstream fs("nombre.txt");
  fs << contenido << endl;
  fs.close();
  cout << "El archivo ha sido creado correctamente" << endl;
  system("pause");
  break;
}
case 2:{
  ifstream fs("nombre.txt", ios::in);
  char linea[128];
  long contador = 0L;
  if(fs.fail())
  cerr << "El fichero no existe" << endl;
  else
  while(!fs.eof())
  {
      fs.getline(linea, sizeof(linea));
      cout << linea << endl;
      if((++contador % 24)==0)
      {
          cout << "continuar...";
          cin.get();
      }
  }
  fs.close();
  system("pause");
  break;
}
case 3:
	if(remove("nombre.txt")==0) // Eliminamos el archivo
        printf("El archivo fue eliminado satisfactoriamente\n");
    else
        printf("No se pudo eliminar el archivo\n");
        
     system("PAUSE");   
    
        break;
default:
        cout << "\nEl numero de opcion escrito no es valido\n" << endl;
        system("pause");
    }
  } while (opcion != 0);
}

int main(){
 presentaMenuGeneral();
 return 0;
}
