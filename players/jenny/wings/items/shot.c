/*
maybe heal is worth more than should be on a level 14 monster, but there are reasons for it to be legal.  1. Can't be used in battle, this is an important drawback, 2. Not obvious how to get it, you get a key to a cabinet, which contains it. 3. The monster, warton.c doesn't always have that key.  And 4.  It is in a pk and no teleport area, 

*/
#include "/players/jenny/define.h"
inherit "/obj/weapon.c";
object ob;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("syringe");
   set_alias("needle");
   set_short("A syringe");
   set_long(
      "This is clear plastic syringe with a needle on the end.  It is filled\n"+
      "with powerful pain killing drugs.  A person could use it to inject\n"+
      "themselves.\n"+
      BOLD+"                      USAGE     inject self"+NORM+"\n");
   set_weight(1);
   set_class(10);
   set_value(100);
   set_type("knife");
   set_hit_func(this_object());
}
init() {
   ::init();
   add_action("gethealed","inject");
}
weapon_hit(attacker) {
   ob = TP->query_attack();
   if(random(100) < 28) {
   write(
     "\n"+
     "You jab your needle deep into "+ob->query_name()+".\n");
     return 3+random(6);}}

gethealed(arg) {
   if(arg == "self") {
      if(!arg) { return 0; }
      if(TP->query_attack()) {
         write("It would not be safe to try and do this while fighting.\n");
return 1;}
      write("You carefully find a vein and stick the needle in, feeling a slightly painful\n"+
               "prick.  After injecting the drugs into your body, you feel a numbness, which\n"+
               "dulls the pain.\n");
      TP->heal_self(80);
    if (wielded) {
        call_other(wielded_by, "stop_wielding");
        wielded = 0;}
      destruct(this_object()); TP->recalc_carry();
      return 1; }
}
