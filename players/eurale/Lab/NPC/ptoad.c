/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("toad");
set_alias("poisonous toad");
set_short(HIR+"Poisonous toad"+NORM);
set_long(
  "This giant poisonous toad has red skin what is dry and very rough\n"+
  "to the touch.  It also is very warty.  Its eyes are orange with\n"+
  "pupils that resemble a starburst.\n");

set_race("creature");
set_level(19);
set_hp(475);
set_al(0);
set_wc(28 + random(3));
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

set_chance(15);
set_spell_dam(random(20));
set_spell_mess1(
  HIR+"The toad FLICKS its poisonous tongue..\n"+NORM);
set_spell_mess2(
  HIR+"You feel the toads poison tongue FLICK you.\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/pskin.c"),ob);
return 0; }
