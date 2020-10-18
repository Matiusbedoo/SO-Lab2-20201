#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int segundoInicio;
    int segundoFinal;
    int microSegundoInicio;
    int microSegundoFinal;
    int totalSegundos;
    int totalMicrosegundos;
    int idHijo;

    //Se crea la estructura para poder obtener el tiempo
    struct timeval current_time;
    gettimeofday(&current_time, NULL);

    //tv_sec nos permite obtener los segundos
    segundoInicio = current_time.tv_sec;

    //tv_usec nos permite obtener los microsegundos
    microSegundoInicio = current_time.tv_usec;

    idHijo = fork();

    //Si se obtiene un valor negativo es porque hubo un error
    if (idHijo < 0)
    {
        exit(1);
    }
    else if (idHijo == 0)
    {
        system(argv[1]);
    }
    else
    {
        wait(NULL);
        gettimeofday(&current_time, NULL);
        segundoFinal = current_time.tv_sec;
        microSegundoFinal = current_time.tv_usec;
        totalSegundos = segundoFinal - segundoInicio;
        totalMicrosegundos = microSegundoFinal - microSegundoInicio;
        printf("Total tiempo: %i,%i\n", totalSegundos, totalMicrosegundos);
        
    }
}