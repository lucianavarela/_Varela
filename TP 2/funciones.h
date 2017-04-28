#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
     char nombre [50];
     int edad;
     int dni;
     int estado;
} ePersona;

void menu (void);

int buscarLibre(ePersona[], int);

int totalPersonas(ePersona[], int);

void altaPersona(ePersona[], int);

void bajaPersona(ePersona[], int);

void mostrarPersonas(ePersona[], int);

void graficoEdades(ePersona[], int);

#endif // FUNCIONES_H_INCLUDED
