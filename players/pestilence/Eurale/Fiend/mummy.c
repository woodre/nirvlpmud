/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("mummy");
set_race("creature");
set_short("Mummy");
set_long(
	"  This was once the ancient Egyptian, Im-ho-tep.  He was caught\n"+
	"stealing a sacred scroll to bring his beloved princess back to\n"+
	"life and buried alive for it.  A modern day archeologist accident-\n"+
	"ally reads an inscription that brings him back to life.  Boris\n"+
	"Karloff played this part in the 1932 thriller, The Mummy, and\n"+
	"it brought him stardom and linked his name to movie horror for\n"+
	"the rest of his career.\n");

set_level(24);
  set_hp(1100);
  set_al(0);
  set_wc(44);
  set_wc_bonus(23);
  set_ac(23);
  set_heal(30,5);
  set_aggressive(0);
  set_dead_ob(this_object());

/*
set_chance(15);
set_spell_dam(25);

set_spell_mess1(
  "\n\nThe mummy swats his attacker with a "+BOLD+"ROTTING, PUTRID HAND"+
	NORM+"\n\n");
set_spell_mess2(
  "\n\nThe mummy swats you with a "+BOLD+"ROTTING, PUTRID HAND!"+
	NORM+"\n\n");
*/

add_spell("putrid",
  "\n\nThe mummy swats you with a "+BOLD+"ROTTING, PUTRID HAND!"+
        NORM+"\n\n",
  "\n\nThe mummy swats his attacker with a "+BOLD+"ROTTING, PUTRID HAND"+
        NORM+"\n\n",
15,25,"other|magic",0);

add_spell("charge",
  "\n\n$HW$#MN#$N$ charges forward, ramming into #TN#.#RET##TN# falls to the ground in pain!"+NORM+"\n\n",
  "\n\n$HW$#MN#$N$ charges forward, ramming into #TN#.#RET##TN# falls to the ground in pain!"+NORM+"\n\n",
20,"30-60",0,0);

add_spell("choke",
  "\n\n$HW$#MN#$N$ chokes #TN#'s with it's bandages!"+NORM+"\n\n",
  "\n\n$HW$#MN#$N$ chokes you with it's bandages!"+NORM+"\n\n",
20,35,"other|magic",0);

add_spell("gaze",
  "\n\n$HW$#MN#$N$ gazes into #TN#s soul.#RET##TN# feels weakened!"+NORM+"\n\n",
  "\n\n$HW$#MN#$N$ gazes into #TN#s soul.#RET##TN# feels weakened!"+NORM+"\n\n",
5,80,0,0);

}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nThe bandages unravel and fall to the floor in a pile....\n\n");
  move_object(clone_object("players/eurale/Fiend/OBJ/bandages"),
    environment(this_object()));
return 0; }
