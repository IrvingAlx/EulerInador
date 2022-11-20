/**
*@file: funciones.c
*@brief: Archivo con las funciones utilizadas en el programa
*@authors: Jose Pablo Montero, Emilio Roman e Irving Vega 
*/
#include "../libs/def.h"

struct data
{
  float t;
  float tinitial;
  float tmax;
  float yinitial;
  float h;
  float x[1]; 
  float derivalue[1]; 
  float yaprox; 
  float yexact;
}; 

static nodo initNewNodo(nodo newNodo)
{
  newNodo->t = 0;
  newNodo->tinitial = 0;
  newNodo->tmax = 0;
  newNodo->h = 0;
  newNodo->yaprox = 0;
  newNodo->yexact = 0;
  newNodo->yinitial = 0 ;
  
  return newNodo;
}

extern nodo newNodo(void)
{
  nodo myNodo = NULL;

   myNodo = malloc(sizeof(struct data));

   myNodo = initNewNodo(myNodo);

   return myNodo;
}

// 3 Editar

extern void createDerivate(float *x, float t, float *derivalue) 
{
  derivalue[0]=-2*x[0]-exp(-4*t); 
}


extern void plotResults(void)
{
  FILE *gnupipe;
  gnupipe=popen("gnuplot -persist","w");
  fprintf(gnupipe,"plot \"solutions.dat\" using 1:3 with lines\n");

  pclose(gnupipe);
}


extern void createSolutionFile(nodo datos)
{
  int i;
FILE *fp;	
	fp = fopen("solutions.dat", "w");

for (datos->t = datos->tinitial; datos->t < datos->tmax; datos->t+=datos->h) 
{ 
	createDerivate(datos->x, datos->t, datos->derivalue);
	datos->yaprox=datos->x[0]; 
	datos->yexact = -2*(datos->x[0]) - exp(-4*datos->t);


	fprintf(fp," %4.2f \t %6.4f \t%6.4f\n", datos->t, datos->yexact, datos->yaprox);
	
		for(i = 0; i < 1; i++)
		{ 
			datos->x[i] = datos->x[i] + datos->h*datos->derivalue[i];
		}
}

			fclose(fp);
}

extern nodo createStruct(nodo datos, char *argv[])
{

	float yaprox, yexact; 
	float x[1], k1[1];
	float h, t, t0, tmax, y0; 
	int i;
  float buffer[10];
  
	sscanf(argv[1], "%f", &t0);
		sscanf(argv[2], "%f", &tmax);
			sscanf(argv[3], "%f", &y0);
				sscanf(argv[4], "%f", &h);
				datos->tinitial = t0;
			datos->tmax = tmax;
		datos->yinitial = y0;
	datos->h = h;

	datos->x[0]=y0; 
	datos->yaprox=datos->x[0]; 

return datos;	 
}

nodo freeNodo(nodo datos)
{
  free(datos);
  datos = NULL;
  return datos;
}


ERROR_CODE argumentsVerification(int argc){
  if(argc != 5)
  {
  printf("\n\nError en el numero de argumentos ingresados....Saliendo");
  return 0;
  }
  return 1;
}
