#include <stdio.h>
#include <stdlib.h>
#include "funcion.h"
#define RUTA "basePeliculas.dat"

int main() {
    char seguir = 's', salir;
    int opcion = 0, result, existeArchivo, cantPeliculas = 0;
    FILE* archivoBase;

    eMovie* misPeliculas;
    misPeliculas = (eMovie*) malloc (sizeof(eMovie));

    existeArchivo = buscarArchivo(RUTA);
    if (existeArchivo == 0) {
        printf("BIENVENIDO! Empecemos a generar la base de sus peliculas.\n");
        system("pause");
        system("cls");
    } else {
        archivoBase = fopen(RUTA, "rb+");
        fread(&cantPeliculas, sizeof(int), 1, archivoBase);
        misPeliculas = (eMovie*) realloc (misPeliculas, (sizeof(eMovie)*cantPeliculas));
        cargarPeliculas(archivoBase, misPeliculas, cantPeliculas);
    }

    do {
        printf("1- Agregar pelicula\n");
        printf("2- Editar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        fflush(stdin);
        scanf("%d",&opcion);

        switch(opcion) {
            case 1:
                misPeliculas = realloc (misPeliculas, sizeof(eMovie)*(cantPeliculas+1));
                result = agregarPelicula(misPeliculas, cantPeliculas);
                if (cantPeliculas == result-1) {
                    printf("Carga exitosa!\n");
                    cantPeliculas = result;
                } else {
                    printf("Carga cancelada!\n");
                    misPeliculas = realloc (misPeliculas, sizeof(eMovie)*(cantPeliculas-1));
                }
                break;
            case 2:
                result = editarPelicula(misPeliculas, cantPeliculas);
                if (cantPeliculas == result) {
                    printf("Modificacion exitosa!\n");
                } else {
                    printf("Modificacion cancelada!\n");
                }
                break;
            case 3:
                result = borrarPelicula(misPeliculas, cantPeliculas);
                if (cantPeliculas == result+1) {
                    printf("Eliminacion exitosa!\n");
                    cantPeliculas = result;
                    misPeliculas = realloc (misPeliculas, sizeof(eMovie)*(cantPeliculas));
                } else {
                    printf("Eliminacion cancelada!\n");
                }
                break;
            case 4:
                generarArchivos(misPeliculas, "template\\index.html", cantPeliculas);
                break;
            case 5:
                printf("Seguro que desea salir? Si realizo cambios y no exporto una nueva version, esos cambios se perderan (S/N): ");
                fflush(stdin);
                scanf("%c", &salir);
                if (tolower(salir) == 's') {
                    seguir = 'n';
                    printf("Saliendo...\n");
                } else {
                    printf("Salida cancelada\n");
                }
                break;
            default:
                printf("Ingrese una opcion valida del menu.\n");
                break;
        }
        system("pause");
        system("cls");
    } while(seguir=='s');
    return 0;
}
