/*
 * This file contains some small mathematic functions that are not
 * implemented in the driver.
 * 
 * The functions:
 * 
 *   pow(a,b) computes a to the power of b.
 *     Example:
 *     pow(3,2)  // returns 9
 *   gauss_random
 *     Example:
 *     gaus_random()  // returned 0.243673 when I tried it
 *   abs(x) returns the absolute value of x
 *     Example:
 *     abs(-3.7)  // returns 3.7
 */

#include <limits.h>
#include <math.h>

#if !__EFUN_DEFINED__(max)  // Alfe 2002-Apr-26
mixed max(mixed a, mixed b) {
  return ((to_float(a) > to_float(b)) ? a : b);
}
#endif

#if 0  // this is efun now, Coogan, 23-Aug-1999
mixed pow(mixed a,mixed b) { 
  status int_flag;
  mixed result;
  int_flag = (intp(a) && intp(b));
  if (intp(a))
    a = to_float(a);
  if (intp(b))
    b = to_float(b);
  result = exp(log(a) * b); 
  if (int_flag) 
    result = to_int(result+0.5);
  return result;
}

mixed abs(mixed x) {
  if (intp(x))
    return (x<0 ? -x : x);
  else
    return (x<0.0 ? -x : x);
}
#endif

/*
 * Seien U1 und U2 gleichverteilte und unabhaengige Zufallszahlen im Intervall 
 * (0,1);
 * dann sind die beiden Zufallszahlen
 * 
 * G1 = sqrt(-2 ln(U1))*cos(2 pi U2)  und G2 = sqrt(-2 ln(U1))*sin(2 pi U2)
 * 
 * jeweils gaussverteilt und unabhaengig mit Erwartungswert 0 und
 * Standardabweichung 1. a*G1 + b (bzw. auch a*G2+b) ist gaussverteilt mit
 * Erwartungswert b und Standardabweichung a.
 * 
 * Literatur:
 * 
 * 1. http://www.cs.tu-berlin.de/~async/nn.html (Statistikteil)
 * 2. Numerical Recipes in C
 */
float gauss_random() {
  mixed h;
  float u1,u2;
  h = to_float(INT_MAX) + 1.0;
  u1 = (to_float(random(INT_MAX))+1.0) / (float) h;
  u2 = (to_float(random(INT_MAX))+1.0) / (float) h;
  return sqrt(-2*log(u1)) * cos(u2*PI2);
}

float limited_gauss_random(float min, float max, float div) {
  mixed h;
  float u1, u2;
  h = to_float(INT_MAX) + 1.0;
  u1 = (to_float(random(INT_MAX))+1.0) / (float) h;
  u2 = (to_float(random(INT_MAX))+1.0) / (float) h;
  h = (max-min)/2.0/div;
  h = exp(-h*h/2.0);
  return sqrt(-2*log(u1*(1.0-h)+h)) * cos(u2*PI2) * div + (max+min)/2.0;
}

#if 0  // efun now, Coogan, 23-Aug-1999
float atan2(float x,float y) {
  if (x < 0.0)
    return PI + atan(y/x);
  if (x > 0.0)
    return atan(y/x);
  return y<0.0? -PI_2 : PI_2;
}
#else  // but with switched arguments! :-((  Alfe 2004-Sep-10
// this should be removed and all occurrances of atan2() in the mudlib
// should be checked and corrected (swap their arguments).  until then
// this ugly patch should keep it safe.
float atan2(float x, float y) {
  return efun::atan2(y, x);
}
#endif

/*
 * greatest common divisor of a and b
 */
int gcd(int a,int b) {
  int h;
#if 1  // gcd(5,-5) produced a too deep recursion otherwise
  if (a < 0)
    a = -a;
  if (b < 0)
    b = -b;
#endif
  if (a < b)
    h=a, a=b, b=h;
  if (b)
    return gcd(b,a % b);
  else
    return a;
}

int gcd_n(int *args) {
  return fold_left(#'gcd, args[1..], args[0]);
}

void reduce_fraction(int a, int b) {
  // a and b should be references!
  int d;
  d = gcd(a, b);
  a /= d;
  b /= d;
}
