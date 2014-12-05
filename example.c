#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SET_BIT(VAR, BIT)       ( (VAR) |= ( 1 << (BIT) ) )
#define CLEAR_BIT(VAR, BIT)     ( (VAR) &= ( ~( 1 << (BIT) ) ) )
#define FLIP_BIT(VAR, BIT)      ( (VAR) ^= ( 1 << (BIT) ) )
#define CHECK_BIT(VAR, BIT)     ( ( (VAR) & ( 1 << (BIT) ) ) != 0 )

void print_byte(unsigned char *frame, unsigned int len)
{
    int i;
    unsigned char temp[10];
    for (i = 0; i < len; i++) {
        sprintf(temp, "%02X", frame[i]);
        printf("%s", temp);
        if (i + 1 < len ) {
            i++;
            sprintf(temp, "%02X ", frame[i]);
            printf("%s", temp);
        }
    }
    printf ("\n");
}

int main() {
    unsigned char c = 255;
    CLEAR_BIT(c, 7);
    print_byte(&c, 1);
    if(CHECK_BIT(c, 1))
        printf("1ok\n");
    if(CHECK_BIT(c, 7))
        printf("7ok\n");
    return 0;
}
