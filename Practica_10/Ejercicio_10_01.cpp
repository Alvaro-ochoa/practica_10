/* Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 1
Problema planteado: Registro de una biblioteca*/
#include <iostream>
#include <string>
using namespace std;
struct Libro 
{
    string titulo;
    string autor;
    int age;
    bool disponible;
};
// Función para registrar los datos del libro
void registrarLibro(Libro &libro) 
{
    cout << "Ingrese el titulo del libro: ";
    getline(cin, libro.titulo);
    cout << "Ingrese el autor del libro: ";
    getline(cin, libro.autor);
    cout << "Ingrese el año de publicación del libro: ";
    cin >> libro.age;
    cout << "¿Está disponible el libro? (1 para sí, 0 para no): ";
    cin >> libro.disponible;
    cin.ignore();
}
// Función para mostrar los datos del libro
void mostrarLibro(const Libro &libro) 
{
    cout << "\nDatos del libro:\n";
    cout << "Titulo: " << libro.titulo << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Año de publicación: " << libro.age << endl;
    cout << "Estado de disponibilidad: " << (libro.disponible ? "Disponible" : "No disponible") << endl;
}
int main() 
{
    Libro libro;
    registrarLibro(libro);
    mostrarLibro(libro);
    return 0;
}
