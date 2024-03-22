# so_long

Archivos a entregar: Makefile, *.h, *.c, maps, textures

Objetivo: Crear un pequeño juego 2D con un personaje, coleccionables y una salida

Funciones autorizadas:
	*open	*close	*read	*write	*malloc
	*free	*perror	*strerror	exit
	*Todas las funciones de la biblioteca math (flag del compilador -lm, man 3 math)
	*Todas las funciones de la miniLibX
	*ft_printf

El programa debe aceptar como primer argumento un archivo con la extensión .ber

Funcionamiento del juego:
	El objetivo es recolectar los coleccionables y salir del mapa
	Las teclas de movimiento seran wasd, zqsd (teclado azerty) y/o flechas de dirección. Los movimientos serán arriba, abajo, izquierda y derecha.
	El personaje no puede ocupar la misma posición que una pared
	Habrá un contador de movimientos que se mostrará en el terminal
	El juego no tiene por qué ser en tiempo real

Gestión de gráficos:
	El programa abrirá una ventana donde se verá el juego
	Debe de tener un funcionamiento normal (minimizar, cambiar de ventana...)
	Con la tecla ESC y con el aspa roja (de la propia ventana) se debe cerrar la ventana y terminar el programa
	Es obligatorio el uso de **images** de la miniLibX

Mapa
	Se compone de paredes, objetos y espacios abiertos
	Los caracteres que representan los elementos del mapa son:
		*0	espacio vacío
		*1	pared
		*C	coleccionable
		*E	salida
		*P	posición inicial del personaje
	El juego sólo va a tener una E y una P, pero puede tener varios C (si más de una P o una E, deberá mostrar un error)
	El mapa será siempre rectangular y cerrado, así que el borde será sólo pared, si no, ha de devolver un error
	Hay que asegurarse de que exita un camino válido en el mapa (permite recoger los coleccionables y salir después)
	El mensaje de error tendrá el siguiente formato:
		**Error\n mensaje al gusto**
