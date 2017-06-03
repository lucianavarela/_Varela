#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[150];
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movies: el puntero al vector de estructuras a tener un elemento agregado
 *  @param cantMovies: cantidad de peliculas actualmente en la base
 *  @return retorna el numero actualizado de cantidad de peliculas en la base
 */
int agregarPelicula(eMovie* movies, int cantMovies);

/**
 *  Borra una pelicula del archivo binario
 *  @param movies: el puntero al vector de estructuras a tener un elemento eliminado
 *  @param cantMovies: cantidad de peliculas actualmente en la base
 *  @return retorna el numero actualizado de cantidad de peliculas en la base
 */
int borrarPelicula(eMovie* movies, int cantMovies);

/**
 *  Edita una pelicula del archivo binario
 *  @param movies: el puntero al vector de estructuras a tener un elemento editado
 *  @param cantMovies: cantidad de peliculas actualmente en la base
 *  @return retorna el numero actualizado de cantidad de peliculas en la base
 */
int editarPelicula(eMovie* movies, int cantMovies);

/**
 *  Genera un archivo html y un archivo binario con la peliculas actualmente en el sistema
 *  @param movies: el puntero al vector de estructuras a tener un elemento editado
 *  @param nombre: el nombre para el archivo
 *  @param cantMovies: cantidad de peliculas actualmente en la base
 */
void generarArchivos(eMovie* movies, char nombre[], int cantMovies);

/**
 *  Busca si hay un archivo existente
 *  @param ruta: ruta al archivo
 *  @return 1 o 0 dependiendo si encontro el archivo o no
 */
int buscarArchivo(char ruta[]);

/**
 *  Carga las peliculas del archivo existente
 *  @param archivo: el puntero al archivo de la base existente de peliculas
 *  @param movies: el puntero al vector de estructuras donde cargar las peliculas existentes
 *  @param cantMovies: cantidad de peliculas actualmente en la base
 */
void cargarPeliculas(FILE* archivo, eMovie* movies, int cantMovies);

/**
 *  Aplica formato al titulo de las peliculas
 *  @param titulo: el string al cual se le aplicara el formato
 */
void formatoTitulo(char titulo[]);

/**
 *  Aplica formato a la descripcion de las peliculas
 *  @param desc: el string al cual se le aplicara el formato
 */
void formatoDescrip(char desc[]);

#endif // FUNCIONES_H_INCLUDED
