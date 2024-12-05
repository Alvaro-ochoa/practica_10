/* Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 5
Problema planteado:  Sistema de gestión de películas */
#include <iostream>
#include <string>
using namespace std;
struct Pelicula
{
    string titulo;
    string director;
    int duracion;     
    int anio_estreno;  
    string genero;     
};
void registrarPelicula(Pelicula &pelicula) 
{
    cout << "Ingrese el título de la película: ";
    getline(cin, pelicula.titulo);
    cout << "Ingrese el nombre del director: ";
    getline(cin, pelicula.director);
    cout << "Ingrese la duración de la película (en minutos): ";
    cin >> pelicula.duracion;
    cout << "Ingrese el año de estreno de la película: ";
    cin >> pelicula.anio_estreno;
    cin.ignore();  
    cout << "Ingrese el género de la película: ";
    getline(cin, pelicula.genero);
    cin.ignore(); 
}

void mostrarPelicula(const Pelicula &pelicula) 
{
    cout << "\nTítulo: " << pelicula.titulo << endl;
    cout << "Director: " << pelicula.director << endl;
    cout << "Duración: " << pelicula.duracion << " minutos" << endl;
    cout << "Año de estreno: " << pelicula.anio_estreno << endl;
    cout << "Género: " << pelicula.genero << endl;
}
// Función para mostrar todas las películas de un género específico
void mostrarPorGenero(Pelicula peliculas[], int n, const string &genero) 
{
    bool encontrado = false;
    for (int i = 0; i < n; ++i) 
    {
        if (peliculas[i].genero == genero) 
        {
            mostrarPelicula(peliculas[i]);
            encontrado = true;
        }
    }
    if (!encontrado) 
    {
        cout << "No se encontraron películas del género " << genero << endl;
    }
}
// Función para mostrar todas las películas dirigidas por un director específico
void mostrarPorDirector(Pelicula peliculas[], int n, const string &director) 
{
    bool encontrado = false;
    for (int i = 0; i < n; ++i) 
    {
        if (peliculas[i].director == director) 
        {
            mostrarPelicula(peliculas[i]);
            encontrado = true;
        }
    }
    if (!encontrado)
    {
        cout << "No se encontraron películas dirigidas por " << director << endl;
    }
}

int main() 
{
    int N;
    cout << "Ingrese el número de películas a registrar: ";
    cin >> N;
    cin.ignore();
    Pelicula peliculas[N];
    for (int i = 0; i < N; ++i) 
    {
        cout << "\nRegistro de la película " << i + 1 << ":\n";
        registrarPelicula(peliculas[i]);
    }
    string generoBusqueda;
    cout << "\nIngrese el género para buscar las películas: ";
    getline(cin, generoBusqueda);
    mostrarPorGenero(peliculas, N, generoBusqueda);
    string directorBusqueda;
    cout << "\nIngrese el nombre del director para buscar las películas: ";
    getline(cin, directorBusqueda);
    mostrarPorDirector(peliculas, N, directorBusqueda);
    return 0;
}
