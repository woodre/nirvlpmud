#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("mtest");
  set_name("Mage Test ");
  set_color_name(HIC+"Mage Test"+NORM);
  set_rank(100);
  set_descrip(
	"mtest -- fear this.\n"
  );
}


cmd(str)
{
  object ob, obj;

  if(tp->query_level() < WIZLEVEL && tp->query_guild_rank() <= MAXGUILDRANK)
	return 0;

  if(!str)
	return 0;

  if(!(obj = find_player(str)))
  {
	notify_fail("Player '"+str+"' could not be found.\n");
	return 0;
  }

  ob = shadow(obj, 0);

  if(!ob)
  {
	write(capitalize(str)+" has no shadow.\n");
  }
  else
  {
	write(capitalize(str)+" is shadowed by: "+object_name(ob)+"\n");
  }

  return 1;
}

