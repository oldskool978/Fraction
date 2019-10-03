#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int main (void)
{   
    char Input[MAX];
    fgets(Input,MAX,stdin);
    
    //Converter
    int Exact[10] = {0x00};
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
    return 0;
}
