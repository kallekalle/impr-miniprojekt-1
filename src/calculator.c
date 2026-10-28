#include "calculator.h"
#include <stdio.h>
#include <math.h>

void do_next_op(char operator, double right_operand, double *accumulator)
{
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
            break;
        }
        *accumulator /= right_operand;
        break;
    case '^':
        if (right_operand == 0)
        {
            *accumulator = 1;
            break;
        }
        *accumulator = pow(*accumulator, right_operand);
        break;
    case '#':
        if (*accumulator < 0)
        {
            break;
        }
        *accumulator = sqrt(*accumulator);
        break;
    case '%':
        if (*accumulator < 0)
        {
            *accumulator = -*accumulator;
            break;
        }
        else
        {
            *accumulator -= (*accumulator * 2);
            break;
        }
        break;
    case '!':
        if (*accumulator == 0)
        {
            break;
        }
        *accumulator = 1 / *accumulator;
        break;
    default:
        printf("Invalid operator");
    }
}