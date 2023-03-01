// Realizar un programa que permita registrar pacientes, se debe captura el nombre del paciente y el numero de documento.

//1. Mostrar los pacientes de tal manera que se muestre 1, 2, 3, etc según el orden de registro (Colas).
// Jose Arley Angulo Tamayo I.S
//Agregue a su aplicación FIFO una alternativa que me permita saber cuantos pacientes se han ingresado. 
//                                                            Desarrollo

#include <iostream>
#include <string>

using namespace std;

struct Paciente {
    string* nombre;
    int* numero_documento;
};

struct Nodo {
    Paciente paciente;
    Nodo* siguiente;
};

struct Cola {
    Nodo* inicio;
    Nodo* fin;
};

void inicializarCola(Cola& cola) {
    cola.inicio = nullptr;
    cola.fin = nullptr;
}

bool esVacia(Cola& cola) {
    return (cola.inicio == nullptr);
}

void encolar(Cola& cola, Paciente paciente) {
    Nodo* nuevo = new Nodo;
    nuevo->paciente = paciente;
    nuevo->siguiente = nullptr;

    if (esVacia(cola)) {
        cola.inicio = nuevo;
        cola.fin = nuevo;
    } else {
        cola.fin->siguiente = nuevo;
        cola.fin = nuevo;
    }
}

void desencolar(Cola& cola) {
    if (!esVacia(cola)) {
        Nodo* temp = cola.inicio;
        cola.inicio = cola.inicio->siguiente;
        delete temp->paciente.nombre;
        delete temp->paciente.numero_documento;
        delete temp;
    }
}

void verPacientes(Cola& cola) {
    if (esVacia(cola)) {
        cout << "No hay pacientes registrados.\n\n";
    } else {
        cout << "Lista de pacientes en orden de registro:\n";
        int num_registro = 1;
        Nodo* temp = cola.inicio;
        while (temp != nullptr) {
            Paciente paciente_actual = temp->paciente;
            cout << num_registro << ". " << *paciente_actual.nombre << " - " << *paciente_actual.numero_documento << "\n";
            temp = temp->siguiente;
            num_registro++;
        }
        cout << "\n";
    }
}

int contarPacientes(Cola& cola) {
    int cantidad = 0;
    Nodo* temp = cola.inicio;
    while (temp != nullptr) {
        cantidad++;
        temp = temp->siguiente;
    }
    return cantidad;
}

int main() {
    Cola cola_pacientes;
    inicializarCola(cola_pacientes);
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
            case 1: {
                Paciente paciente;
                paciente.nombre = new string;
                paciente.numero_documento = new int;
                cout << "Ingrese el nombre del paciente: ";
                cin >> *paciente.nombre;
                cout << "Ingrese el número de documento del paciente: ";
                cin >> *paciente.numero_documento;
                encolar(cola_pacientes, paciente);
                cout << "Paciente registrado exitosamente.\n\n";
                break;
            }
            case 2:
                verPacientes(cola_pacientes);
                break;
            case 3:
                cout << "Se han registrado " << contarPacientes(cola_pacientes) << " pacientes.\n\n";
                break;
            case 4:
                cout << "Hasta luego!\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n\n";
                break;
        }
    } while (opcion != 4);
    
    return 0;
}
