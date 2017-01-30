/* for it's best special, it shoots pucks.  The obvious drawback is you need pucks in your inventory, and for carry reasons + a limited number of pucks available, this isn't very practicable.
they also have to figure out that it works with pucks by themselves.
*/
#include "/players/jenny/define.h"
inherit "/obj/weapon.c";
object ob;
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
   set_value(2500);

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
      slapshot = (random(35) + 75);
      num = random(100);
      puck = present("jennypuck",TP);
   ob = TP->query_attack();
   if(num < 31) {
   write(
     "\n"+
     "You give "+ob->query_name()+" a "+RED+"vicious "+NORM+"cross-check in the face.\n"+
     "\n"+
     CAP(ob->query_name())+" spits out a few "+WHT+"teeth"+NORM+".\n");
   say(
     "\n"+
     TPN+" gives "+ob->query_name()+" a "+RED+"vicious "+NORM+"cross-check in the face.\n"+
     "\n"+
          CAP(ob->query_name())+" spits out a few "+WHT+"teeth"+NORM+".\n");
     return 8;}
   if(num > 75 && puck) {
         if(ob->is_npc()) 
         ob->heal_self(-(4+random(5)));

      else ob->add_hit_point(-(4+random(5)));

   write("\n"+
            "You take a few steps back, drop a "+BLK+"puck "+NORM+"on the ground, and nail "+ob->query_name()+"\n"+
             "with a "+slapshot+" mph slapshot.\n");
   say("\n"+
     TPN+" takes a few steps back, drops a "+BLK+"puck "+NORM+"on the ground, and nails "+ob->query_name()+"\n"+
           "with a "+slapshot+" mph slapshot.\n");
      destruct(puck); TP->recalc_carry();
 return 6;}
}
