/*
* @file: proyectoFinal.c
* @brief: Programa que cumple con los siguientes objetivos:
          1. Buenas practicas de programacion.
          2. Programacion modular
          3. Ordenar ascendentemente los números por árboles binarios.
          4. Se deben usar archivos de texto.
          5. Validar valores de entrada con enums.
* @authors: 
      Jose Pablo Montero Cantu
      Emilio Roman Sanchez
      Irving Alejandro Vega Lagunas
* @date: 01/12/2021
*/
#include "../libs/def.h"

/** Prototipos de funcion */
void createDerivate(float *x, float t, float *k1);
void plotResults(void);
nodo createStruct(nodo datos, char *argv[]);
void createSolutionFile(nodo datos);
ERROR_CODE argumentsVerification(int argc);
nodo newNodo(void);
nodo freeNodo(nodo datos);

int main(int argc, char *argv[]) 
{
  nodo datos;

  remove("solutions.dat");
	
  argumentsVerification(argc);

  datos = newNodo();

  datos = createStruct(datos, argv);

  createSolutionFile(datos);

  plotResults();

  datos = freeNodo(datos);


  return 1;
}

