#include <ansi.h>
inherit "/obj/monster";
#define SAL HIR+"Salamander"+NORM

reset(arg) {
  int lvl;
  ::reset(arg);
  if(arg) return;
  lvl = random(4);
  set_name(SAL);
  set_alias("salamander");
  set_short("a "+SAL);
  set_long(
  "Salamanders are lesser elemental's of fire.  They are lizard-like\n"+
  "in appearance, but walk upright like men.  Salamanders move with\n"+
  "suprising grace and attack with lightning speed.  They love fire and\n"+
  "thrive easily in the lava tunnels.\n");
  set_race("salamander");
  set_level(17 + lvl);
  set_hp(425 + (lvl * 25));
  set_wc(24 + (lvl * 2));
  set_ac(14 + lvl);
  set_al(-random(1000));
  if(!random(2)) set_aggressive(1);
  else set_aggressive(0);
  set_chat_chance(20);
  set_a_chat_chance(20);
  load_chat("The "+SAL+" dips its head into the lava.\n");
  load_chat(SAL+" hisses angrily.\n");
  load_chat("The "+SAL+" hops around.\n");
  load_a_chat(SAL+" hisses angrily and spits at you!\n");
  load_a_chat("The "+SAL+" beats you with its tail.\n");
  load_a_chat("The "+SAL+" flings lava onto you!\n");
  set_chance(10 + (5 * lvl));
  set_spell_dam(10 + (10 * lvl));
  set_spell_mess1("The "+SAL+" flings a "+HIR+"ball of lava"+NORM+" onto its enemy!");
  set_spell_mess2("The "+SAL+" flings a "+HIR+"ball of lava"+NORM+" onto you!");
  switch (random(4)) {
	case 0 :
	   move_object(clone_object("players/pavlik/ilstkarn/treasure/red_potion"), this_object());
	   break;
	case 1 :
	   move_object(clone_object("players/pavlik/ilstkarn/heals/lava_drink"), this_object());
	   break;
	case 2 :
	   move_object(clone_object("players/pavlik/ilstkarn/armor/salamander_armor"), this_object());
	   break;
	case 3 :
	   move_object(clone_object("players/pavlik/ilstkarn/treasure/fire_stones"), this_object());
	   break;
  }
  money = 200 + (lvl * 200);
}

stop_fight() {
  if(!random(2)) {
	::stop_fight();
	return 1;
  }
  return;
}

