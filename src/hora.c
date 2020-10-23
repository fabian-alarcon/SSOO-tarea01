//Fabián Alarcón Montenegro - 20.277.366-4

//Se incluyen las librerías necesarias.
//time.h para poder imprimir la fecha y hora en pantalla.
//signal.h para poder captar y manipular las señales.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

//La función SigintHandler cumple el rol de manipular la señal SIGUSR1.
//Recibe como parámetro el número de la señal.

//Utilizando las funciones de la librería time.h
//se calculan la fecha y hora actuales, para posteriormente
//imprimirlas como una cadena de caracteres.

void SigusHandler(int sig)
{
	time_t lahora;
	time(&lahora);
	printf("\nSeñal SIGUSR1 recibida: %s", ctime(&lahora));
}

//La función SigintHandler se usa para manipular la señal SIGINT.
//Recibirá como parámetro el número de la señal.
//Al utilizar "SIG_DFL", se restaurará el tratamiento por defecto
//de esta señal.
//Y en este caso, permitirá que el programa termine 
//al pulsar ctrl+c por segunda vez.

void SigintHandler(int sig)
{
	signal(SIGINT, SIG_DFL);
}

int main(void)
{
	//Se imprime la ID de proceso de este programa.
	//Se utiliza la función getpid() para que retorne la ID.
	
	//La idea de esto es facilitar la ejecución del comando
	//kill -s SIGUSR1, ya que necesita la PID para enviar la señal.
	
	printf("Programa hora ejecutandose. PID=%d",getpid());
	
	//Se utiliza la función signal para captar y manipular las señales.
	
	//Aquí se capta la señal SIGUSR1, que es enviada desde otra consola.
	//Y mediante la función SigusHandler se imprimirá
	//la fecha y hora en pantalla.
	
	signal(SIGUSR1, SigusHandler); 
	
	
	//Aquí se capta la señal SIGINT.
	//La cual se envía pulsando la secuencia ctrl+c desde el teclado.
	//La idea es que el programa finalice al recibir dos señales SIGINT.
	
	//Para ello, la función signal recibirá la primera señal SIGINT.
	//Y la función SiginHandler permitirá que el programa termine
	//al recibir la segunda señal SIGINT.
	
	signal(SIGINT, SigintHandler);
	
	//El programa entra en un bucle de espera infinito.
	//El mensaje se imprimirá cada 2 segundos,
	//gracias a la función "sleep".
	
	while(1)
	{	
		printf("\nListo para recibir la señal SIGUSR1.");
		sleep(2);
	}
	
	return 0;
}

