#include "/players/jenny/define.h"
inherit "/obj/weapon.c";
object ob;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("nightstick");
   set_alias("stick");
   set_short("A nightstick");
   set_long(
      "This is a two and a half foot long wooden nightstick.  It is stained\n"+
      "dark brown and has a handle at the end for getting a better grip.\n");
   set_weight(2);
   set_class(15);
   set_value(400);
   set_type("club");
   set_hit_func(this_object());
}
init() {
   ::init();
}
weapon_hit(attacker) {
      int num;
      array *ouchie;
      ouchie = ({ "on the kneecap","in the head","on the hand","in the shoulder" });
      num = random(sizeof(ouchie));

   ob = TP->query_attack();
   if(random(100) < 31) {
   write(
     "\n"+
     "You wack "+ob->query_name()+" "+ouchie[num]+" with your nightstick.\n");
   say(
     "\n"+
     TPN+" wacks "+ob->query_name()+" "+ouchie[num]+" with "+POS+" nightstick.\n");
     return 2+random(5);}}
