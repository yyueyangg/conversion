# include <stdio.h>
# include <math.h>
# include <ctype.h>
# include <string.h>

int menu(void);
void btod(void);
void dtob(void);
void dtoh(void);
void htod(void);

int menu(void)
{
    int ch;
    printf("------------menu------------\n");
    printf("Only for 8 bits, 0 to 255\n");
    printf("--------------------------\n");
    printf("A) Convert binary to decimal\n");
    printf("B) Convert decimal to binary\n");
    printf("C) Convert hexadecimal to decimal\n");
    printf("D) Convert decimal to hexadecimal\n");
    printf("Q) Quit\n");
    printf("--------------------------\n");
    ch = getchar();
    while(getchar() != '\n' && getchar() != EOF)
        continue;
    return (toupper(ch));
}

void btod()
{
    long long n;
    printf("Enter the binary number to be converted to decimal:\n");
    printf("000000000 to 11111111\n");
    scanf("%lld", &n);
    while(getchar() != '\n' && getchar() != EOF)
        continue;
    
    int dec = 0, i=0, rem;
    if (n>=00000000 && n <=11111111)
    {
        while(n!=0)
        {
            rem = n % 10;
            n /= 10;
            dec += rem * pow(2, i);
            ++i;
        }
        printf("The decimal of this binary number is %d\n", dec);
    }
}


void dtob()
{
    unsigned n;
    printf("Enter the decimal number to be converted to binary\n");
    printf("0 to 255\n");
    scanf("%u", &n);
    while(getchar() != '\n' && getchar() != EOF)
        continue;
    int i;
    static char bin[9];
    for(i=0; i<8; i++)
    {
        bin[i] = n & 0x80 ? '1' : '0';
        n <<= 1;
    }
    bin[i] = '\0';

    printf("The binary of this decimal number is\n");
    for (i=0; i<8; i++)
    {
        printf("%c", bin[i]);
    }
    printf("\n");
}

void htod()
{
    char hex[17];
    long long dec = 0;
    int i, value, len;

    printf("Enter the hexadecimal number to be converted to decimal:\n");
    scanf("%s", hex);
    while(getchar() != '\n' && getchar() != EOF)
        continue;
    len = strlen(hex);
    len--;

    for (i=0; hex[i]!='\0'; i++)
    {
        if(hex[i]>='0' && hex[i]<='9')
        {
            value = hex[i] - 48;
        }
        else if (hex[i]>='a' && hex[i]<='f')
        {
            value = hex[i] - 97 + 10;
        }
        else if (hex[i]>='A' && hex[i]<='F')
        {
            value = hex[i] - 65 + 10;
        }

        dec += value * pow(16, len);
        len--;
    }

    printf("The decimal of this hexadecimal number is %lld\n", dec);
}



void dtoh()
{
    int dec;
    printf("Enter a number:\n");
    scanf("%d", &dec);
    while(getchar() != '\n' && getchar() != EOF)
        continue;
    int i=1, j, rem;
    char hex[17];
    while(dec!=0)
    {
        rem = dec % 16;
        if (rem<10)
        {
            rem += 48;
        }
        else 
        {
            rem += 55;
        }
        hex[i++] = rem;
        dec = dec / 16;
    }

    printf("The hexadecimal of this decimal number is:\n");
    for (j= i-1; j>0; j--)
    {
        printf("%c", hex[j]);
    }

    printf("\n");
}



int main()
{
    int choice = '\0';
    while(choice!='Q')
    {
        choice = menu();
        switch(choice)
        {
            case 'A':
                btod();
                break;
            case 'B':
                dtob();
                break;
            case 'C':
                htod();
                break;
            case 'D':
                dtoh();
            case 'Q':
                break;
        }
    }

    return(0);
}
