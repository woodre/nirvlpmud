#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("pelican");
   set_short("Brown Pelican");
   set_alias("Pelican");
   set_long("A huge dark long legged bird, its huge bill\n"+
            "has a large expandable pouch.  Its silvery\n"+
            "brown body is accented by a white neck and\n"+
            "yellow head with bright yellow eyes.\n");
   set_level(4);
   set_ac(4);
   set_wc(8);
   set_hp(60);
   set_al(100);
   set_dead_ob(this_object());
}

monster_died(ob) {
  object pelt;
  pelt = clone_object("/obj/treasure");
  pelt->set_id("fish");
  pelt->set_short("A large fish");
  pelt->set_long("A large fish flops about on the sand.\n");
  pelt->set_weight(1);
  pelt->set_value(150);
  tell_room(environment(),"The tame pelican looks at you sadly and, dying, drops a fish from his bill.\n");
  move_object(pelt,environment(ob));

}
