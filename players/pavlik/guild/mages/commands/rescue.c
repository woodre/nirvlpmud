#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command.c";

#define SPELL_COST	25

reset(arg) {
  if(arg) return;
  set_verb("rescue");
  set_name("Rescue");
  set_color_name(HIC+"Rescue"+NORM);
  set_rank(12);
  set_sp_cost(SPELL_COST);
  set_cost_string(SPELL_COST + " sp");
  set_descrip(
	"Use your skill on Magic to get out of sticky situations. " +
	"The Rescue command can be used to transport you back to the " +
	"safety of the Mages Tower.  This command may not work in some " +
	"realms so travel wisely.\n"
  );
}


cmd()
{
  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(!check_sp())
  {
	notify_fail("");
	return 0;
  }

  if(env->realm() == "NT")
  {
	notify_fail("Something here blocks your "+HIY+"Rescue"+NORM+" spell!\n");
	return 0;
  }

  if(env->query_mguild())
  {
	notify_fail("You are already in the Mages Tower.\n");
	return 0;
  }

  write("You cast a " + query_color_name() + " spell.\n");
  say(ME+" casts a spell.\n");

  write(
   "A hole in the earth opens up at your feet - "+HIY+"without hestitation you jump in!\n"+NORM+
   "You feel a "+HIM+"strange sensation"+NORM+" as you are transported "+HIM+"across time and space.\n"+NORM);

  say(
   "A hole in the earth opens at "+ME+"'s feet - "+ME+" quickly jumps in and disappears!\n" +
   "The hole "+HIBLK+"closes up"+NORM+" and "+HIBLK+"disappears"+NORM+".\n");

  move_object(tp, GUILD_HOME);

  write("You now find yourself in the "+HIW+"safety"+NORM+" of the "+HIC+"Mages Tower.\n\n"+NORM);
  say(
   HIW+"A hole suddenly opens in the floor!\n"+NORM+
   ME+" climbs out of the hole, stands up and brushes off "+PO+" robes.\n" +
   "The hole quickly "+HIBLK+"closes up"+NORM+" and "+HIBLK+"disappears"+NORM+".\n");

  command("look", tp);
  tp->add_spell_point(-query_sp_cost());
  return 1;

}
