/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("catoblepas");
set_short(GRY+"Catoblepas"+NORM);
set_long(
  "This bizarre, loathsome creature inhabits nearly anywhere there is\n"+
  "water.  The most terrifying of its features are its large bloodshot\n"+
  "eyes.  It's body is like a large, bloated buffalo, and its legs are\n"+
  "stumpy like those of a hippopotamus.  It has a long, snakey tail\n"+
  "which is swift and strong.  Its head is perched upon a long, weak\n"+
  "neck and looks much like that of a wart-hog.\n");

set_race("creature");
set_level(20);
set_hp(500);
set_al(0);
set_wc(30);
set_ac(17);
set_aggressive(0);
set_dead_ob(this_object());

set_a_chat_chance(4);
  load_a_chat("The large tail HITS you.\n");
  load_a_chat("You get FLIPPED by the huge tail.\n");

set_chance(6);
set_spell_dam(30);
set_spell_mess1(
  GRY+"A gray flash emits from the Catoblepas's eyes.\n"+NORM);
set_spell_mess2(
  GRY+"A grey flash from the Catoblepas's eyes BURNS YOU.\n"+NORM);

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/eye.c"),ob);
return 0; }
