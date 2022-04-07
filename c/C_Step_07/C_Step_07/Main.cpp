#include <stdio.h>


int main(void)
{
    //배열 방식
    /*
    int iArrayA[5] = { 1, 2, 3, 4, 5 };
    int iArrayB[] = { 1, 2, 3, 4, 5 };
    int iArrayC[5] = { 1, 2 };
    int iArrayD[5] = { 0 };

    for (int i = 0; i < 5; i++)
    {
        printf_s("%d번-[A : %d] [B : %d] [C : %d] [D : %d]\n\n", 
            i, iArrayA[i], iArrayB[i], iArrayC[i], iArrayD[i]);
    }
    */
    



    /*
    int iArray[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf_s("%d\t", iArray[i][j]);
            
            if (j == 2)
            {
                printf_s("\n");
            }
        }
    }
    */
            
    //문자 배열//
    /*
    char str1[5] = {'g', 'o', 'o', 'd', '\0'};
    char str2[5] = "good";

    printf_s("%s\n", str1);
    printf_s("%s", str2);
    */
    
    

    char str1[6] = { 'g', 'o', 'o', 'd', ' ', '\0' };
    char str2[9] = { 'm', 'o', 'r', 'n', 'i', 'n', 'g', '!', '\0' };

    for (int i = 0; i < 5; i++)
    {
        printf_s("%c", str1[i]);   
    }
    
    printf_s("%s\n", str2);
    


	return 0;
}