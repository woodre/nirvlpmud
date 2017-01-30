#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

reset(arg) {
  if(arg) return;
  set_verb("devote");
  set_name("Devote");
  set_color_name(HIC+"Devote"+NORM);
  set_rank(1);
  set_descrip(
	"A Mage will do anything for magic - even sacrifice his own " +
	"life's blood.  The devote command will turn Hit Points into " +
	"Spell Point's.  Some Hit Points will be lost in the transfer.\n"
  );
}


cmd(str)
{
  int much;
  int x;

  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(!str)
  {
    notify_fail("Devote how much?\n");
    return 0;
  }

  sscanf(str, "%d", much);

  if(much < 10)
  {
    notify_fail("You must devote at least 10 hit points.\n");
    return 0;
  }

  if(much >= tp->query_hp())
  {
    notify_fail("Magic will be no use to you if you're dead!\n" +
		"You cannot devote more hit points than you have.\n");
    return 0;
  }

  x = ((much * 2)/3) + random(much/3);

  write(
   "You'll sacrifice anything for magic, even your own life's blood!\n" +
   "You devote "+much+" hit points.\n");

  if(tp->query_level() > WIZLEVEL)
	write(CYN+x+" spell points added.\n"+NORM);

  tp->add_hit_point(-much);
  tp->add_spell_point(x);
  return 1;

}

