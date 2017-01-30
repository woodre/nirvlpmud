/*specials - one gives an extra attack if your max hp - hp is less than random 200, so it punishes you for having very high hp, the other special gives 2 extra attacks when the monster's hp is less than random 500, and your max hp - hp is greater than random 400, so it goes off if the monsters hp are low and yours are low too.  Computing a wc bonus for this mess seems inexact, so i'll just give the logic I used.  One special will always go off when hp are high, and the other should kick in sometimes when m
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "marcel pronovost" ||  str == "marcel" || str == "pronovost" || str == "Marcel Pronovost" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Marcel Pronovost");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(23);
   set_hp(800+random(30));
   set_wc(44);
   set_wc_bonus(20);
   set_ac(19);
   set_heal(3,2);
   add_money(3500+random(1500));
    set_dead_ob(this_object());
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

   set_short(BOLD+RED+"Marcel Pronovost"+NORM);
   set_long(
      "Marcel Pronovost is a Detroit Red Wing alumni.  He is a pretty big\n"+
      "guy with very short dark hair.  Marcel played defense in the NHL for\n"+
      "20 years, from 1950 to 1970, the first 15 of those years were in Detroit.\n"+
      "He was one of the best defensemen in the league, a solid defender who\n"+
      "had very good skating and stick-handling skills.  He helped Detroit win\n"+
      "4 Stanley Cup Championships in the 1950's.  Marcel has been enshrined\n"+
      "in the Hockey Hall of Fame.\n");
}
init() {
  ::init();
add_action("nomove","south");
add_action("nomove","east");
}
nomove() {
     if(MEAT) {
write("Marcel says: Stay and fight me like a man!\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(!this_object()) return;
  if(MEAT){
    if( TO->query_hp() < random(500) && (MEAT->query_mhp() - MEAT->query_hp()) > random(400))      if(attacker_ob) { already_fight = 0; attack(); already_fight = 0; attack(); }     

    if( (MEAT->query_mhp() - MEAT->query_hp()) < random(200))    if(attacker_ob) { already_fight = 0; attack(); }

  }
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
