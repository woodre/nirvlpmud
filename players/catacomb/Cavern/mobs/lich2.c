#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object club, helmet;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("lich");
set_race("undead");
set_short("A lich");
set_long(
  "  A wandering ghost of a Durkor mage floats in front of you.\n"+
  "An evil aura surrounds it.  It wanders the cavern looking for\n"+
  "any living creature to satisfy its hunger.  Its only concern is\n"+
  "to feed itself on the lifeblood of the living.  With each meal\n"+
  "it grows stronger, but it can never quench its hunger.\n");
 
set_level(18);
set_hp(400);
set_al(-1000);
set_ac(15);
set_dead_ob(this_object());
set_aggressive(0);
set_chat_chance(5);
  load_chat("The lich warns of the dangers of the mighty fire god, Ifreet.\n");
set_a_chat_chance(1);
  load_a_chat("The lich floats near you wanting to take your life.\n");
  load_a_chat("The lich wails: Consumir en fete.\n");
set_chance(20);
set_spell_dam(25);
set_spell_mess1(
  "The lich assaults its foe with an onslaught of mental energy.\n");
set_spell_mess2(
  "The lich sends forth a flurry of mental energy into your mind.\n");

club = clone_object("players/catacomb/Cavern/items/Lclub.c");
move_object(club, this_object());
command("wield club", this_object());
set_wc(29);

helmet = clone_object("players/catacomb/Cavern/items/CurseHelmet.c");
move_object(helmet, this_object());
}

heart_beat() 
{
  int chance;
  chance = random (100);
  ::heart_beat();
  if (!environment())
	return;
  if (!ATTACKED)
	return;
  if (chance > 65)
  {
	say("\nThe lich's "+HIW+"skeletal hands"+NORM+" "+RED+"IMPALE"+NORM+" you.\n");
	say("	  The lich quickly absorbs the lifeforce.\n\n");
	write("        The lich impales its enemy with its skeletal hands.\n\n");
	ATTACKED->hit_player(random(30));
	return 1;
  }
  if ((chance > 20) && (chance < 60))
  {
	say("\nThe lich "+RED+"D I S E M B O W E L S "+NORM+"you in a relentless onslaught\n\n");
	write("\nThe lich pounds on its foe with no mercy.\n\n");
	ATTACKED->hit_player(random(25));
	return 1;
  }
  else
  {
	return 1;
  }
}