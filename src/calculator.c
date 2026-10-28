#include "calculator.h"
#include <stdio.h>
#include <math.h>

void do_next_op(char operator, double right_operand, double *accumulator)
{
    // Selveste regnemaskinen bestående af et switch-statement. Hver operator har sin egen case, og få af casesne har undtagelser.
    switch (operator)
    {
    case '+':
        *accumulator += right_operand;
        break;
    case '-':
        *accumulator -= right_operand;
        break;
    case '*':
        *accumulator *= right_operand;
        break;
    case '/':
        if (right_operand == 0)
        {
            break; // Ingen division med 0.
        }
        *accumulator /= right_operand;
        break;
    case '^':
        if (right_operand == 0)
        {
            *accumulator = 1; // Et tal opløftet i 0 giver 1.
            break;
        }
        *accumulator = pow(*accumulator, right_operand);
        break;
    case '#':
        if (*accumulator < 0)
        {
            break; // Ingen kvadratrod på negative tal, som opgavebeskrivelsen beder om.
        }
        *accumulator = sqrt(*accumulator);
        break;
    case '%':
        *accumulator = -*accumulator; // Sætter minus foran accumulatoren. så hvis den pt er -25 --> -(-25) = 25
        break;
    case '!':
        if (*accumulator == 0)
        {
            break;
        }
        *accumulator = 1 / *accumulator;
        break;
    default:
        printf("Invalid operator"); // Kun de ovenstående operators er gyldige på denne lommeregner.
    }
}