/* Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 3
Problema planteado: Estudiantes de Programación I:
Descripción: Desarrolle una estructura que guarde los datos de los n alumnos de la materia Programación I */
#include <iostream>
#include <string>
using namespace std;
struct Estudiante 
{
    int cedula;
    string nombre;
    string apellido;
    int edad;
    string profesion;
    string lugar_nacimiento;
    string direccion;
    int telefono;
};
// Función para registrar los datos de un estudiante
void registrarEstudiante(Estudiante &estudiante) 
{
    cout << "Ingrese la cédula del estudiante: ";
    cin >> estudiante.cedula;
    cin.ignore();  
    cout << "Ingrese el nombre del estudiante: ";
    getline(cin, estudiante.nombre);
    cout << "Ingrese el apellido del estudiante: ";
    getline(cin, estudiante.apellido);
    cout << "Ingrese la edad del estudiante: ";
    cin >> estudiante.edad;
    cin.ignore();  
    cout << "Ingrese la profesión del estudiante: ";
    getline(cin, estudiante.profesion);
    cout << "Ingrese el lugar de nacimiento del estudiante: ";
    getline(cin, estudiante.lugar_nacimiento);
    cout << "Ingrese la dirección del estudiante: ";
    getline(cin, estudiante.direccion);
    cout << "Ingrese el teléfono del estudiante: ";
    cin >> estudiante.telefono;
    cin.ignore();  
}
// Función para mostrar los datos de un estudiante
void mostrarEstudiante(const Estudiante &estudiante) 
{
    cout << "\nDatos del Estudiante:\n";
    cout << "Cédula: " << estudiante.cedula << endl;
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Apellido: " << estudiante.apellido << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Profesión: " << estudiante.profesion << endl;
    cout << "Lugar de Nacimiento: " << estudiante.lugar_nacimiento << endl;
    cout << "Dirección: " << estudiante.direccion << endl;
    cout << "Teléfono: " << estudiante.telefono << endl;
}
int main() 
{
    int N;
    cout << "Ingrese el número de estudiantes: ";
    cin >> N;
    cin.ignore();
    Estudiante estudiantes[N];
    // Registrar los datos de cada estudiante
    for (int i = 0; i < N; ++i)
    {
        cout << "\nRegistro del estudiante " << i + 1 << ":\n";
        registrarEstudiante(estudiantes[i]);
    }
    cout << "\nDatos de los estudiantes registrados:\n";
    for (int i = 0; i < N; ++i) 
    {
        mostrarEstudiante(estudiantes[i]);
    }
    return 0;
}
