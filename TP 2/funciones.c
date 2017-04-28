#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define A 20

void menu () {
    ePersona listaPersonas[A] = {"", 0, 0, 0};
    char seguir = 's';
    int opcion;

    while(seguir=='s') {
        printf("\t-- LOG DE PERSONAS --\nElige una opcion:\n");
        printf("1. Agregar una persona\n");
        printf("2. Borrar una persona\n");
        printf("3. Imprimir lista ordenada por nombre\n");
        printf("4. Imprimir grafico de edades\n");
        printf("5. Salir\n");

        fflush(stdin);
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                altaPersona(listaPersonas, A);
                break;
            case 2:
                bajaPersona(listaPersonas, A);
                break;
            case 3:
                mostrarPersonas(listaPersonas, A);
                break;
            case 4:
                graficoEdades(listaPersonas, A);
                break;
            case 5:
                printf("Saliendo...\n");
                seguir = 'n';
                break;
            default:
                printf("-> Debe ingresar una opcion valida del menu.\n");
        }
        system("pause");
        system("cls");
    }
}

int buscarLibre(ePersona lasPersonas[], int tam) {
    int posicion = -1;
    for (int i = 0; i < tam; i++) {
        if (lasPersonas[i].estado==0) {
            posicion = i;
            break;
        }
    }
    return posicion;
}

int totalPersonas(ePersona lasPersonas[], int tam) {
    int cantPersonas = 0;
    for (int i = 0; i < tam; i++) {
        if (lasPersonas[i].estado==1) {
            cantPersonas++;
        }
    }
    return cantPersonas;
}

void altaPersona(ePersona lasPersonas[], int tam) {
    int posicion = buscarLibre(lasPersonas, tam);
    if (posicion == -1) {
        printf("-> No hay espacio para dar de alta mas personas. Debera borrar una persona para agregar una nueva.\n");
    } else {
        ePersona personaAux;
        char nombreAux[50], nombreAuxSoloLetras[50], edadAux[30], dniAux[30];
        int ok, ok2, okMenu, isNaN, dniDuplicado;

        //Ingreso del nombre
        do {
            ok = 0;
            isNaN = 0;
            printf("Ingrese el nombre de la persona: ");
            fflush(stdin);
            gets(nombreAux);
            for (int i=0; i<(strlen(nombreAux)); i++) {
                if (isdigit(nombreAux[i]) == 1) {
                    printf("-> No puede ingresar numeros en el nombre.\n");
                    isNaN = 1;
                    break;
                }
            }
            if (isNaN == 0) {
                ok = 1;
                strcpy(nombreAuxSoloLetras, nombreAux);
            }
        } while (ok == 0);
        strcpy(nombreAuxSoloLetras, strlwr(nombreAuxSoloLetras));
        nombreAuxSoloLetras[0] = toupper(nombreAuxSoloLetras[0]);
        for (int j = 0; j < strlen(nombreAuxSoloLetras); j++) {
            if (nombreAuxSoloLetras[j] == ' ') {
                nombreAuxSoloLetras[j+1] = toupper(nombreAuxSoloLetras[j+1]);
            }
        }
        strcpy(lasPersonas[posicion].nombre, nombreAuxSoloLetras);

        //Ingreso de la edad
        do {
            ok = 0;
            isNaN = 0;
            printf("Ingrese su edad: ");
            fflush(stdin);
            gets(edadAux);
            for (int i=0; i<(strlen(edadAux)); i++) {
                if (isdigit(edadAux[i]) == 0) {
                    printf("-> Debe ingresar una edad numerica.\n");
                    isNaN = 1;
                    break;
                }
            }
            if (isNaN == 0) {
                ok = 1;
                lasPersonas[posicion].edad = atoi(edadAux);
            }
        } while (ok == 0);

        //Ingreso del DNI
        do {
            do {
                ok = 0;
                ok2 = 0;
                isNaN = 0;
                dniDuplicado = 0;
                printf("Ingrese su DNI (sin puntos ni espacios): ");
                fflush(stdin);
                gets(dniAux);
                for (int i=0; i<(strlen(dniAux)); i++) {
                    if (isdigit(dniAux[i]) == 0) {
                        printf("-> Debe ingresar un DNI numerico.\n");
                        isNaN = 1;
                        break;
                    }
                }
                if (isNaN == 0) {
                    if (strlen(dniAux) != 8) {
                        printf("-> Debe ingresar el DNI completo.\n");
                    } else {
                        ok = 1;
                    }
                }
            } while (ok == 0);
            for (int i=0; i<tam; i++) {
                if (lasPersonas[i].dni == atoi(dniAux)) {
                    dniDuplicado = 1;
                    printf("-> La persona con este DNI ya ha sido ingresada al sistema.\n");
                    printf("Ingrese 1 para reingresar el DNI, 2 para reingresar otra persona u otra tecla para volver al menu: ");
                    fflush(stdin);
                    okMenu = getche();
                    printf("\n");
                    switch (okMenu) {
                        case '1':
                            ok = 0;
                            break;
                        case '2':
                            altaPersona(lasPersonas, tam);
                            ok2 = 3;
                            break;
                        default:
                            printf("-> Carga cancelada\n");
                            ok2 = 3;
                            break;
                    }
                }
            }
            if(ok2 == 3) {
                break;
            }
            if (dniDuplicado == 0) {
                lasPersonas[posicion].dni = atoi(dniAux);
                lasPersonas[posicion].estado = 1;
                printf("-> Carga exitosa\n");
                ok2 = 1;
                break;
            }
        } while (ok2 == 0);
    }
}

