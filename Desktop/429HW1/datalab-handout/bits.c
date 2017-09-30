/*
 * CS:APP Data Lab
 *
 * <Shijing Zhong>
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    // law of &
    return ~(~x|~y);
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    // make a mask 0xFF to truncate the far right byte
    return (x >> (8*n)) & 0xFF;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n) {
    // produce a mask on the accordingly, and when n = 0
    // the exception still works here, since the shifting turn 31,
    // won't invoke the 32 shifting overflow error
    return (x >> n) & ~((~1) << (32 + (~n)));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    //make a mask of 0001 0001...
    int maskTemp = (0x11 << 16) | 0x11;
    int mask = maskTemp | (maskTemp << 8);
    // start accumulating each byte's 1
    int total = (x & mask) + ((x >> 1) & mask);
    total = total + ((x >> 2) & mask);
    total = total + ((x >> 3) & mask);
    // start accumulating two bytes' ones together
    total = total + (total >> 16);
    // add them all up
    return (0xf & total) + (0xf & (total >> 4)) + (0xf & (total >> 8)) + (0xf & (total >> 12));
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    int negativeX = ~x + 1;
    // except 0, no sign for both negative and positive
    // even Tmin has two signs, exception yields
    return ((x | negativeX) >> 31) + 1;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + < < >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(){
    // ignore meda
    return 1 << 31;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    int numShift = 32 + (~n + 1);//32-n
    // truncated the extra left bits, see if the have any
    int numFit = (x << numShift) >> numShift;
    //if they differ,it cannot be represent
    return !(numFit ^ x);
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -21544
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */

int divpwr2(int x, int n) {
    // round zero works for positive value
    int unroundedVal = (x >> n);
    // for negative value, if positive, not going to add this
    int additionalRounding = (x >> 31) & ((~0 + (1 << n)) & x);
    return  unroundedVal + !!additionalRounding;
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    //from book
    return ~x + 1;
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    //isPositive when equals 0
    int isPositive =(1 << 31) & x;
    //exclude 0 here
    return !(isPositive | !x);
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int ySign = y >> 31;
    int xSign = x >> 31;
    int signlessComparison = !((y + (~x + 1)) >> 31);
    // special case y+ and x- always return 1; y- and x+ return 0
    return (signlessComparison & ((!ySign) | xSign)) | ((!ySign) & xSign);
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    int mask16 = (~0) << 16;
    // if the index is more than 16 index increases by 16
    int bit16 = (!!(x & mask16)) << 4;
    x = x >> bit16;
    // the rest operations are similar
    int mask8 = 0xFF << 8;
    int bit8 = (!!(x & mask8)) << 3;
    x = x >> bit8;
    int mask4 = 0xF0;
    int bit4 = (!!(x & mask4)) << 2;
    x = x >> bit4;
    int mask2 = 0xC;
    int bit2 = (!!(x & mask2)) << 1;
    x = x >> bit2;
    int bit1 = (!!(x & 2));
    //add them up, no overlaps
    return bit16 + bit8 + bit4 + bit2 + bit1;
}
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    //get the exponent
    unsigned exponent = (uf >> 23) & 0xFF;
    //get the fraction number
    unsigned frac = (~0 + (1<<23)) & uf;
    //check if exponent has anything
    if(exponent == 0xFF && frac){
        return uf;
    }
    //flip the sign and the rest remains unchang
    return uf ^ (1 << 31);
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    unsigned mask = 1 << 31;
    //return special cases 0 and Tmin
    unsigned sign = x & mask;
    if(!x){
        return 0;
    }else if(!(x ^ (mask))){
        return mask + (158 << 23);
    // switch signs for easier steps
    }else if(sign){
        x = ~x + 1;
    }
    // x is positive now
    unsigned frac;
    unsigned exp = 0;
    while (!(x & (1 << 31))) {
        exp = exp + 1;
        x = x << 1;
    }
    frac = (x&(~mask)) >> 8;
    //rounding delete 0x7F
    if ((x & 0x7F || 0x1 & frac)&&(x & 0x80)){
        frac++;
    }
    exp = (158 - exp) << 23;
    return sign + exp + frac;
}
/*
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {

  unsigned signMask = 1<<31;
  unsigned sign = uf & signMask;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned fracMask = ~0 + (1<<23);
  unsigned frac = fracMask & uf;
  // return itself for nan and infinity, also 0
  if(exp == 0xFF || (!uf) || (uf == signMask)){
      return uf;
  }
  // if exponent is not zero, just add 1
  if (exp) {
    exp = exp + 1;
  // if exponent is zero, but also the frac cannot hold more bits
  } else if (frac == fracMask) {
    frac = frac - 1;
    exp = exp + 1;
  // if exponent is zero, else case, then shift to the left once
  } else {
    frac = frac << 1;
  }

  return sign + (exp << 23) + frac;
}
