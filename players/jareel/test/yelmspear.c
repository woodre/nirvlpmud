#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
inherit "/obj/weapon.c";

     object ob;
     int limit = 2;

     reset(arg) {
       ::reset(arg);
         if(arg) return;
     set_id("spear");
     set_short(BOLD+"The legendary spear of "+HIY+"Yelm"+NORM);
     set_long(
       "\n"+
       "\n"+
       "\n");
     set_weight(2);
     set_class(18);
     set_value(10000);
     set_type("spear");
     message_hit = ({
        HIY+"stabs"+NORM," into the chest",
        HIY+"thrusts"+NORM," in the chest",
        HIY+"jabs"+NORM," into the head",           
        HIY+"slashes"+NORM," accross the chest",
        HIY+"spears"+NORM," the skull",
        HIY+"chopped"+NORM," the knee",
        HIY+"devestates"+NORM," its foe"
        });
     set_hit_func(this_object());
}

status id(string arg) { return ( ::id(arg) || arg == "yelm_spear" || arg == "spear" || arg == "legendary" || arg == "legendary spear"); }

     init() {
       ::init();
}

     weapon_hit(attacker) {
       status heh;
         if(TPRN != "Mondar") {
           if(!heh)
           if(random(100) < 40  && limit > 0) {
             heh = 1;
           TP->attack();
             heh = 0;
           limit --;
         return 1;}
         else { 
           limit = 2;
         return 3; }}}
        

