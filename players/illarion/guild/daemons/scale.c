#include "/players/illarion/ansi.h"
varargs string show_scale(int val,int max,int size,int marker) {
  int n,div;
  string ret;
  if(size<10) size=10;
  div=val*size/max;
  ret="";
  marker=marker*size/max;
  if(marker> 0 && marker < size)
    for(n=1;n<=size;n++)
      ret+=(n==div?HIY+"*"+NORM:(n==marker?HIB+"|"+NORM:"-"));
  else
    for(n=1;n<=size;n++)
      ret+=(n==div?HIY+"*"+NORM:"-");
  return (div<=0?HIR+"("+NORM:"[")+ret+(div>size?HIG+")"+NORM:"]");
}
