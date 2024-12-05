/* Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 8
Problema planteado: Realizar un programa que simule y registre cuantas medallas ha ganado un atleta 
y que me muestre el medallero final por departamento. */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
struct Atleta 
{
    string nombre;
    string departamento;
    string deporte;
    int medallas_oro;
    int medallas_plata;
    int medallas_bronce;
    Atleta(string nombre = "", string departamento = "", string deporte = "")
        : nombre(nombre), departamento(departamento), deporte(deporte), 
          medallas_oro(0), medallas_plata(0), medallas_bronce(0) {}
};
// Función para registrar un atleta y sus medallas
void registrarAtleta(Atleta &atleta) 
{
    cout << "Ingrese el nombre del atleta: ";
    getline(cin, atleta.nombre);
    cout << "Ingrese el departamento que representa: ";
    getline(cin, atleta.departamento);
    cout << "Ingrese el deporte que practica (Tiro con arco, Atletismo, Boxeo, Ciclismo, Natación, Esgrima): ";
    getline(cin, atleta.deporte);
    cout << "Ingrese las medallas de oro ganadas: ";
    cin >> atleta.medallas_oro;
    cout << "Ingrese las medallas de plata ganadas: ";
    cin >> atleta.medallas_plata;
    cout << "Ingrese las medallas de bronce ganadas: ";
    cin >> atleta.medallas_bronce;
    cin.ignore(); 
}
// Función para mostrar el medallero por departamento
void mostrarMedalleroFinal(const unordered_map<string, unordered_map<string, int>> &medallero) 
{
    cout << "\nMedallero final por departamento:\n";
    for (const auto& departamento : medallero) 
    {
        cout << "Departamento: " << departamento.first << "\n";
        cout << "Medallas: ORO - " << departamento.second.at("oro")
             << ", PLATA - " << departamento.second.at("plata")
             << ", BRONCE - " << departamento.second.at("bronze") << endl;
    }
}

int main() 
{
    int N;  
    cout << "Ingrese el número de atletas: ";
    cin >> N;
    cin.ignore(); 
    vector<Atleta> atletas(N);
    unordered_map<string, unordered_map<string, int>> medallero;

    // Registrar los datos de los atletas
    for (int i = 0; i < N; ++i) 
    {
        cout << "\nRegistro del atleta " << i + 1 << ":\n";
        registrarAtleta(atletas[i]);
        string departamento = atletas[i].departamento;
        medallero[departamento]["oro"] += atletas[i].medallas_oro;
        medallero[departamento]["plata"] += atletas[i].medallas_plata;
        medallero[departamento]["bronze"] += atletas[i].medallas_bronce;
    }
    mostrarMedalleroFinal(medallero);
    return 0;
}
