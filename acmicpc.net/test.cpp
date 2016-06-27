#include <iostream>

#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
(byte & 0x40 ? '1' : '0'), \
(byte & 0x20 ? '1' : '0'), \
(byte & 0x10 ? '1' : '0'), \
(byte & 0x08 ? '1' : '0'), \
(byte & 0x04 ? '1' : '0'), \
(byte & 0x02 ? '1' : '0'), \
(byte & 0x01 ? '1' : '0')

using namespace std;

int main () {
  int a = 3;
  while(a>0) {
    printf("%c%c%c%c%c%c%c%c : %d : %d\n" , BYTE_TO_BINARY(a), a, a|3);
    a = (a-1) & 3;
  }
  printf("%c%c%c%c%c%c%c%c : %d : %d\n" , BYTE_TO_BINARY(a), a, a|3);

  return 0;
}

