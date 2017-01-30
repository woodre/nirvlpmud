#include <ansi.h>

short()
{
  string sd;
  string a, b;
  sd = ::short();
  if(sscanf(sd, "%s[%s]",a,b)==2)
    return (a+HIC+"("+NORM+b+HIC+")"+NORM);
  else sd;
}
