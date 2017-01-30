#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;

  set_name("spotted fawn");
  set_short("A spotted fawn");
  set_alias("fawn");
  set_long("The young fawn stands on thin wobbly legs.\n"+
           "His pale brown coat is still dotted with\n"+
           "white showing his youth.  His huge brown\n"+
           "eyes stare at you.\n");
  set_type("animal");
  set_level(4);
  set_ac(8);
  set_wc(4);
  set_hp(60);
  set_al(200);
  set_aggressive(0);
  set_dead_ob(this_object());
}

monster_died(ob) {
  object cloak;
  cloak = clone_object("/obj/armor");
  cloak->set_alias("cloak");
  cloak->set_name("cloak");
  cloak->set_short("Fawnskin Cloak");
  cloak->set_long("A pale brown fawn skin cloak.  This cloak\n"+
                  "should provide some warmth and protection.\n");
  cloak->set_type("misc");
  cloak->set_weight(1);
  cloak->set_ac(1);
  cloak->set_value(150);
  tell_room(environment(),"As the fawn dies, he leaves his warm coat behind.\n");
  move_object(cloak,environment(ob));

}



