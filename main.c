
//Listing 18.13 Using character test macros to creat an integer to create an
//   integer input function; page 478

//LOOK AT BOOK BECAUSE THIS CODE IS CONFUSING

#include <stdio.h>
#include <ctype.h>

int get_int(void);

int main(void)
{
    int x;
    x = get_int();

    printf("\nYou entered %d.\n", x);

    return 0;

}

int get_int(void)
{

    int ch = 'a';
    int i = 0;
    int sign = 1;

    puts("\nEnter something....");

    printf("\n1...'i' is %d and 'ch' is %c\n", i,ch);
    //skip over any leading whitespace
    while(isspace(ch = getchar()))
        ;

    printf("\n2...'i' is %d and 'ch' is %c", i,ch);
    //if the first character is nonnumeric, unget
    //  the character and return 0
    if(ch != '-' && ch != '+' && !isdigit(ch) && ch != EOF)
    {
        ungetc(ch, stdin);
        return 0;
    }

    //if the first character is a minus sing, set sign accordingly
    if(ch == '-')
        sign = -1; //multiplier to set the "number" negative (ie. minus)

    //if the first character was a plus or minus sign, get the next character
    if(ch == '-' || ch == '+')
        ch = getchar();
    printf("\n3...'i' is %d and 'ch' is %c", i,ch);
    //read characters until a nondigit is input.  Assign values,
    //  multiplied by proper power of 10, to i

    for(i=0; isdigit(ch); ch=(getchar()))
            i = 10 * i + (ch - '0');
    printf("\n4...'i' is %d and 'ch' is %c", i,ch);
    //make result negative if sign is negative
    i *= sign;

    //if EOF was not encountered, a nondigit character must have been read
    //  in, so unget it
    if(ch != EOF)
        ungetc(ch, stdin);

    //return the input value
    return i;



}

