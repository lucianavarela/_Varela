#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>


void menu () {
    char seguir='s';
    int opcion=0;

    while(seguir=='s') {
    	printf("------------ CALCULADORA ------------\n");
    	//Ambos ifs cumplen la funcion de remplazar x e y con ambos operandos.
        if(flagA=='0'){
            printf("1- Ingresar 1er operando (A=x)\n");
        } else {
            printf("1- Ingresar 1er operando (A=%.2f)\n", numA);
        }
        if(flagB=='0'){
            printf("2- Ingresar 2do operando (B=y)\n");
        } else {
            printf("2- Ingresar 2do operando (B=%.2f)\n", numB);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        if (opcion > 1 || opcion < 9) {
            switch(opcion)
            {
                case 1:
                    ingresoNumA();
                    break;
                case 2:
                    ingresoNumB();
                    break;
                case 3:
                    //Validacion para confirmar que se hayan ingresado ambos operandos antes de realizar una operacion.
                    if (flagA == '0' || flagB == '0'){
                        printf("Debe ingresar primero ambos operandos.\n");
                    } else {
                        suma(numA, numB);
                    }
                    break;
                case 4:
                    if (flagA == '0' || flagB == '0'){
                        printf("Debe ingresar primero ambos operandos.\n");
                    } else {
                        resta(numA, numB);
                    }
                    break;
                case 5:
                    if (flagA == '0' || flagB == '0'){
                        printf("Debe ingresar primero ambos operandos.\n");
                    } else {
                        division(numA, numB);
                    }
                    break;
                case 6:
                    if (flagA == '0' || flagB == '0'){
                        printf("Debe ingresar primero ambos operandos.\n");
                    } else {
                        multiplicacion(numA, numB);
                    }
                    break;
                case 7:
                    if (flagA == '0'){
                        printf("Debe ingresar el primer operando.\n");
                    } else {
                        factorial(numA);
                    }
                    break;
                case 8:
                    if (flagA == '0' || flagB == '0'){
                        printf("Debe ingresar primero ambos operandos.\n");
                    } else {
                        suma(numA, numB);
                        resta(numA, numB);
                        division(numA, numB);
                        multiplicacion(numA, numB);
                        factorial(numA);
                    }
                    break;
                case 9:
                    seguir = 'n';
                    break;
            }
            //Funciones para que el sistema pause despues de cada operacion, y luego se limpie al consola.
            system("pause");
            system("cls");
        } else {
            printf("Debe ingresar un menu valido.");
        }
    }
}

//Funcion para ingresar el primer operando.
void ingresoNumA() {
    printf("Ingrese el primer operando: ");
    fflush(stdin);
    scanf("%f", &numA);
    flagA='1';
}

//Funcion para ingresar el segundo operando.
void ingresoNumB() {
    printf("Ingrese el segundo operando: ");
    fflush(stdin);
    scanf("%f", &numB);
    flagB='1';
}

//Funcion para calcular la suma.
void suma(float numA, float numB) {
    float suma;
    suma = numA + numB;
    printf("El resultado de A + B es: %.2f\n", suma);
}

//Funcion para calcular la resta.
void resta(float numA, float numB) {
    float resta;
    resta = numA - numB;
    printf("El resultado de A - B es: %.2f\n", resta);
}

//Funcion para calcular la division.
void division(float numA, float numB) {
    float div;
    //Validacion para contemplar el caso en el que el divisor el 0.
    if (numB == 0) {
        printf("La division no se puede hacer ya que el divisor es 0.\n");
    } else {
        div = numA / numB;
        printf("El resultado de A / B es: %.2f\n", div);
    }
}

//Funcion para calcular la multiplicacion.
void multiplicacion(float numA, float numB) {
    float multip;
    multip = numA * numB;
    printf("El resultado de A * B es: %.2f\n", multip);
}

//Funcion para calcular el factorial.
void factorial(float numA) {
	int i;
	int validarInt = numA;
	//Validacion para contemplar el caso en que se quiera calcular el factorial con un numero decimal o negativo.
	if (numA != validarInt) {
        printf("El factorial solo se puede calcular partiendo de un numero entero.\n");
    } else if (numA < 0) {
    	printf("El factorial solo se puede calcular partiendo de un numero positivo.\n");
    } else if (numA > 20) {
    	printf("El numero es demasiado grande para resolver el factorial.\n");
    } else {
		long long int acum = 1;
		for (i=1; i<=numA; i++) {
			acum *= i;
		}
		printf("El resultado de A!: %lld\n", acum);
	}
}
