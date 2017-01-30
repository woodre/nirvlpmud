#include <ansi.h>
#include "/obj/lib/living/settings.h"

#define EXPSTORE "/obj/exp_store.c"

int cmd_topkills()
{
  int i, siz;
  mixed *kills;
    
  if (this_player()->query_ghost())
  {
    write("You are in an immaterial state with no scores.\n");
	  return 1;
  }
  
  kills = (mixed *) EXPSTORE->query_kills();
  
  siz = sizeof(kills);
  write( HIR + pad("~", 40, '~') + NORM + "\n");
  write( YEL+"  Top Kills for Current Reboot Period\n"+NORM );
  write( HIR + pad("~", 40, '~') + NORM + "\n");
  write( " "+pad("PLAYER", 15) + " "+ pad("EXP",10) + " MOB\n");
  
  for(i=0; i<sizeof(kills); i++) {
    write( " "+pad(kills[i][0], 15) +" "+ pad( comma_number(kills[i][1]), 10) + " "+kills[i][2]+"\n");
  }
  
  write( HIR + pad("~", 40, '~') + NORM + "\n");
  
  return 1;
}
