#include "/players/pestilence/define.h"
#define ME TP->query_possessive()
#define MEE TP->query_objective()
inherit "/obj/weapon.c";
object ob;
int limit = 8;
status heh;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_id("ak 47");
   set_alias("gun");
   set_short("AK 47 assault rifle");
   set_long(
      "This is a very deadly AK 47 assault rifle.  It is military issue from >A.o.P<.\n"+
      "On the side of the long barrel, For military use only, is written.\n");
   set_weight(2);
   set_class(16);
   set_value(0);
   set_type("gun");
message_hit = ({
        BOLD+"fired a shot into"+NORM," devastating them",
        BOLD+"destroyed"+NORM," in the arm",
        BOLD+"blows a hole into"+NORM,"'s chest",           
        BOLD+"shot"+NORM," in the groin",
        BOLD+"shot impaled"+NORM," in the ribs",
        BOLD+"fired into"+NORM,"'s knee",
        BOLD+"glanced"+NORM," on the leg"
        });
   set_hit_func(this_object());
} 
init() {
   ::init();
}
weapon_hit(attacker) {

   if(!attacker) return;
   if(heh) return;
   if(TP) {
   if(random(100) > 60) hithim();
   if(!heh)
   if(random(100) < 33 && limit > 0 && attacker &&
     present(attacker, environment(environment()))) {
   heh = 1;
   if(TP)
     TP->attack();
   heh = 0;
   limit --; 
     return 1;}
   else { 
    limit = 8;
return 3; }}}

hithim() {
      int flurry;
      object clip;
      flurry = (random(14));
      if(!TP) return 0;
      clip = present("ak_clip",TP);
      ob = TP->query_attack();
      if(!ob) return 0;
      if(!clip) return 0;
         ob->hit_player(flurry+random(10)); 
       if(ob) {
      write("\n"+
            "You unleash a flurry of shots hitting "+ob->query_name()+"\n"+
             "with "+flurry+" shots.\n");
      say("\n"+ 
     TPN+" unleashes a flurry of shots hitting "+ob->query_name()+"\n"+
           "with "+flurry+" shots.\n");
        }
      if(clip) destruct(clip); TP->recalc_carry();
 return random(4); } 

query_wear() {
  int wear;
  wear = 3*misses/3 + 4*hits/12;
  return wear;
}

query_heh() { return heh; }
