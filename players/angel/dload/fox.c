#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("red fox");
   set_short(RED+"A red fox"+NORM);
   set_alias("fox");
   set_long("The long slender red fox has alert black eyes\n"+
            "and a long bushy tail tipped with white.  She\n"+
            "seems to be protecting something.\n");
   set_type("animal");
   set_level(3);
   set_ac(7);
   set_wc(4);
   set_hp(45);
   set_al(-100);
   set_aggressive(0);
   set_dead_ob(this_object());
}

monster_died(ob) {
  object tail;
  tail = clone_object("/obj/treasure");
  tail->set_id("tail");
  tail->set_short(RED+"Red fox tail"+NORM);
  tail->set_long("A"+RED+" red fox tail"+NORM+" , dense and thick.\n"+
                 "It might be used to make something to wear.\n");
  tail->set_weight(1);
  tail->set_value(120);
  tell_room(environment(),"The fox is quickly skinned, leaving the tail on the ground.\n");
  move_object(tail,environment(ob));

}