void mostrarPersonas(ePersona lasPersonas[], int tam) {
    int cantPersonas = totalPersonas(lasPersonas, tam);
    if (cantPersonas == 0) {
        printf("-> No hay personas en la base de datos.\n");
    } else {
        ePersona personaAux;
        char nombre[] = {"NOMBRE"};
        printf("%35s\tEDAD\tDNI\n", nombre);
        for (int i = 0; i < tam-1; i++) {
            for (int j = i+1; j < tam; j++) {
                if (strcasecmp(lasPersonas[i].nombre,lasPersonas[j].nombre) > 0) {
                    personaAux = lasPersonas[i];
                    lasPersonas[i] = lasPersonas[j];
                    lasPersonas[j] = personaAux;
                }
            }
        }
        for (int i = 0; i < tam; i++) {
            if (lasPersonas[i].estado == 1) {
                printf("%35s\t%d\t%d\n", lasPersonas[i].nombre, lasPersonas[i].edad, lasPersonas[i].dni);
            }
        }
    }
}

void bajaPersona(ePersona lasPersonas[], int tam) {
    int flagEncontro = 0, ok = 0, isNaN = 0;
    char confirm = 'n', confirm2 = 'n', dniAux[30];
    int cantPersonas = totalPersonas(lasPersonas, tam);
    if (cantPersonas == 0) {
        printf("-> No hay personas en la base de datos.\n");
    } else {
        int dniBusqueda;
        do {
            ok = 0;
            isNaN = 0;
            printf("Ingrese el DNI de la persona que desea borrar (sin puntos ni espacios): ");
            fflush(stdin);
            gets(dniAux);
            for (int i=0; i<(strlen(dniAux)); i++) {
                if (isdigit(dniAux[i]) == 0) {
                    printf("-> Debe ingresar un DNI numerico.\n");
                    isNaN = 1;
                    break;
                }
            }
            if (isNaN == 0) {
                if (strlen(dniAux) != 8) {
                    printf("-> Debe ingresar el DNI completo.\n");
                } else {
                    dniBusqueda = atoi(dniAux);
                    ok = 1;
                }
            }
        } while (ok == 0);
        for (int i = 0; i < tam; i++) {
            if (lasPersonas[i].dni == dniBusqueda && lasPersonas[i].estado == 1) {
                printf("%s\t%d\t%d\n", lasPersonas[i].nombre, lasPersonas[i].edad, lasPersonas[i].dni);
                printf("Desea eliminar a %s? (S/N): ", lasPersonas[i].nombre);
                fflush(stdin);
                confirm = getche();
                if (tolower(confirm) == 's') {
                    lasPersonas[i].estado = 0;
                    printf("\n-> %s se ha eliminado.");
                } else {
                    printf("\n-> Operacion cancelada.");
                }
                flagEncontro = 1;
                break;
            }
        }
        if (flagEncontro == 0) {
            printf("\n-> No existe ninguna persona con ese DNI.");
        }
        printf("\nPresione 1 para ingresar una nueva busqueda o 2 para regresar al menu: ");
        fflush(stdin);
            confirm2 = getche();
            if (confirm2 == '1') {
                printf("\n\n");
                bajaPersona(lasPersonas, tam);
            } else {
                printf("\n");
            }
    }
}

void graficoEdades(ePersona lasPersonas[], int tam) {
    int cantPersonas = totalPersonas(lasPersonas, tam);
    if (cantPersonas == 0) {
        printf("-> No hay personas en la base de datos.\n");
    } else {
        int primerFranja = 0, segundaFranja = 0, terceraFranja = 0;
        for (int i=0;i<tam;i++) {
            if (lasPersonas[i].estado == 1) {
                if (lasPersonas[i].edad > 0 && lasPersonas[i].edad <= 18) {
                    primerFranja++;
                } else if (lasPersonas[i].edad > 18 && lasPersonas[i].edad < 35) {
                    segundaFranja++;
                } else {
                    terceraFranja ++;
                }
            }
        }

        int tamGrafico = primerFranja;
        if (segundaFranja > tamGrafico) {
            tamGrafico = segundaFranja;
        }
        if (terceraFranja > tamGrafico) {
            tamGrafico = terceraFranja;
        }

        char primerF[tamGrafico], segundaF[tamGrafico], terceraF[tamGrafico];
        for (int i=0; i<tamGrafico; i++) {
            primerF[i] = ' ';
            segundaF[i] = ' ';
            terceraF[i] = ' ';
            if (i < primerFranja) {
                primerF[i] = '*';
            } else {
                primerF[i] = ' ';
            }
            if (i < segundaFranja) {
                segundaF[i] = '*';
            } else {
                segundaF[i] = ' ';
            }
            if (i < terceraFranja) {
                terceraF[i] = '*';
            } else {
                terceraF[i] = ' ';
            }
        }

        for (int i=tamGrafico-1; i>=0; i--) {
            printf(" %c     %c     %c\n", primerF[i], segundaF[i], terceraF[i]);
        }
        printf("<18  19-35  >35\n");
    }
}
