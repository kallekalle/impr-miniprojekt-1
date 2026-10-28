#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double run_calculator(double *accumulator, char operator, double right_operand);
// double scan_data(char operator, double right_operand);
void do_next_op(char operator, double right_operand, double *accumulator);

int main(void)
{
    double accumulator = 0.0;
    char operator = '\0';
    double right_operand = 0.0;
    printf("Denne lommeregner kan følgende:\n\nPlus\nMinus\nGange\nDivision\nPotens\nKvadratrod (#)\nVende fortegnet (%%)\nDividere 1 med akkumulatoren (!)\n\nAfslut regnemaskinen med 'q'");
    run_calculator(&accumulator, operator, right_operand);
    return 0;
}

double run_calculator(double *accumulator, char operator, double right_operand)
{
    do
    {
        printf("\nIndtast operator og operand: ");
        scanf(" %c", &operator);

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
        }
        do_next_op(operator, right_operand, accumulator);
        printf("\nResultat indtil videre: %lf\n", *accumulator);
    } while (
        operator != 'q');

    return 0;
}
