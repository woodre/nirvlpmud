#include "/players/fred/mages/defs.h"

inherit "/obj/monster.c";
int dmg;
int max;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_level(20);
   set_name("gauge");
   set_short(BOLD+BLK+"A power gauge"+NORM);
   set_long("This is a power gauge. You can use it to gauge how\n"+
            "powerful you are.  Just type 'stop' when you are done.\n");
   set_race("unknown");
   set_hp(1000);
   set_wc(0);
   set_ac(14);
   set_al(0);
   dmg=0;
   }

id(str){ return str == "gauge" || str == "power gauge"; }

init() {
   ::init();
   add_action("reset_cmd","reset");
   add_action("stop_it","stop");
  }

heart_beat() {
   if(attacker_ob) {
   dmg += 1000-hit_point;
   if(dmg < 10){   
     say("The power gauge turns "+BOLD+YEL+"Yellow"+NORM+".\n");
     heal_self(100);
     dmg = 0;}
   else if(dmg < 20){
     say("The power gauge turns "+BOLD+GRN+"Green"+NORM+".\n");
     heal_self(100);
     dmg = 0;}
   else if(dmg < 30){
     say("The power gauge turns "+BOLD+BLU+"Blue"+NORM+".\n");
     heal_self(100);
     dmg = 0;}
   else if(dmg < 40){
     say("The power gauge turns "+BOLD+MAG+"Magenta"+NORM+".\n");
     heal_self(100);
     dmg = 0;}
   else{
     say("The power gauge turns "+BOLD+RED+"Red"+NORM+".\n");
     heal_self(100);
     dmg = 0;} 
   }
  ::heart_beat();
}

reset_cmd() {
   write("Ok.\n");
   dmg=0;
   return 1;
}

stop_it(){
 object b;
 b = TO->query_attack();
 if(b){
  TO->stop_fight();
  b->stop_fight();
  b->stop_fight();
  TO->stop_fight();
 }
 say(capitalize(TPRN)+" feels satisfied and stops hitting the gauge.\n");
 return 1;
}
