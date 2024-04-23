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

MLX
	API que permite la creación y el manejo de interfaces gráficas de usuario (GUI).
	Se requiere una compilación desde el makefile para hacerla funcionar y después importarla en el header.
		Makefile: ´-l mlx -l ft -framework OpenGL -framework Appkit´
		.h: ´# include "mlx.h"´
	Lo primero será inicializar la MLX con el comando void	´*mlx = mlx_init();´. Esto creará una conexión entre el programa y el display (en este caso, la ventana en la que se ejecuta so_long).

	Manejo de ventana:
		void *mlx_new_window(void *mlx, int size_x, int size_y, char *title);
		int mlx_clear_window(void *mlx, void *win);
		int mlx_destroy_window(void *mlx, void *win);
	Dibujar en la ventana:
		int mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);
		int mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
	Manipular imágenes:
		void *mlx_new_image(void *mlx_ptr, int width, int height);
		char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
		int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
		unsigned int mlx_get_color_value(void *mlx_ptr, int color);
		void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);
		void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
		int mlx_destroy_image(void *mlx_ptr, void *img_ptr);
	Eventos de teclado o ratón
		int mlx_loop(void *mlx_ptr);
		int mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
		int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);
		int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
		int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
