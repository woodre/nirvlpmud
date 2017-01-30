inherit "obj/treasure.c";
#include <ansi.h>

reset(arg)
{
  if(arg) return;
  set_id("n51gn");
  set_alias("sign");
  set_long("The huge, well lit, sign with lots of neon reads:\n"+BOLD+
	   "        %~~~~~~~~~~~~~~~~~~~%\n"+
	   "        |                   |\n"+
	   "        |  Casa de Nirvana  |\n"+
	   "        |                   |\n"+
	   "        |"+NORM+"  Hotel and Casino "+BOLD+"|\n"+
	   "        |                   |\n"+
	   "        %~~~~~~~~~~~~~~~~~~~%\n\n"+NORM);
}

short() 
{ 
      return HIR + "A large sign two stories high" + NORM ; 
    } 
get() { return 0; }
