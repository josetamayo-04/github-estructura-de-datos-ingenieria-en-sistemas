// Realizar un programa que permita registrar pacientes, se debe captura el nombre del paciente y el numero de documento.

//1. Mostrar los pacientes de tal manera que se muestre 1, 2, 3, etc según el orden de registro (Colas).
// Jose Arley Angulo Tamayo I.S
//                                              Desarrollo

#include <iostream>
#include <queue>
#include <string>
#include <cctype>
using namespace std;

struct Paciente {
    string nombre;
    string documento;
};

queue<Paciente*> cola_pacientes;

bool validar_nombre(const string& nombre) {
    for (char c : nombre) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

bool validar_documento(const string& documento) {
    for (char c : documento) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

void registrar_paciente() {
    string nombre, documento;
    cout << "Ingrese el nombre del paciente: ";
    getline(cin, nombre);
    while (!validar_nombre(nombre)) {
        cout << "Nombre inválido. Ingrese sólo letras y espacios: ";
        getline(cin, nombre);
    }
    cout << "Ingrese el número de documento del paciente: ";
    getline(cin, documento);
    while (!validar_documento(documento)) {
        cout << "Número de documento inválido. Ingrese sólo números: ";
        getline(cin, documento);
    }

    // Crear un nuevo objeto Paciente en el heap
    Paciente* nuevo_paciente = new Paciente;
    nuevo_paciente->nombre = nombre;
    nuevo_paciente->documento = documento;

    // Agregar el paciente a la cola
    cola_pacientes.push(nuevo_paciente);
    cout << "El paciente " << nombre << " ha sido registrado correctamente." << endl;
}

void mostrar_pacientes() {
    if (cola_pacientes.empty()) {
        cout << "No hay pacientes registrados." << endl;
    }
    else {
        int i = 1;
        cout << "Listado de pacientes registrados:" << endl;
        // Recorrer la cola y mostrar los pacientes en orden de registro
        while (!cola_pacientes.empty()) {
            Paciente* paciente_actual = cola_pacientes.front();
            cout << i << ". " << paciente_actual->nombre << " - Documento: " << paciente_actual->documento << endl;
            cola_pacientes.pop();
            i++;
        }
    }
}

int main() {
    int opcion = 0;
    while (opcion != 3) {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Registrar paciente" << endl;
        cout << "2. Ver pacientes registrados en orden de registro" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese el número de la opción que desea: ";
        cin >> opcion;
        cin.ignore(); // Ignorar el salto de línea después de ingresar la opción

        switch (opcion) {
        case 1:
            registrar_paciente();
            break;
        case 2:
            mostrar_pacientes();
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }
    }

    // Liberar la memoria reservada en el heap para cada paciente
    while (!cola_pacientes.empty()) {
        Paciente* paciente_actual = cola_pacientes.front();
        delete paciente_actual;
        cola_pacientes.pop();
    }

    return 0;
}
