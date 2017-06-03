#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcion.h"

int agregarPelicula(eMovie* movies, int cantMovies){
    char confirm;
    eMovie peliAux;

    printf("Titulo: ");
    fflush(stdin);
    gets(peliAux.titulo);
    formatoTitulo(peliAux.titulo);
    printf("Genero: ");
    fflush(stdin);
    gets(peliAux.genero);
    formatoTitulo(peliAux.genero);
    printf("Duracion (en minutos): ");
    fflush(stdin);
    scanf("%d", &peliAux.duracion);
    printf("Descripcion: ");
    fflush(stdin);
    gets(peliAux.descripcion);
    formatoDescrip(peliAux.descripcion);
    printf("Puntaje(1-5): ");
    fflush(stdin);
    scanf("%d", &peliAux.puntaje);
    printf("Link a la portada: ");
    fflush(stdin);
    gets(peliAux.linkImagen);

    *(movies+cantMovies) = peliAux;
    printf("%s - %s - %d - %s - %d - %s\n", (movies+cantMovies)->titulo, (movies+cantMovies)->genero, (movies+cantMovies)->duracion, (movies+cantMovies)->descripcion, (movies+cantMovies)->puntaje, (movies+cantMovies)->linkImagen);

    printf("Desea cargar esta pelicula? (S/N): ");
    scanf("%c", &confirm);
    if (tolower(confirm) == 's') {
        cantMovies = cantMovies + 1;
        return cantMovies;
    } else {
        return -1;
    }
}

int editarPelicula(eMovie* movies, int cantMovies){
    char confirm;
    char peliBusqueda[50];
    int encontro = 0, opcion;
    eMovie peliAux;

    if (cantMovies == 0) {
        printf("No hay peliculas en el sistema aun.\n");
        return -1;
    } else {
        printf("Ingrese el titulo de la pelicula que desea editar: ");
        fflush(stdin);
        gets(peliBusqueda);

        for (int i=0; i<cantMovies; i++) {
            if (strcmpi(((movies+i)->titulo), peliBusqueda)== 0) {
                encontro = 1;
                printf("%s - %s - %d - %s - %d - %s\n", (movies+i)->titulo, (movies+i)->genero, (movies+i)->duracion, (movies+i)->descripcion, (movies+i)->puntaje, (movies+i)->linkImagen);
                printf("Desea modificar esta pelicula? (S/N): ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (tolower(confirm) == 's') {
                    printf("1. Titulo\n");
                    printf("2. Genero\n");
                    printf("3. Duracion\n");
                    printf("4. Descripcion\n");
                    printf("5. Puntaje\n");
                    printf("6. Link a Imagen\n");
                    printf("Que desea modificar de esta pelicula? ");

                    fflush(stdin);
                    scanf("%d", &opcion);

                    switch(opcion){
                    case 1:
                        printf("Ingrese el nuevo titulo: ");
                        fflush(stdin);
                        gets(peliAux.titulo);
                        formatoTitulo(peliAux.titulo);
                        printf("El nuevo titulo de %s es %s. Desea guardar los cambios? (S/N): ", (movies+i)->titulo, peliAux.titulo);
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if (tolower(confirm) == 's') {
                            strcpy((movies+i)->titulo, peliAux.titulo);
                            return cantMovies;
                        } else {
                            return -1;
                        }
                        break;
                    case 2:
                        printf("Ingrese el nuevo genero: ");
                        fflush(stdin);
                        gets(peliAux.genero);
                        formatoTitulo(peliAux.genero);
                        printf("El nuevo genero de %s es %s. Desea guardar los cambios? (S/N): ", (movies+i)->titulo, peliAux.genero);
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if (tolower(confirm) == 's') {
                            strcpy((movies+i)->genero, peliAux.genero);
                            return cantMovies;
                        } else {
                            return -1;
                        }
                        break;
                    case 3:
                        printf("Ingrese la nueva duracion: ");
                        fflush(stdin);
                        scanf("%d", &peliAux.duracion);
                        printf("La nueva duracion de %s es %s minutos. Desea guardar los cambios? (S/N): ", (movies+i)->titulo, peliAux.duracion);
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if (tolower(confirm) == 's') {
                            (movies+i)->duracion = peliAux.duracion;
                            return cantMovies;
                        } else {
                            return -1;
                        }
                        break;
                    case 4:
                        printf("Ingrese la nueva descripcion: ");
                        fflush(stdin);
                        gets(peliAux.descripcion);
                        formatoDescrip(peliAux.descripcion);
                        printf("La nueva descripcion de %s es %s. Desea guardar los cambios? (S/N): ", (movies+i)->titulo, peliAux.descripcion);
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if (tolower(confirm) == 's') {
                            strcpy((movies+i)->descripcion, peliAux.descripcion);
                            return cantMovies;
                        } else {
                            return -1;
                        }
                        break;
                    case 5:
                        printf("Ingrese el nuevo puntaje: ");
                        fflush(stdin);
                        scanf("%d", &peliAux.puntaje);
                        printf("El nuevo puntaje de %s es %s. Desea guardar los cambios? (S/N): ", (movies+i)->titulo, peliAux.puntaje);
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if (tolower(confirm) == 's') {
                            (movies+i)->puntaje = peliAux.puntaje;
                            return cantMovies;
                        } else {
                            return -1;
                        }
                        break;
                    case 6:
                        printf("Ingrese el nuevo link: ");
                        fflush(stdin);
                        gets(peliAux.linkImagen);
                        strcpy(peliAux.linkImagen, strlwr(peliAux.linkImagen));
                        printf("El nuevo link a la portada de %s es %s. Desea guardar los cambios? (S/N): ", (movies+i)->titulo, peliAux.linkImagen);
                        fflush(stdin);
                        scanf("%c", &confirm);
                        if (tolower(confirm) == 's') {
                            strcpy((movies+i)->linkImagen, peliAux.linkImagen);
                            return cantMovies;
                        } else {
                            return -1;
                        }
                        break;
                    default:
                        printf("Parametro de la pelicula erroneo.\n");
                        return -1;
                        break;
                    }
                } else {
                    return -1;
                }
            }
        }
        if (encontro == 0) {
            printf("No existe ninguna pelicula con ese nombre.\n");
            return -1;
        }
    }
}

