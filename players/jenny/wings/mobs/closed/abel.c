/*specials - wc bonus 35 - extra hit bonus, i estimated going off 24 percent of the time, heal_self bonus helps drive this number up, wc of 50 bonus of 12, random heal self bonus goes of 1/6 of the time, damage average of 55 multiplied by 2 since it's heal self, bonus of 18.  The one shot heal_self bonus is hard to put a number on, so I set it at 5, considering this has a good chance of leading to the players death, it's a very conservative number.  So all that totals 35
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "sid abel" ||  str == "sid" || str == "abel" || str == "Sid Abel" || str == "alumni"; } 
object ob;
int justonce;
reset(arg)
{
    justonce = 0;
   ::reset(arg);
   if (arg) return;
   set_name("Sid Abel");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(26);
   set_hp(1250+random(130));
   set_wc(50);
   set_wc_bonus(35);
   set_ac(25);
   set_heal(5,2);
    set_dead_ob(this_object());
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
message_hit = ({
        BOLD+"punches"+NORM," in the mouth, knocking out a few teeth",
        BOLD+"jabs"+NORM," in the eye with his fingers",
        BOLD+"head buts"+NORM," opening up a nasty cut",           
        BOLD+"knees"+NORM," in the groin",
        BOLD+"kicks"+NORM," in the stomach",
        BOLD+"punches"+NORM," in the ribs",
        BOLD+"punches"+NORM," in the arm"
        });

   set_short(BOLD+RED+"Sid Abel"+NORM);
   set_long(
      "Sid Abel is a Detroit Red Wings alumni.  He is an average size man with\n"+
      "short dark hair.  Abel played in the NHL for 13 seasons, from 1938 to\n"+
      "1954, missing a few seasons to fight in WWII.  Eleven of those seasons\n"+
      "were in Detroit.  Abel was one of the best centers in the NHL, and was\n"+
      "a member of  arguably the best forward line in league history, the Production\n"+
      "Line, with Gordie Howe and Ted Lindsay.  He has also served the Red\n"+
      "Wings in the capacity of coach and general manager.  Sid Abel has been\n"+
      "enshrined in the Hockey Hall of Fame.\n");

}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","west");
}
nomove() {
     if(MEAT) {
write("Sid Abel says: You're not going anywhere "+MEATN+".\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(450))     if(attacker_ob) { already_fight = 0; attack(); }

    if(!random(6)) ouch();

    if(TO->query_hp() < 200 && justonce < 1) lastgasp();

  }
}

ouch() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Sid Abel throws "+MEATN+" up against the wall.\n"+
      "\n"+
      "Sid says: You shouldn't mess with me.  Do you know who I am?"+NORM+"\n"+
      "\n");
      MEAT->heal_self(-45-random(20));
      return 1; }
   return 1;
}
lastgasp() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"With his last ounce of energy, Sid Abel punches "+MEATN+" in the throat.\n"+
      "\n"+
      MEATN+" rolls around on the floor, struggling to breathe."+NORM+"\n"+
      "\n");
      MEAT->heal_self(-(MEAT->query_hp() / 2));
      justonce = 5;
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 

return 0; }
