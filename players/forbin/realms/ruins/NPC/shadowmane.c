#include "/players/forbin/realms/ruins/ruinsdefine.h"
inherit "obj/monster.c";

id(str) { return (::id(str) || str == "mane"); }

reset(arg)  {
  object amulet;
  ::reset(arg);
  if(arg) return;
  amulet = clone_object(OBJ+"damulet.c");
  move_object(amulet, this_object());
set_name("ShadowMane");
set_alt_name("shadowmane");
set_short(""+MAG+"ShadowMane"+NORM+"");
set_long(
    "  Standing only four feet tall, this dark creature glares at you with\n"+
    "unrestrained hatred.  Its body is covered with short black hair which\n"+
    "seems to blend well with its surroundings.  Its arms and legs are\n"+
    "heavily muscled and taught with anger.  Looking at its hands you see\n"+
    "they end with long sharp claws, easily capable of rending any armor\n"+ 
    "and especially flesh.  A small red amulet hangs from its neck, it\n"+
    "seems to glow with a magical light.\n");
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
  load_a_chat("The shadowmane howls as it strikes at you!\n");
  load_a_chat("ShadowMane leaps at you!\n");

set_chance(15);
set_spell_dam(random(15)+5);

set_spell_mess1(
  "ShadowMane "+BOLD+""+BLK+"RAKES"+NORM+" at its foe!\n");
set_spell_mess2(
  "You scream in pain as ShadowMane "+BOLD+""+BLK+"RAKES"+NORM+""+
  " you with its claws!\n");
}

query_shadowmane() { return 1; }

monster_died() {
#ifdef KILLLOG
  mon_log(KILLLOG);
#endif
  return 1; 
}