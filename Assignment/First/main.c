#include <stdio.h>
#include <stdlib.h>

int main()
{
    int attend;
    int bit_value;
    // Initial value of attend
    attend = 0x2F; // 00101111 in binary
    printf("attend before do anything \t%X\n", attend);


    bit_value = (attend >> 2) & 1;
    printf("Value of BIT 2 of original attend: %d\n", bit_value);

    // SET BIT 4
    attend = attend | (1 << 4);
    printf("attend after SET BIT 4\t\t%X\n", attend);
    // Reset to the initial value
    attend = 0x2F;

    // RESET BIT 2
    attend = attend & ~(1 << 2);
    printf("attend after RESET BIT 2\t%X\n", attend);
    // Reset to the initial value
    attend = 0x2F;

    // TOGGLE BIT 6
    attend = attend ^ (1 << 6);
    printf("attend after TOGGLE BIT 6\t%X\n", attend);
    return 0;
}
