#include "/players/pavlik/guild/mages/defs.h"
inherit "players/pavlik/guild/mages/inherit/command";

#define SPELL_COST	240

reset(arg) {
  if(arg) return;
  set_verb("magestaff");
  set_name("Mage Staff");
  set_color_name(HIC+"Mage Staff"+NORM);
  set_rank(34);
  set_sp_cost(SPELL_COST);
  set_cost_string(SPELL_COST + " sp");
  set_descrip(
	"Summon the Mage's trusted tool and weapon.\n"
  );
}

/*
 * This file contains some functions used by the Mage Staff
 * These are NOT guild spells that players can just cast
 */

cmd()
{

  if(tp->query_guild_rank() < query_rank())
	return 0;

  if(!env->query_mguild())
  {
	notify_fail("You must be within the Mages Tower first.\n");
	return 0;
  }

  if(!check_sp())
  {
	notify_fail("");
	return 0;
  }

  if(tp->query_sp() < query_sp_cost())
  {
	notify_fail("You are too tired to create a Mage Staff right now.\n");
	return 1;
  }

  if(present("mage staff", tp))
  {
	notify_fail("You already have a mage staff.\n");
	return 0;
  }

  write(
   "You wave your hand in front of you and the air "+HIY+"crackles"+NORM+" with magic.\n" +
   "The air "+MAG+"shimmers"+NORM+" before you and an enchanted staff appears!\n" +
   "You take hold of the "+HIC+"Mage Staff"+NORM+".\n");

  say(
   "The air "+HIY+"crackles"+NORM+" with "+HIM+"magic"+NORM+" and a powerfull staff appears!\n" +
   ME+" takes hold of the magical staff.\n");

  move_object(clone_object(OBJ_DIR + "mage_staff"), tp);
  tp->add_spell_point(-query_sp_cost());
  return 1;

}

staff_help()
{
  write(
   "Mage Staff Powers:\n"+
   "  staff add <spell>      - Add spell to the autolist\n"+
   "  staff remove <spell>   - Remove spell from autolist\n"+
   "  staff list             - Show spells currently in autolist\n"+
   "  staff clear            - Clear all spells from autolist\n"+
   "  staff renew            - Recover saved autlist\n"+
   "  staff save             - Save autolist\n"+
   "  staff autocast <on/off> - Toggle Autocasting\n"+
   "  staff freq <#>         - Set casting Frequency\n"+
   "  staff order            - Toggles casting order [random or consecutive]\n"+
   "  staff help             - This menu\n"+
   "\n");
  return 1;
}


staff_hit(obj) {

  int x;
  x = random(10);

  if(x == 0) {
	write("You crack "+IT+" across the back with your staff!\n");
	say(ME+" cracks "+IT+" across the back with the magic staff!\n");
  }
  else if(x == 1) {
	write("A "+HIB+"bolt of lightning"+NORM+" emerges from your staff and strikes "+IT+"!\n");
	say("A "+HIB+"bolt of lightning"+NORM+" emerges from "+ME+"'s staff and strikes "+IT+"!\n");
	if(obj) obj->hit_player(5+random(5), "other|electric");
  }
  else if(x == 2) {
	write("Your staff "+HIY+"shines brilliantly"+NORM+" with magic power!\n");
	say(ME+"'s staff "+HIY+"shines brilliantly"+NORM+" with magic power!\n");
	if(obj) obj->hit_player(5+random(5), "magical");
  }
  else if(x == 4) {
	write("You slam your staff into your enemy's stomach!\n");
	say(ME+" slams the magic staff into "+IT+"'s stomach!\n");
  }
  else if(x == 6) {
	write(HIR+"Searing Flames"+NORM+" shoot from your staff and burn "+IT+"!\n");
	say(HIR+"Searing Flames"+NORM+" shoot from "+ME+"'s staff and burn "+IT+"!\n");
	obj->hit_player(5+random(5), "other|fire");
  }
  else if(x == 7) {
	write("Your dragon wood staff glows with the power of magic.\n");
  }
  else if(x == 8) {
	write("You "+HIG+"BASH"+NORM+" "+IT+" in the head!\n");
	say(ME+" "+HIG+"BASHES"+NORM+" "+IT+" in the head!\n");
  }

}
