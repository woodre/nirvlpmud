inherit "/obj/treasure.c";
#include <ansi.h>

id(str)
{
  return str == "valen_key" || str == "bronze key" || str == "key";
}

short()
{
  return "A bronze key";
}

long() 
{
  write("A bronze key with a emblem on the top.  \n"+
  "The emblem is a crossed "+BLUE+"Sword"+NORM+" and "+HIW+"Feather"+NORM+".\n");
}

get() { return 1; }
query_weight() { return 2; }
query_value(){ return 100; }