int borrarPelicula(eMovie* movies, int cantMovies){
    char confirm;
    char peliBusqueda[50];
    int encontro = 0, opcion;

    if (cantMovies == 0) {
        printf("No hay peliculas en el sistema aun.\n");
        return -1;
    } else {
        printf("Ingrese el titulo de la pelicula que desea editar: ");
        fflush(stdin);
        gets(peliBusqueda);

        for (int i=0; i<cantMovies; i++) {
            if (strcmpi(((movies+i)->titulo), peliBusqueda)== 0) {
                encontro = 1;
                printf("%s - %s - %d - %s - %d - %s\n", (movies+i)->titulo, (movies+i)->genero, (movies+i)->duracion, (movies+i)->descripcion, (movies+i)->puntaje, (movies+i)->linkImagen);
                printf("Desea borrar esta pelicula? (S/N): ");
                fflush(stdin);
                scanf("%c", &confirm);
                if (tolower(confirm) == 's') {
                    if (cantMovies == 1) {
                        cantMovies = cantMovies-1;
                        return cantMovies;
                    } else {
                        for (int j=0; j<cantMovies-i; j++) {
                            *(movies+i+j) = *(movies+i+(j+1));
                        }
                        cantMovies = cantMovies-1;
                        return cantMovies;
                    }
                } else {
                    return -1;
                }
            }
        }
        if (encontro == 0) {
            printf("No existe ninguna pelicula con ese nombre.\n");
            return -1;
        }
    }
}

void generarArchivos(eMovie* movies, char nombre[], int cantMovies){
    char cargaHTML[20000];
    FILE* archivoBase;
    archivoBase = fopen("basePeliculas.dat", "wb");
    fwrite(&cantMovies, sizeof(int), 1, archivoBase);
    for (int i=0; i<cantMovies; i++) {
        fwrite((movies+i), sizeof(eMovie), 1, archivoBase);
    }
    fclose(archivoBase);
    printf("Base de datos generada!\n");
    system("pause");

    FILE* archivoHTML;
    archivoHTML = fopen(nombre, "w");

    strcat(cargaHTML,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
    for (int i=0; i<cantMovies; i++) {
        char puntaje [10], duracion[10];
        itoa((movies+i)->puntaje, puntaje, 10);
        itoa((movies+i)->duracion, duracion, 10);
        strcat(cargaHTML, "<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='");
        strcat(cargaHTML, (movies+i)->linkImagen);
        strcat(cargaHTML, "'alt=''></a><h3><a href='#'>");
        strcat(cargaHTML, (movies+i)->titulo);
        strcat(cargaHTML, "</a></h3><ul><li>Genero: ");
        strcat(cargaHTML, (movies+i)->genero);
        strcat(cargaHTML, "</li><li>Puntaje: ");
        strcat(cargaHTML, puntaje);
        strcat(cargaHTML, "</li><li>Duracion: ");
        strcat(cargaHTML, duracion);
        strcat(cargaHTML, "</li></ul><p>");
        strcat(cargaHTML, (movies+i)->descripcion);
        strcat(cargaHTML, "</p></article>");
    }
    strcat(cargaHTML,"</div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");

    fprintf(archivoHTML,cargaHTML);
    fclose(archivoHTML);
    printf("Pagina HTML generada!\n");
}

int buscarArchivo(char ruta[20]) {
    FILE* archivo;
    if((archivo = fopen(ruta, "r")) == NULL ){
        return 0;
    } else {
        return 1;
    }
}

void cargarPeliculas(FILE* archivo, eMovie* movies, int cantMovies) {
    int cant, i=0;
    eMovie movieAux;
    fseek(archivo, 4, SEEK_SET);
    while (!feof(archivo)) {
        cant = fread(&movieAux, sizeof(eMovie), 1, archivo);
        if (cant != 1) {
            if (feof(archivo)) {
                break;
            } else {
                printf("No se pudo leer el ultimo registro.\n");
                break;
            }
        }
        *(movies+i) = movieAux;
        i++;
    }
    fclose(archivo);
}

void formatoTitulo(char titulo[]){
    titulo = strlwr(titulo);
    titulo[0] = toupper(titulo[0]);
    for (int i = 0; i < strlen(titulo); i++) {
        if (titulo[i] == ' ') {
            titulo[i+1] = toupper(titulo[i+1]);
        }
    }
}

void formatoDescrip(char desc[]){
    desc = strlwr(desc);
    desc[0] = toupper(desc[0]);
    for (int i = 0; i < strlen(desc); i++) {
        if (desc[i] == '.') {
            if (desc[i+1] == ' ') {
                desc[i+2] = toupper(desc[i+2]);
            } else {
                desc[i+1] = toupper(desc[i+1]);
            }
        }
    }
}
