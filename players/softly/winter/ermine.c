#include "/players/softly/misc/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("ermine");
   set_short("A"+BOLD+" white ermine"+NORM);
   set_alias("ermine");
   set_long("A long slender white ermine with a black tipped\n"+
            "tail stares through clear black eyes.\n");
   set_type("creature");
   set_level(5);
   set_ac(5);
   set_wc(9);
   set_hp(75);
   set_al(-200);
   set_aggressive(1);
   set_dead_ob(this_object());
}

monster_died(ob) {
  object pelt;
  pelt = clone_object("/obj/treasure");
  pelt->set_id("pelt");
  pelt->set_short(BOLD+"Ermine Pelt"+NORM);
  pelt->set_long("A"+BOLD+" white ermine"+NORM+" pelt.  This soft\n"+
                 "dense hide might have some value.\n");
  pelt->set_weight(1);
  pelt->set_value(200);
  tell_room(environment(),"The ermine is quickly skinned.  The pelt lies on the ice.\n");
  move_object(pelt,environment(ob));

}
