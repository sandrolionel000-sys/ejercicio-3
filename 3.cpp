
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <limits>
using namespace std;


class Estudiante {

public:
    string nombre;
    int nacimiento;
    float gpa;
};


class GrupoEstudiantes {

private:

    array<Estudiante, 10> estudiantes = {{
        {"Juan", 2000, 3.4},
        {"Maria", 2005, 2.8}
    }};

public:

    



    void ingresarTeclado() {

        cout << "INGRESO DE ESTUDIANTES" << endl;

        for (int i = 2; i < 4; i++) {

            cout << "\nNombre: ";
            getline(cin, estudiantes[i].nombre);

            cout << "Ano de nacimiento: ";
            cin >> estudiantes[i].nacimiento;

            cout << "GPA: ";
            cin >> estudiantes[i].gpa;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    
    


    void insertarArrays() {

        string nombres[3] = {"Gaby", "Patty", "Diana"};
        int nacimientos[3] = {2002, 2004, 2006};
        float gps[3] = {3.8, 3.0, 2.9};

        estudiantes[4] = {nombres[0], nacimientos[0], gps[0]};
        estudiantes[5] = {nombres[1], nacimientos[1], gps[1]};
    }

    
    



    void leerArchivo() {

        ifstream archivo("datos.txt");

        if (!archivo.is_open()) {
            cout << "Error al abrir datos.txt" << endl;
            return;
        }

        for (int i = 6; i < 10; i++) {

            archivo >> estudiantes[i].nombre;
            archivo >> estudiantes[i].nacimiento;
            archivo >> estudiantes[i].gpa;
        }

        archivo.close();
    }


    

    // 4. Mostrar estudiantes, edad y beca
    void mostrarEstudiantes() {

        int anioActual = 2026;

        cout << "\n========== LISTA DE ESTUDIANTES ==========" << endl;

        for (int i = 0; i < 10; i++) {

            int edad = anioActual - estudiantes[i].nacimiento;

            cout << "\nEstudiante: " << i + 1 << endl;
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Nacimiento: " << estudiantes[i].nacimiento << endl;
            cout << "GPA: " << estudiantes[i].gpa << endl;
            cout << "Edad aproximada: " << edad << " anos" << endl;

            if (estudiantes[i].gpa >= 3.5) {
                cout << "Beca: SI CALIFICA" << endl;
            }
            else {
                cout << "Beca: NO CALIFICA" << endl;
            }
        }
    }
};

int main() {

    GrupoEstudiantes grupo;

    grupo.ingresarTeclado();
    grupo.insertarArrays();
    grupo.leerArchivo();
    grupo.mostrarEstudiantes();

    return 0;
}
