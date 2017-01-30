/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("couatl");
set_alias("serpent");
set_short(BOLD+"Couatl"+NORM);
set_long(
  "This feathered serpent is believed to be a distant realive of the\n"+
  "dragons.  So rare, as to be considered lengendary, it is one of the\n"+
  "most beautiful creatures in existence.  It has the body of of a long\n"+
  "serpent and feathered wings the colors of the rainbow.\n");

set_race("creature");
set_level(20);
set_hp(650 + random(200));
set_al(0);
set_wc(33);
set_ac(17);
set_heal(3,7);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(3);
  load_chat("A voice whispers, 'do not be foolish, I will kill you.'\n");
  load_chat("'Go back before it's too late' echoes in your head.\n");

set_chance(12);
set_spell_dam(15 + random(25));
set_spell_mess1(
  BOLD+"     The couatle SNAPS at its prey...\n"+NORM);
set_spell_mess2(
  BOLD+"A bolt of BLACK LIGHTNING from couatl's eyes STRIKES your "+
  "chest.\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/feathers.c"),ob);
return 0; }
