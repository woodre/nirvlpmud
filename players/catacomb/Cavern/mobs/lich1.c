#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object axe, amulet;

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
  load_chat("The lich warns of the dangers of Shimmerglooms cavern.\n");
set_a_chat_chance(1);
  load_a_chat("The lich floats near you wanting to take your life.\n");
  load_a_chat("The lich tells you: Once in Gloom's cave there is no escape.\n");
set_chance(30);
set_spell_dam(25);
set_spell_mess1(
  "The lich assaults its foe with an onslaught of mental energy.\n");
set_spell_mess2(
  "The lich sends forth a flurry of mental energy into your mind.\n");

axe = clone_object("players/catacomb/Cavern/items/Dthaxe.c");
move_object(axe, this_object());
command("wield axe", this_object());
set_wc(30);

amulet = clone_object("players/catacomb/Cavern/items/CurseAmulet.c");
move_object(amulet, this_object());
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
  if (chance > 75)
  {
	say("\nThe lich reaches out with its deadly hands and "+HIR+"RAKES"+NORM+"\n");
	say("		  you across the face.\n\n");
	write("\nThe lich rakes its enemy across the face with its skeletal hands.\n\n");
	ATTACKED->hit_player(random(30)+ 10, "other|evil");
	return 1;
  }
  if ((chance > 25) && (chance < 60))
  {
	say("\nThe lich "+RED+"O B L I T E R A T E S "+NORM+"you in a relentless onslaught\n\n");
	write("\nThe lich pounds on its foe with no mercy.\n\n");
	ATTACKED->hit_player(random(40));
	return 1;
  }
  else
  {
	return 1;
  }
}