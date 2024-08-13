// Define the 7-segment patterns for digits 0-9
const unsigned char segment_map[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00000111, // 7
    0b01111111, // 8
    0b01101111  // 9
};

void main() {
    unsigned char count = 0;

    // Initialize PORTD as output
    TRISD = 0x00; // Set PORTD as output (all pins)
    PORTD = 0x00; // Clear PORTD

    while (1) {
        // Display current count on 7-segment display
        PORTD = segment_map[count];

        // Increment counter and wrap around at 10
        count = (count + 1) % 10;

        // Delay for 1 second
        Delay_ms(1000); // Adjust delay based on your clock frequency
    }
}