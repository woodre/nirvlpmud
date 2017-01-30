#include "/players/guilds/bards/ansi.h"
varargs string show_scale(int val,int max,int size,int marker) {
  int n,div;
  string ret;
  if(size<10) size=10;
  ret="";
  if(max==0) {
    for(n=1;n<=size;n++) ret+="?";
    return NORM+MAG+"["+ret+"]"+NORM;
  }
  div=val*size/max;
  marker=marker*size/max;
  if(marker> 0 && marker < size)
    for(n=1;n<=size;n++)
      ret+=(n==div?HIM+"*"+NORM+MAG:(n==marker?HIB+"|"+NORM+MAG:"-"));
  else
    for(n=1;n<=size;n++)
      ret+=(n==div?HIM+"*"+NORM+MAG:"-");
  return NORM+MAG+(div<=0?"(":"[")+ret+(div>size?")":"]")+NORM;
}
