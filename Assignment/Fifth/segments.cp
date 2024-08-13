#line 1 "C:/Users/ams12/Desktop/Assignment/Fifth/segments.c"

const unsigned char segment_map[] = {
 0b00111111,
 0b00000110,
 0b01011011,
 0b01001111,
 0b01100110,
 0b01101101,
 0b01111101,
 0b00000111,
 0b01111111,
 0b01101111
};

void main() {
 unsigned char count = 0;


 TRISD = 0x00;
 PORTD = 0x00;

 while (1) {

 PORTD = segment_map[count];


 count = (count + 1) % 10;


 Delay_ms(1000);
 }
}
