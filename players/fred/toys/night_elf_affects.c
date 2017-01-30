inherit "/obj/treasure.c";
#include <ansi.h>

reset (arg)
{
  set_id("night_elf_affects");
  SetMultipleIds(({"mohawk","night elf mohawk","nightelf mohawk"}));
  long_desc = "A brilliant Night Elf Mohawk.  It makes you want to pity fools.\n";
  set_weight(0);
}

extra_look()
{ 
  if(environment() == this_player())
    return "Your hair is standing up displaying a brilliant Night Elf Mohawk";
  else
    return ""+environment()->query_name()+"'s hair is standing up displaying a brilliant Night Elf Mohawk"; 
}

query_auto_load() { return "/players/fred/toys/night_elf_affects.c:"; }

drop(){ return 1; }

