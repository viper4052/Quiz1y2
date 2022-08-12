#include <iostream>
#include <string>

/*
*    Quiz #1 y #2
* --------------------------
* Utilizando arreglos en C++ escriba una estructura de datos que le permita modelar un tren de N vagones 
* y escriba una función que reciba el tren por parámetro, luego liste los 10 primeros y los 10 últimos asientos disponibles.
* Eso hace que el tren por definición tenga alguna forma de marcar los asientos ya ocupados.
*
*/

using namespace std;

struct tren
{
    int vagones;
    int asientos;
};
tren nuevoTren;

const int v = 2; // cantidad de vagones del tren
const int a = 10; // cantidad de asientos del tren
int arrayTren[v][a]; // crea el array que forma el tren


int inicializaTren(int nVagones, int nAsientos, int arrayTren[v][a]){ // Esta funcion inicializa el tren 
    for (int i = 0; i < v; i++)                                       // con todos los espacios vacíos
    {
        for (int j = 0; j < a; j++)
        {
            arrayTren[i][j] = 0;
        }
    }
    return 0; 
}


int asignaEspacios(int nVagones, int nAsientos, int arrayTren[v][a]){ // funcion que genera los espacios ocupados
    for (int i = 0; i < v; i++)                                       // de forma aleatoria usando la función rand()
    {
        for (int j = 0; j < a; j++)
        {
            arrayTren[i][j] = rand() % 2;
        }
    }
    return 0;
}   


int formaTren(int nVagones, int nAsientos, int arrayTren[v][a]){  // Genera el tren y le da forma dependiendo de los parámetros
    nuevoTren.vagones = nVagones;                                 //  que se le definanen la sección de variables arriba del programa
    nuevoTren.asientos = nAsientos;                               
    for (int i = 0; i < nVagones; i++){
       for (int j = 0; j < nAsientos; j++){
            arrayTren[i][j] = asignaEspacios(v, a, arrayTren);
       }
    }
    
    // esta parte permite ver los asientos del tren y su estado.
    // 1 es ocupado y 0 es libre.
    for (int i = 0; i < v; i++) 
    {
        for (int j = 0; j < a; j++)
        {
            cout << arrayTren[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";

    return 0;
}

int listaPrimUltAsientos(int arrayTren[v][a]){
    int primeros[10] = {}; // crea un array para almacenar los primeros 10 espacios libres
    int ultimos[10] = {}; // crea otro array para almacenar los últimos 10 espacios libres

    inicializaTren(v, a, arrayTren); // crea el array del tren
    formaTren(v, a, arrayTren); // hace que se cree el tren y con asientos ocupados

    for (int i = 0; i < a; i++)       // for loop para obtener los 10 primeros asientos.
    {
        for (int j = 0; j < v; j++)
        {
            if (arrayTren[i][j] == 0)
            {
                primeros[i] = 0;
            }  
        }
    } 
    
    for (int k = 10; k < a; k--)       // for loop para obtener los 10 últimos asientos.
    {
        for (int l = 10; l < v; l--)
        {
            if (arrayTren[k][l] == 0)
            {
                ultimos[k] = 0;
            }  
        }
    } 
    

    cout << "Los primeros 10 asientos son: ";
    for (int i = 0; i < 10; i++)
        cout << primeros[i] << ' ';

    cout << "\nLos últimos 10 asientos son: ";
    for (int j = 0; j < 10; j++)
        cout << ultimos[j] << ' ';
    
    
     return 0;
}



int main(){    
    listaPrimUltAsientos(arrayTren); // ejecuta la función principal para obtener la información

    cout << "\nEl tren tiene " + std::to_string(nuevoTren.vagones) + " vagones y " 
    + std::to_string(nuevoTren.asientos*nuevoTren.vagones) + " asientos.";
    return 0;
}