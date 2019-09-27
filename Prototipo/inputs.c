#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "inputs.h"



float getFloat(char* message)
{
    float aux;
    printf("%s",message);
    scanf("%f",&aux);
    return aux;
}



int getInt(char* message)
{
    int aux;
    printf("%s",message);
    scanf("%d",&aux);
    return aux;
}



char getChar(char* message)
{
    char aux;
    printf("%s",message);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

//char getNumberRandom(int since , int until, int start)
//{
//    if(start)
//srand (time(NULL));
//    return since + (rand() % (until + 1 - since)) ;
//}




int isNumericFloat(char str[])
{
    int i=0;
    int cantidadPuntos=0;
    while(str[i] != '\0')
    {
        if (str[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;

        }
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}



int isNumeric(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


int isJustLetters(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}



int isAlfaNumeric(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}



int isTelephone(char str[])
{
    int i=0;
    int contadorGuiones=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
            return 0;
        if(str[i] == '-')
            contadorGuiones++;
        i++;
    }
    if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


void getString(char message[],char input[])
{
    printf("%s",message);
    scanf ("%s", input);
}


int getStringLetters(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isJustLetters(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int getStringNumbers(char message[],char input[])
{
    char aux[256];
    getString(message,aux);
    if(isNumeric(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int getStringNumbersFloat(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(isNumericFloat(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



void getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit,int* input)
{
    char auxStr[256];

    while(1)
    {
        while(!getStringNumbers(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }

        *input = atoi(auxStr);



        if(*input < lowLimit || *input > hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        break;
    }

}

/**
 * \brief Limpia el stdin, similar a fflush
 * \param -
 * \return -
 *
 */
void cleanStdin(void)
{
    int c;
    do
    {
        c = getchar();
    }
    while (c != '\n' && c != EOF);
}


void getValidString(char requestMessage[],char errorMessage[], char input[])
{

    while(1)
    {
        if (!getStringLetters(requestMessage,input))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }

}