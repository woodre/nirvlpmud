inherit "/obj/monster";
#include "/players/jenny/define.h"
int NUM;
id(str) { return str == "ken holland" ||  str == "ken" || str == "holland" || str == "Ken Holland"; } 

reset(arg)
{
NUM = 1;
   ::reset(arg);
   if (arg) return;
   set_name("Ken Holland");
   set_race("human");
   set_gender("male");
   set_al(810+random(170));
   set_level(21);
   set_hp(500+random(300));
   set_wc(35+random(10));
   set_wc_bonus(8);
   set_ac(20);
   set_heal(2,2);
   MOCO("/players/jenny/wings/items/laptop.c"),TO);
   set_short(BOLD+WHT+"Ken Holland"+NORM);
   set_long(
      "Ken Holland is the General Manager of the Detroit Red Wings.  He\n"+
      "is a middle aged man with short brown hair, and wearing a black suit.\n"+
      "Ken is responsible for overseeing the team.  He hires and fires coaches,\n"+
      "drafts and trades for players, signs free agents, and negotiates contracts.\n"+
      "After owner Mike Llitch, Ken is the most powerful man in the Red Wings\n"+
      "organization.\n");
}
heart_beat() {
  ::heart_beat();
    if(random(4) > NUM) gethelp();
    if( random(32)  < 9) gethit();
 }

gethelp() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
   say("\n"+
         "Ken Holland calls a security guard into the room.\n");
            MOCO("/players/jenny/wings/mobs/staff/security.c"),ENVTO);
            NUM = 50;
   return 1;}
   return 1;}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n");
       say("Ken Holland "+WHT+"knees "+NORM+MEATN+" in the groin.\n");
      MEAT->hit_player(30); return 1; }
   return 1;
}
