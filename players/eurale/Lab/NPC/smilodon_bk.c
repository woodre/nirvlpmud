/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
#include "/players/eurale/closed/aggro_hb.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("smilodon");
set_short(HIW+"Smilodon"+NORM);
set_long(
  "This giant predator is one of the large cats.  Its closest relative\n"+
  "would be the saber-toothed tiger. It is obvious why as there are\n"+
  "6 inch fangs protruding down from its upper jaw.  Large, powerful\n"+
  "legs make this beast not only strong but also fast.\n");

set_race("cat");
set_level(20);
set_hp(500 + random(100));
set_al(-random(100));
set_wc(30 + random(6));
set_ac(17);
set_aggressive(1);
set_dead_ob(this_object());

set_chat_chance(4);
  load_chat("The smilodon's big tail swishes back and forth.\n");
  load_chat("The smilodon growls.....\n");

set_chance(10);
set_spell_dam(random(11 + random(10)));

set_spell_mess1(
  HIW+"The smilodon BITES at its attacker...\n"+NORM);
set_spell_mess2(
  HIW+"You feel the huge fangs BITE through your skin...\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/fang.c"),ob);
return 0; }
