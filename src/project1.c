#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// "Interfacen" på lommeregneren, hvor brugeren promptes. Accumulater er en pointer, fordi den bliver sendt rundt mellem funktionerne.
double run_calculator(double *accumulator, char operator, double right_operand); 

// Selveste regnemaskinen
void do_next_op(char operator, double right_operand, double *accumulator);

int main(void)
{
    double accumulator = 0.0; // Tallet på "skærmen" af lommeregneren.
    char operator = '\0'; // Operatoren, fx plus, minus osv.
    double right_operand = 0.0; // Tallet som brugeren taster på lommeregneren.
    printf("Denne lommeregner kan følgende:\n\nPlus\nMinus\nGange\nDivision\nPotens\nKvadratrod (#)\nVende fortegnet (%%)\nDividere 1 med akkumulatoren (!)\n\nAfslut regnemaskinen med 'q'");
    run_calculator(&accumulator, operator, right_operand); // Kalder lommeregner-funktionen.
    return 0;
}

double run_calculator(double *accumulator, char operator, double right_operand)
{
    // Brugeren promptes til at indtaste operator og operand i et do-while loop. den skal do'es while operator'en ikke er q.
    // og yderligere if operatoren er q, så slutter programmet.
    do
    {
        printf("\nIndtast operator og operand: ");
        scanf(" %c", &operator); // Brugeren indtaster en operator

        if (operator == 'q')
        {
            printf("Endelig resultat: %lf", *accumulator);
            break;
        }

        if (operator == '+' || operator == '-' ||
            operator == '*' || operator == '/' ||
            operator == '^')
        {
            scanf("%lf", &right_operand);
            // De to scanf'er er adskilt i to, da en samlet scanf ville forvente både et tegn og et tal, så q alene ville få den til at vente på et tal..
        }
        do_next_op(operator, right_operand, accumulator); // Her kaldes do_next_op-funktionen inde i run_calculator
        printf("\nResultat indtil videre: %lf\n", *accumulator);
    } while (
        operator != 'q');

    return 0;
}
