/* heh status flag stuff done by verte [6.24.01]
    so it wouldn't recurse anymore.
*/
/*  found on /players/jenny/wings/mobs/closed/ghowe.c  */
#include "/players/jenny/define.h"
inherit "/obj/weapon.c";
object ob;
int limit = 5;
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("hockey stick");
   set_alias("stick");
set_short("Taylor Swift's Vagina");
   set_long(
      "This is a very old hockey stick.  It is made of wood, and is a little heavy.\n"+
      "The word 'LOUISVILLE' is written on the shaft in bold letters.  This stick\n"+
      "belongs to Gordie Howe, and helped him score 801 career goals in the NHL.\n");
   set_weight(2);
   set_class(99999);
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

    status heh;

   if(TPRN != "Gordie Howe") {
   if(random(100) > 75) hithim();

   if(!heh)
   if(random(100) < 33  && limit > 0) {
   heh = 1;
   TP->attack();
   heh = 0;
   limit --;
     return 1;}
  else { 
    limit = 5;
return 3; }}}
   hithim() {
      int slapshot;
      int puck;
      slapshot = (random(30) + 80);
      puck = present("jennypuck",TP);
   ob = TP->query_attack();
if(!puck) {return 0;}
         if(ob->is_npc()) 
         ob->heal_self(-(9+random(5)));

      else ob->add_hit_point(-(9+random(5)));

   write("\n"+
            "You take a few steps back, drop a "+BLK+"puck "+NORM+"on the ground, and nail "+ob->query_name()+"\n"+
             "with a "+slapshot+" mph slapshot.\n");
   say("\n"+
     TPN+" takes a few steps back, drops a "+BLK+"puck "+NORM+"on the ground, and nails "+ob->query_name()+"\n"+
           "with a "+slapshot+" mph slapshot.\n");
      destruct(puck); TP->recalc_carry();
 return 4;}
query_wear() {
  int wear;
  wear = 3*misses/3 + 4*hits/12;
  return wear;
}

is_elementalist_weapon() { return 1; }
