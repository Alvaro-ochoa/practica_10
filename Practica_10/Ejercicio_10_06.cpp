/* Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 6
Problema planteado: Gestión de empleados con funciones  */

#include <iostream>
#include <string>
using namespace std;
struct Empleado 
{
    string nombre;
    int id;
    double sueldo;
    int antiguedad;  
};
// Función para registrar los datos de un empleado
void registrarEmpleado(Empleado &empleado) 
{
    cout << "Ingrese el nombre del empleado: ";
    getline(cin, empleado.nombre);
    cout << "Ingrese el ID del empleado: ";
    cin >> empleado.id;
    cout << "Ingrese el sueldo del empleado: ";
    cin >> empleado.sueldo;
    cout << "Ingrese la antigüedad del empleado (en años): ";
    cin >> empleado.antiguedad;
    cin.ignore();  
}

int contarEmpleadosConSueldoMayorA(Empleado empleados[], int n, double sueldoLimite)
{
    int contador = 0;
    for (int i = 0; i < n; ++i) {
        if (empleados[i].sueldo > sueldoLimite) {
            contador++;
        }
    }
    return contador;
}

float calcularPromedioAntiguedad(Empleado empleados[], int n) 
{
    int sumaAntiguedad = 0;
    for (int i = 0; i < n; ++i) 
    {
        sumaAntiguedad += empleados[i].antiguedad;
    }
    return (n > 0) ? static_cast<double>(sumaAntiguedad) / n : 0.0;
}
// Función para mostrar los datos de un empleado
void mostrarEmpleado(const Empleado &empleado) 
{
    cout << "\nNombre: " << empleado.nombre << endl;
    cout << "ID: " << empleado.id << endl;
    cout << "Sueldo: " << empleado.sueldo << endl;
    cout << "Antigüedad: " << empleado.antiguedad << " años" << endl;
}

int main() 
{
    int N;
    cout << "Ingrese el número de empleados: ";
    cin >> N;
    cin.ignore(); 
    Empleado empleados[N];
    for (int i = 0; i < N; ++i) 
    {
        cout << "\nRegistro del empleado " << i + 1 << ":\n";
        registrarEmpleado(empleados[i]);
    }
    float sueldoLimite;
    cout << "\nIngrese el sueldo límite para contar empleados con sueldo mayor: ";
    cin >> sueldoLimite;
    int cantidadEmpleadosConSueldoMayor = contarEmpleadosConSueldoMayorA(empleados, N, sueldoLimite);
    cout << "\nCantidad de empleados con sueldo mayor a " << sueldoLimite << ": " << cantidadEmpleadosConSueldoMayor << endl;
    float promedioAntiguedad = calcularPromedioAntiguedad(empleados, N);
    cout << "\nPromedio de antigüedad de los empleados: " << promedioAntiguedad << " años" << endl;
    cout << "\nDatos de los empleados registrados:\n";
    for (int i = 0; i < N; ++i) {
        mostrarEmpleado(empleados[i]);
    }
    return 0;
}
