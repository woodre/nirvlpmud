#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

object amulet;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("mane");
set_alt_name("shadowmane");
set_alias("shadow");
set_race("demon");
set_short(""+MAG+"ShadowMane"+NORM+"");
set_long(
  "  Standing only four feet tall, this dark creature glares at\n"+
  "you with unrestrained hatred. Its body is covered with short\n"+
  "black hair which seems to blend well with its surroundings. It's\n"+
  "arms and legs are heavily muscled and taught with anger. Looking\n"+
  "at it's hands you see they end with long sharp claws, easily\n"+
  "capable of rending any armor and especially flesh. A small red\n"+
  "amulet hangs from its neck, it seems to glow with a magical\n"+
  "light.\n");

set_level(12);
set_hp(random(50) + 200);
set_al(-random(800));
set_wc(20);
set_ac(7);
set_aggressive(1);
set_dead_ob(this_object());
set_chat_chance(5);
  load_chat("The shadowmane glares at you with hatred.\n");
  load_chat("ShadowMane gives a deep throaty growl.\n");
set_a_chat_chance(15);
  load_a_chat("ShadowMane rakes at you!\n");
  load_a_chat("Shadowmane howls as it strikes at you!\n");
  load_a_chat("Shadowmane leaps at you!\n");

set_chance(15);
set_spell_dam(random(15)+5);

set_spell_mess1(
  "ShadowMane "+BOLD+""+BLK+"RAKES"+NORM+" at it's foe!\n");
set_spell_mess2(
  "You scream in pain as ShadowMane "+BOLD+""+BLK+"RAKES"+NORM+""+
  " you with it's claws!\n");

	amulet = clone_object("players/maledicta/ruins/obj/damulet.c");
	move_object(amulet, this_object());
	
}


