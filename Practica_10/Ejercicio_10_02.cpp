/* Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 2
Problema planteado: Datos de un atleta  */

#include <iostream>
#include <string>
using namespace std;
struct Atleta 
{
    string nombre;
    string pais;
    int edad;
    int mejor_tiempo; 
};
// Función para ingresar los datos de un atleta
void ingresarDatosAtleta(Atleta &atleta) 
{
    cout << "Ingrese el nombre del atleta: ";
    getline(cin, atleta.nombre);
    cout << "Ingrese el país del atleta: ";
    getline(cin, atleta.pais);
    cout << "Ingrese la edad del atleta: ";
    cin >> atleta.edad;
    cout << "Ingrese el mejor tiempo del atleta (en segundos): ";
    cin >> atleta.mejor_tiempo;
    cin.ignore(); 
}

Atleta obtenerMejorAtleta(Atleta atletas[], int n) 
{
    Atleta mejor_atleta = atletas[0];  
    for (int i = 1; i < n; ++i) 
    {
        if (atletas[i].mejor_tiempo < mejor_atleta.mejor_tiempo) {
            mejor_atleta = atletas[i];  
        }
    }
    return mejor_atleta;
}

int main() 
{
    int n;
    cout << "Ingrese el número de atletas: ";
    cin >> n;
    cin.ignore();  
    Atleta atletas[n];
    // Ingresar los datos de cada atleta
    for (int i = 0; i < n; ++i) 
    {
        cout << "\nAtleta #" << i + 1 << endl;
        ingresarDatosAtleta(atletas[i]);
    }
    Atleta mejor_atleta = obtenerMejorAtleta(atletas, n);
    cout << "\nEl atleta con el mejor tiempo es:\n";
    cout << "Nombre: " << mejor_atleta.nombre << endl;
    cout << "País: " << mejor_atleta.pais << endl;
    cout << "Mejor tiempo: " << mejor_atleta.mejor_tiempo << " segundos\n";
    return 0;
}
