#include "/players/softly/closed/ansi.h"
inherit "obj/monster";
object gold;

reset(arg){
::reset(arg);
 if(arg) return;

set_name("butterfly");
set_race("insect");
set_alias("bfly");
set_short(HIM+"Pink butterfly"+NORM+"");
set_long("A "+HIM+"bright pink butterfly "+NORM+"flutters amongst the flowers.\n");
set_level(1);
set_hp(15);
set_al(1000);
set_wc(5);
set_ac(3);
set_aggressive(0);
set_chat_chance (1);
load_chat("The "+HIM+"pink butterfly "+NORM+"flutters about.\n");
load_chat("The flower nods when the butterfly lands on it.\n");
load_chat("The butterfly brushes your face.\n");
load_chat("The "+HIM+"pink butterfly "+NORM+"flies just out of reach.\n");
set_dead_ob(this_object());
}
monster_died(ob) {
  tell_room(environment(this_object()),
  "As the "+HIM+"pink butterfly "+NORM+"dies you see a\n"+
  "few coins lying on the ground nearby.\n");	
  gold = clone_object("obj/money");
  gold->set_money(50+random(10));
  move_object(gold,environment(this_object()));
  return 1; 
}




