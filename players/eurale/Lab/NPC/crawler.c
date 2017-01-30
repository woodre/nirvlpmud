/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("carrion crawler");
set_alias("crawler");
set_short(HIG+"Carion crawler"+NORM);
set_long(
  "This monster looks like a cross between a giant green cutworm and\n"+
  "a cephalopod.  Its head, which is covered with tough hide, sprouts\n"+
  "eight, slender, writhing tentacles.  It also emits a rank, fetid\n"+
  "odor.\n");

set_race("creature");
set_level(20);
set_hp(500);
set_al(0);
set_wc(32);
set_ac(16);
set_heal(1,3);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The tentacles constantly search the area...\n");

set_chance(15);
set_spell_dam(random(12));
set_spell_mess1(
  HIG+"The crawler's tentacle wraps around its victim...\n"+NORM);
set_spell_mess2(
  HIG+"You feel the cralwer tentacle wrap around your leg...\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/tentacle.c"),ob);
return 0; }
