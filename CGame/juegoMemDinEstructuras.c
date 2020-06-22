#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct{
	int salud;
	int mana;
	int fuerza;
	int magia;
}heroe;

typedef struct{
	int salud;
	int fuerza;
}malo;


heroe yo;
malo *otros;


void introduceyo();
void introducemalo(int N);
void asignamem(int *N);


int main (){

	int op, i, objetivo, pegar;
	int cont = 0; //contador de la batalla
	int N = 0; //va contando el numero de malos
	srand(time(NULL));
	introduceyo();
	
	asignamem(&N);

	//creamos la batalla

	do{
		do{
			printf("(1) Atacar.\n");
			printf("(2) Magia.\n");
			scanf("%i", &op);

		}while(op < 1 || op > 2);

		printf("Elige al malo al que quieres pegar.\n");

		for (i = 0; i < N; i++){
			printf("El malo %i tiene una vida de: %i.\n", i, otros[i].salud);
		}
		scanf("%i", &objetivo);

		if(otros[objetivo].salud > 0){
			switch(op){
				case 1:
					pegar = yo.fuerza;
					printf("He pegado %i.\n", pegar);
					otros[objetivo].salud -= pegar;
					printf("La salud del malo %i es de %i.\n", objetivo, otros[objetivo].salud);
					break;						
				case 2:
					if(yo.mana > 0){
						pegar = yo.magia * (rand() % 3); // pegaremos mi fuerza de pegar x 
									//0, 1 o 2 en función de la suerte que tenga
						printf("He pegado %i.\n", pegar);
						otros[objetivo].salud -= pegar;
						printf("La salud del malo %i es de %i.	\n",objetivo,otros[objetivo].salud);
					}
					else{
						printf("No tienes mana!!");
					}
					break;
			}
		}
		else{
			printf("Deja a los cadaveres. Tu objetivo esta muerto!!");
		}

		printf("Turno de los malos: \n");
		for(i = 0; i < N; i++){
			if(otros[i].salud > 0){
				pegar = otros[i].fuerza * (rand () % 3);
				printf("El malo %i me ha pegado %i.\n", i, pegar);
				yo.salud -= pegar;
				printf("Mi salud es de: %i\n", yo.salud);
			}
		}
		
		
		if ((cont % 2) == 0){ //Cada dos turnos crece el número de malos
			otros = (malo*)realloc(otros,(N+1)*sizeof(malo));
			if(otros == NULL){
				printf("No se ha podido reservar memoria.\n");
				exit(1);
			}
			introducemalo(N);
			N++;
		}
		cont++;
			
	}while(yo.salud > 0); //mientras estemos vivos seguimos peleando

	


system("pause");
return 0;


}

void introduceyo(){
	yo.salud = 10000;
	yo.mana = 100;
	yo.fuerza = 50;
	yo.magia = 100;
}

void introducemalo(int N){
	otros[N].salud = 100;
	otros[N].fuerza = 50;
}

void asignamem(int *N){
	//Esto se hace para reservar 1 espacio de memoria para nuestro malo
	//se pone *N+1 pq N vale 0, y +1 pues le indicamos que queresemos reservar 1 espacio
	otros = (malo*)malloc((*N+1)*sizeof(malo)); //si el vector dinámico fuera de enteros
        //pondríamos otros=(int*)malloc((*N+1)*sizeof(int)); y si fuera char pues con (char*)
	if (otros == NULL){
		printf("No se ha podido reservar mem. dinamica,\n");
		exit(1);
	}
	introducemalo(*N); 
	(*N)++; //aparece un nuevo malo
}
