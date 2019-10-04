#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 4

void ErroR (void);

int main (int argc, char* argv[])
{   
    char Input[MAX];
    if (argc > 2 || atoi(argv[1]) > 100)
        ErroR();
    if (argv[2] != '\0')
    {
        printf("Enter Percent Value: ");
        fgets(Input,MAX,stdin);
        if (atoi(Input) > 100)
            ErroR();
        for (int i = 0; i < strlen(Input); i++)
            if (isdigit(Input[i]) == 0 && Input[i] != '\n' && Input[i] != '%')
                ErroR();
    }
    else
    { 
        memcpy(Input , argv[1], MAX -1 );
        for (int i = 0; i < strlen(Input); i++)
            if (isdigit(Input[i]) == 0 && Input[i] != '%')
                ErroR();
    }
    //Converter
    int Exact[16] = {0x00};
    int PerCent = atoi(Input);
    int ExactCount = 0;
    for (int i = 0; i < PerCent; i++)
    {
        if  (PerCent % (i + 1) == 0 && i > 1 && 100 / (i + 1) != 1 && (PerCent / ( i + 1)) != (100 / ( i + 1 )) && (( 100 / ( i + 1 )) * (i + 1) == 100))
        {   
            ExactCount++;
            Exact[ExactCount -1] = i + 1;
        }
    }
    int SimplifiedExact = 0;
    for (int i = 0; i < ExactCount; i++)
        {
            printf("   %i\n-------\n   %i\n\n", PerCent / Exact[i], 100 / Exact[i]); 
            if ( i == ExactCount - 1)
                SimplifiedExact = Exact[i];
        }
    if (SimplifiedExact == 0)
        printf("   %i\n------- \n  100\n\n", PerCent);
    if (argv[2] != '\0')
        fgetc(stdin);
    return 0;
}

void ErroR (void)
{
    printf("syntax: fraction %%\n");
    exit(1);
}
