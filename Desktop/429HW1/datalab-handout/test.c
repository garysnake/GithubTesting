
#include <stdio.h>

/* count digits, white space, others */

int main() {

    int x;
    //-2147483648[0x80000000],31[0x1f])

//x is 1333788672 * z is 8388607 * n is 0
    x = float_i2f(0x80000001);
    printf("final answer is %d", x);
}
int float_i2f(int x) {
  int mask = 1 << 31;
  int sign = x & mask;
  if(!x){
    return 0;
  }else if(x == mask){
    return mask | (158<<23);
  }else if(sign){
    x = ~x + 1;
  }
  // x is positive now
  int rawFrac = 0;
  int bitPos = 0;
  while(x){
    rawFrac = rawFrac + ((1 & x)<<bitPos);
    bitPos = bitPos + 1;
    x = x >> 1;
  }
  rawFrac = rawFrac << (32 - bitPos);
  int finalFrac = (rawFrac&(~mask)) >> 8;
  if (rawFrac&0x80 && ((rawFrac&0x7F) > 0 || finalFrac&1))
      finalFrac = finalFrac + 1;
  return sign + ((bitPos + 126) << 23) + finalFrac;
}
