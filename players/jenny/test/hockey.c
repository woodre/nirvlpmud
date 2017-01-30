#include "/players/jenny/define.h"
inherit "/obj/weapon.c";
object ob;
int limit = 5;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("hockey stick");
   set_alias("stick");
   set_short("A Hockey Stick");
   set_long(
      "This is hockey stick with a silver aluminum shaft.  It is very hard\n"+
      "and unyielding, perfect for giving hard cross-checks.  There is white\n"+
      "tape on the end of the stick, as well as on the blade.  This stick\n"+
      "belongs to Vladimir Konstantinov.\n");
   set_weight(2);
   set_class(20);
   set_value(3500);
   set_type("staff");
message_hit = ({
        BOLD+"speared"+NORM," in the eye",
        BOLD+"wacked"+NORM," in the throat",
        BOLD+"chopped"+NORM," over the head",           
        BOLD+"slashed"+NORM," in the groin",
        BOLD+"butt ended"+NORM," in the ribs",
        BOLD+"hacked"+NORM," on the knee",
        BOLD+"slashed"+NORM," on the hand"
        });
   set_hit_func(this_object());
}
init() {
   ::init();
}
weapon_hit(attacker) {
      int num;
      int slapshot;
   int puck;
      slapshot = (random(30) + 80);
      puck = present("jennypuck",TP);
   ob = TP->query_attack();

   if(random(100) < 33  && limit > 0) {
   TP->attack();
   limit --;
     return 1;}
  else { 
    limit = 5;
  return 0; }
   if(random(100) > 75 && puck) {
         if(ob->is_npc()) 
         ob->heal_self(-(5+random(5)));

      else ob->add_hit_point(-(5+random(5)));

   write("\n"+
            "You take a few steps back, drop a "+BLK+"puck "+NORM+"on the ground, and nail "+ob->query_name()+"\n"+
             "with a "+slapshot+" mph slapshot.\n");
   say("\n"+
     TPN+" takes a few steps back, drops a "+BLK+"puck "+NORM+"on the ground, and nails "+ob->query_name()+"\n"+
           "with a "+slapshot+" mph slapshot.\n");
      destruct(puck); TP->recalc_carry();
 return 4;}
}
