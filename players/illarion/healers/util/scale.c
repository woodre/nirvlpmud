#include <ansi.h>
varargs string show_scale(int val,int max,int size,int marker) {
  int n,div;
  string ret;
  if(size<10) size=10;
  div=val*size/max;
  if(val <= 1)
    div = 0;
  else if(val >= max)
    div = size;
  ret="[";
  marker=marker*size/max;
  if(marker > 0 && marker < size)
    for(n=0;n<=size;n++)
      ret+=(n==div?"*":(n==marker?HIB+"|"+NORM:"-"));
  else
    for(n=0;n<=size;n++)
      ret+=(n==div?"*":"-");
  return ret+"]";
}
