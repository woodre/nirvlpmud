inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("hatchet");
  set_short("A hatchet");
  set_long(
"This is a small hatchet.  The handle is made out of wood, with bands\n"+
"of iron running all along it.  The head is made from iron as well, and\n"+
"has been maintained in very good shape.  It is extremely sharp.\n");
  set_value(1700);
  set_weight(2);
  set_class(16);
  set_read("An inscription on the base of the hatchet reads:\n\n"+
    " this properrty uf Nygor Wyrd donot touch or else kill you!!!\n");
  set_params("other|dark",0,"dark_hit");
}
dark_hit() {
  if(!random(6)) {
    write("An aura of darkness surrounds your axe.\n");
    say("An aura of darkness surrounds "+environment()->query_name()+"'s axe!\n");
    return 5;
    /* 0-4 damage- it's auto-randomized */
  }
}
