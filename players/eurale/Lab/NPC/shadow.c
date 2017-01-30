/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("dragon");
set_alias("shadow dragon");
set_short(BOLD+"Shadow Dragon"+NORM);
set_long(
  "These dragons are rumored to be the most sly and devious and not\n"+
  "prone to risk taking.  At all ages, a shadow dragon's scales and\n"+
  "body are translucent so that when viewed from a distance it appears\n"+
  "to be a mass of shadows.  This specimen is not one of the larger\n"+
  "but its deadly teeth and claws still pose a serious threat to any\n"+
  "living creature.\n");

set_race("creature");
set_level(20);
set_hp(550 + random(50));
set_al(-random(125));
set_wc(42);
set_ac(17);
set_heal(2,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
  load_chat("Smoke curls from the dragon's nostrils.\n");

set_chance(8);
set_spell_dam(random(60));
set_spell_mess1(
  BOLD+"The dragon breathes a dark BLACK FLAME...\n"+NORM);
set_spell_mess2(
  BOLD+"The dragon SINGES you with a BLAST of dark BLACK FLAME..\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/shadowscale.c"),ob);
return 0; }
