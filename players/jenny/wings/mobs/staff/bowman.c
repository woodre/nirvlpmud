inherit "/obj/monster";
#include "/players/jenny/define.h"
int NUM;
id(str) { return str == "scotty bowman" ||  str == "scotty" || str == "bowman" || str == "Scotty Bowman"; } 

reset(arg)
{
NUM = 100+random(100);
   ::reset(arg);
   if (arg) return;
   set_name("Scotty Bowman");
   set_race("human");
   set_gender("male");
   set_al(870+random(100));
   set_level(21);
   set_hp(400+random(70));
   set_wc(35);
   set_wc_bonus(8);
   set_hp_bonus(200);
   set_ac(22);
   add_money(2000+random(2000));
    MOCO("/players/jenny/wings/items/notebook.c"),TO);
   set_short(BOLD+WHT+"Scotty Bowman"+NORM);
   set_long(
      "Scotty Bowman is the coach of the Detroit Red Wings.  He is a stocky\n"+
      "67 year old man with dark hair and a receding hairline.  His large head\n"+
      "and thick neck is reminiscent of that of a bulldog.  Scotty has coached in\n"+
      "the NHL for 29 seasons, and is the winningest coach in league history.\n"+
      "Though he may seem stubborn, Scotty is smart enough, and adaptable\n"+
      "enough to have been successful in many different eras.  Many people\n"+
      "consider him to be the greatest coach in the history of professional sports.\n");
}
heart_beat() {
  ::heart_beat();
  if(TO->query_hp() < NUM) healme();
/* MEAT check added [5.23.01] by Vertebraker */
    if( MEAT && (random(INTMEAT + 10) < 8)) gethit();
 }

      healme() {
  if(!environment(this_object())) return 1;
  if(MEAT)
   if(environment() == environment(MEAT)) {
    say("\n"+
         WHT+ "Scotty pops something into his mouth and starts to feel a whole lot better."+NORM+"\n");
   TO->heal_self(200);
NUM = NUM - 2000;
 return 1; }
return 1;
}
gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n");
       say("Scotty effortlessly steps to the side and "+WHT+"throws "+NORM+MEATN+" to the ground\n");
      MEAT->hit_player(30); return 1; }
   return 1;
}
