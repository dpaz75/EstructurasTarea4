#include "NodoArbolBinario.h"
#include "Evaluador.h"
#include <iostream>       // std::cin, std::cout
#include <list>          // std::list
using namespace std;

//Devuelve la suma de todos los numeros del arbol con la raiz dada.

int suma(NodoArbolBinario* raiz)
{
    //caso base
    if(raiz==NULL) //si la raiz es nula sale del ciclo
    return 0;
    int sumador=raiz->num;  // guardamos el dato de la raiz en ese momento en un campo entero
    //llamadas recurcivas
    int sumai= suma(raiz->hijo_izq); //acumulamos el nodo del hijo izquierdo en una variable de forma recurciva
    int sumad=suma(raiz->hijo_der);  //acumulamos el nodo del hijo derecho en una variable de forma recurciva
    //cuerpo
    sumador=sumador+sumai+sumad; //acumula los campos recursivos
    return sumador; //retorna la suma
}

//Devuelve la cantidad de nodos que tiene el arbol con la raiz dada.
int cantidadNodos(NodoArbolBinario* raiz)
{
    //caso base
    if(raiz==NULL) //si la raiz es nula sale del ciclo
    return 0;

    //cuerpo
    int cont=1; //inicializamos en uno para contar la primera entrada
    if(raiz->hijo_izq!=NULL) //se verifica que el lado izquierdo no sea nulo para iniciar la llamada recursiva
        //llamada recurciva
        cont+=cantidadNodos(raiz->hijo_izq);//cuenta el valor que tiene el hijo izquierdo en ese momento

    if(raiz->hijo_der!=NULL) //se verifica que el lado derecho no sea nulo para iniciar la llamada recursiva
        //llamada recurciva
        cont+=cantidadNodos(raiz->hijo_der);//cuenta el valor  que tiene el hijo derecho ese momento

    return cont; // devuelve el contador
}

//Devuelve el promedio de los numeros que tiene el arbol con la raiz dada.
int promedio(NodoArbolBinario* raiz)
{
    int sum = suma(raiz);// sumamos los valores del arbol
    int cant = cantidadNodos(raiz);//calculamos cuantos hojas tiene el arbol
    int promedio = sum / cant;//calculamos el promedio dividiendo la suma del arbol entra la cantidad de hojas
    return promedio;//nos devuelve el promedio
}

//Devuelve la cantidad de pasos que tiene que dar el algoritmo para llegar a un numero dado.
//Ejemplo: http://www.comp.nus.edu.sg/~stevenha/visualization/bst.html
//Para llegar al nodo 7 se ocupan 3 pasos (15,6,7)
//Para llegar al nodo 5 se ocupan 4 pasos (15,6,4,5)
//Para llegar al nodo 15 se ocupa 1 paso (15)
int cuantosPasos(NodoArbolBinario* raiz,int num)
{
    //Casos Base
    if(raiz==NULL) // si la raiz es nula se sale del ciclo
      return 1; // si no existe retornamos 1, si lo encuentra en el primer paso

    if(raiz->num == num) // compara que el valor de la raiz sea el mumero que buscamos
       return 1; //  numero de la raiz que buscamos es igual al numero que enviamos retorna 1,si lo encontramos en el primer paso

    //Cuerpo
    int cont = 1; // contador para que cuente el numero de pasos
    if(num>raiz->num) // si el numero es mayor que la raiz
            //llamada recurciva
        cont += cuantosPasos(raiz->hijo_der,num); // si es mayor contamos los pasos del hijo por la derecha

    if(num<raiz->num) // verificamos si el numero es menor que la raiz
            //llamada recurciva
        cont += cuantosPasos(raiz->hijo_izq,num); // si es menor contamos los pasos del hijo por la izquierda

    return cont; // nos devuelva la cantidad de pasos contados
}


//Devuelve la cantidad de hojas que tiene el arbol con la raiz dada.
int sumaHojas(NodoArbolBinario* raiz)
{
    //caso base
    if(raiz==NULL) //si la raiz es nula sale del ciclo
    return 0;

    //cuerpo
    if(raiz->hijo_izq==NULL && raiz->hijo_der==NULL) //se verifica que el lado izquierdo y derecho del arbol sean nulos
            return 1; // si ambos hijos son Nulos retornamos 1
    else
     //llamada recurciva
    return sumaHojas(raiz->hijo_izq)+sumaHojas(raiz->hijo_der); // sumamos el hijo izquierdo y derecho,y retornamos la suma de ellos.

}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 1;
}
