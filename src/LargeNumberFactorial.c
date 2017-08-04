#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int myStrlen(char *str)
{
    int i =0;

    while(str[i++]);

    return i-1;
}

char* myStrRev(char *str)
{
    int i = 0;
    int j = myStrlen(str)-1;

    while(i<j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

    return str;
}



char* multiply(char* num1, char* num2)
{
    int n1 = myStrlen(num1);
    int n2 = myStrlen(num2);
    int shifter = 0;
    char *val =  (char *)calloc(sizeof(char),n1+n2+1);

    int i,j;
    for(j=n2-1;j>=0;j--)
    {
        int k = n1+n2 -1 - shifter;
        int multipler = num2[j] - '0';

        for(i=n1-1;i>=0;i--)
        {
            int temp = (multipler * (num1[i] - '0')) + (val[k] == '\0'? 0 : val[k] - '0');
            val[k--] =  temp%10 + '0';
            if(temp > 9)
            {
                val[k] = ((val[k] == '\0'? 0 : val[k] - '0') + (temp/10)) + '0';
            }
        }

        shifter++;
    }

    int nonNullIndex=0;

    while(val[nonNullIndex] == '0' || val[nonNullIndex] == '\0') nonNullIndex++;

    return val+nonNullIndex;

}


char* convertToString(int num)
{
    long int n = num;
    int i=0,j=0;
    while(n)
    {
        i++;
        n/=10;
    }

    char* str = (char *)calloc(sizeof(char),i+1);

    while(num)
    {
        str[j++] = num%10 + '0';
        num /=10;
    }

    myStrRev(str);
    return str;

}

char* factorial(int n)
{
    char* result = "1";
    int i;
    for(i=1;i<=n;i++)
    {
        result = multiply(result,convertToString(i));
    }

    return result;
}

int main()
{
    int num = 0;

    printf("Enter number for factorial: ");
    scanf("%d", &num);

    printf("\nfactorial of %d = %d! = %s\n\n", num,num,factorial(num));


    return 0;
}



