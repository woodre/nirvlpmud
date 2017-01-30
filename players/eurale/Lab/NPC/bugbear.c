/*  Changed to new doc/build/RULES/monster.guide 8/12/02 - Eurale  */

#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";
#define ETO environment(this_object())
#define TO this_object()

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("bugbear");
set_short(HIY+"sleeping bugbear"+NORM);
set_long(
  "Standing nearly 7 feet tall, this muscular, hairy creature is one\n"+
  "to be cautious around.  It has a yellow hide with light red hair\n"+
  "and greenish eyes with red pupils.  Its ears are wedge shaped,\n"+
  "rising from the top of its head.  It has the snout of a bear with\n"+
  "a mouth full of sharp teeth which is where it got its name even\n"+
  "though it is not related to the bear.\n");

set_race("creature");
set_level(19);
set_hp(451 + random(25));
set_al(0);
set_wc(30);
set_ac(16);
set_aggressive(0);
set_dead_ob(this_object());

checker();
}

monster_died() {
object ob;
ob = present("corpse",ETO);
move_object(clone_object("/players/eurale/Lab/OBJ/hide.c"),ob);
return 0; }

checker() {
if(query_attack()) {
  TO->set_short(HIY+"giant bugbear"+NORM);
  return 1; }
call_out("checker",1);
}
