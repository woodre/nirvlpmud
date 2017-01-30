/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())
#define TO this_object()

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("wight");
set_short(BOLD+"Wight"+NORM);
set_long(
  "From a distance, this undead can easily be mistaken for any number\n"+
  "of humanoid races.  Upon closer inspection, however, its true nature\n"+
  "becomes apparent.  This nightmarish reflection of its former living\n"+
  "self has cruel, burning eyes, set in mummified flesh.  It has an\n"+
  "emaciated body with hands that end in sharp claws.\n");

set_race("undead");
set_level(19);
set_hp(445 + random(100));
set_al(-random(100));
set_wc(30);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/molar.c"),ob);
return 0; }

init() {
  ::init();
  add_action("NoGo","northwest");
  add_action("NoGo","southwest");
}

NoGo() {
  write("The wight extends its boney arm and stops you.\n");
  return 1; }
