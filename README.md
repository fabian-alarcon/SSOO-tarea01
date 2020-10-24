# SSOO-tarea01
Primer tarea de Sistemas Operativos UV 2020.

Estudiante: Fabián Alarcón.
Correo institucional: fabian.alarconm@alumnos.uv.cl

El objetivo de esta tarea era elaborar un programa que imprimiera la fecha y hora en pantalla, cada vez que recibiera una señal SIGUSR1.

En la pauta se especificó que "hora.c" debía estar en un bucle de espera infinito. Durante ese estado, sólo podía imprimir la hora en pantalla al captar señales SIGUSR1, y que la única manera de terminar el programa era luego de recibir 2 señales SIGINT.

Para ello, primero me centré en que el programa pudiera captar los números de estas dos señales mediante la función signal() (de la librería <signal.h>), para poder otorgarles un comportamiento distinto, utilizando unos Signal Handlers. 

Los Signal Handlers de este programa fueron dos funciones que recibían el número de la señal como parámetro:

-SigusHandler: Calculaba la fecha y hora actual, usando funciones de la librería <time.h>. Y posteriormente lo imprimía como una cadena de caracteres junto con el texto "Señal SIGUSR1 recibida".

-SigintHandler: Luego de recibir la primer señal SIGINT, se hace un llamado a esta función. Para evitar que el programa termine luego del primer "control+c". Haciendo uso del SIG_DFL (default handler for signals), la señal SIGINT mantiene el comportamiento que tenía por defecto. Y esto permite que el programa sí finalice luego de que el usuario ejecute el comando control+c por segunda vez.

Por defecto, el programa iniciará imprimiendo en pantalla el texto: "Programa hora ejecutandose.", acompañado de la ID de proceso de este programa. 
Para obtener la PID se utilizó la función getpid(). Intuyo que la idea de mostrar la PID al inicio del programa, fue porque el comando kill -s SIGUSR1 necesita la ID de proceso de este programa para poder enviar la señal, y esto facilita las cosas para el usuario.

Posteriormente, hora.c entrará en un bucle while infinito, en el cual se imprimirá el texto: "Listo para recibir la señal SIGUSR1." cada 2 segundos. Esto último se hizo usando la función sleep().

En este estado, el programa imprimirá la fecha y hora en pantalla cada vez que se ejecute el comando kill -s SIGUSR1 desde otra consola. Y la única manera de salir del programa es pulsando el comando control+c 2 veces, tal y como se especificó en la pauta.
