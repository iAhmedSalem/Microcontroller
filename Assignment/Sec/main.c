#include <stdio.h>
#include <stdlib.h>

int set_bit(int var, int bit_num);
int reset_bit(int var, int bit_num);
int toggle_bit(int var, int bit_num);
int read_bit(int var, int bit_num);

int main()
{
    int result1 = set_bit(0b00101111, 4);
    printf("Result after setting bit 4: %d\n", result1); // Expect 63 (0b00111111)

    int result2 = reset_bit(0b00101111, 2);
    printf("Result after resetting bit 2: %d\n", result2); // Expect 43 (0b00101011)

    int result3 = toggle_bit(0b00101111, 6);
    printf("Result after toggling bit 6: %d\n", result3); // Expect 111 (0b01101111)

    int bit_value = read_bit(0b00101111, 3);
    printf("Value of bit 3: %d\n", bit_value); // Expect 1

    return 0;
}

int set_bit(int var, int bit_num)
{
    var = var | (1 << bit_num); // Set the bit at position `bit_num`
    return var;
}

int reset_bit(int var, int bit_num)
{
    var = var & (~(1 << bit_num)); // Reset (clear) the bit at position `bit_num`
    return var;
}

int toggle_bit(int var, int bit_num)
{
    var = var ^ (1 << bit_num); // Toggle (flip) the bit at position `bit_num`
    return var;
}

int read_bit(int var, int bit_num)
{
    return (var >> bit_num) & 1; // Read the bit at position `bit_num`
}
