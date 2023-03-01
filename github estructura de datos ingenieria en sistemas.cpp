// Realizar un programa que permita registrar pacientes, se debe captura el nombre del paciente y el numero de documento.

//1. Mostrar los pacientes de tal manera que se muestre 1, 2, 3, etc según el orden de registro (Colas).
// Jose Arley Angulo Tamayo I.S
//Agregue a su aplicación FIFO una alternativa que me permita saber cuantos pacientes se han ingresado. 
//                                                            Desarrollo

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Paciente {
    string* nombre;
    int* numero_documento;
};

int main() {
    queue<Paciente> cola_pacientes;
    int opcion;
    do {
        cout << "Menu:\n";
        cout << "1. Registrar paciente\n";
        cout << "2. Ver pacientes registrados\n";
        cout << "3. Cuantos pacientes se han registrado\n";
        cout << "4. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                Paciente paciente;
                paciente.nombre = new string;
                paciente.numero_documento = new int;
                cout << "Ingrese el nombre del paciente: ";
                cin >> *paciente.nombre;
                cout << "Ingrese el número de documento del paciente: ";
                cin >> *paciente.numero_documento;
                cola_pacientes.push(paciente);
                cout << "Paciente registrado exitosamente.\n\n";
                break;
            case 2:
                if (cola_pacientes.empty()) {
                    cout << "No hay pacientes registrados.\n\n";
                } else {
                    cout << "Lista de pacientes en orden de registro:\n";
                    int num_registro = 1;
                    queue<Paciente> copia_cola_pacientes = cola_pacientes;
                    while (!copia_cola_pacientes.empty()) {
                        Paciente paciente_actual = copia_cola_pacientes.front();
                        cout << num_registro << ". " << *paciente_actual.nombre << " - " << *paciente_actual.numero_documento << "\n";
                        copia_cola_pacientes.pop();
                        num_registro++;
                    }
                    cout << "\n";
                }
                break;
            case 3:
                cout << "Se han registrado " << cola_pacientes.size() << " pacientes.\n\n";
                break;
            case 4:
                cout << "Hasta luego!\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n\n";
                break;
        }
    } while (opcion != 4);
    
    // Liberar memoria
    while (!cola_pacientes.empty()) {
        Paciente paciente_actual = cola_pacientes.front();
        delete paciente_actual.nombre;
        delete paciente_actual.numero_documento;
        cola_pacientes.pop();
    }
    
    return 0;
}

