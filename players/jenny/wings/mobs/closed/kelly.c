/*specials - wc bonus 22 - special goes off half the time, so I cut the wc in half healing bonus and spell point taking bonus each go off only once
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "red kelly" ||  str == "red" || str == "kelly" || str == "Red Kelly" || str == "alumni"; } 
object ob;
int justonce = 0;
int once = 0;
int NUM;
reset(arg)
{
   NUM = 300+random(200);
   ::reset(arg);
   if (arg) return;
   set_name("Red Kelly");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(25);
   set_hp(600+random(20));
   set_wc(45);
   set_wc_bonus(23);
   set_hp_bonus(400);
   set_ac(24);
   set_heal(3,2);
    add_money(3500+random(1000));
    set_dead_ob(this_object());
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

   set_short(BOLD+RED+"Red Kelly"+NORM);
   set_long(
      "Red Kelly is a Detroit Red Wings alumni.  He is an average size guy with\n"+
      "short red hair.  Kelly was an NHL defensemen for 20 years from 1947 to\n"+
      "1967.  He played his first 12 seasons in Detroit, helping them win four Stanley\n"+
      "Cups.  A clean player, who put up good offensive numbers, Red Kelly was\n"+
      "one of the best defensemen of his era, and is enshrined in the Hockey Hall\n"+
    "of Fame.\n");
}
init() {
  ::init();
add_action("nomove","south");
add_action("nomove","east");
}
nomove() {
     if(MEAT) {
write("Red Kelly says: No, lets stay and finish this!\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if(!random(2))     if(attacker_ob) { already_fight = 0; attack(); }

    if(TO->query_hp() < 200 && justonce < 1)  healme();

    if(TO->query_hp() < NUM && once < 1)  takesp();

  }
}
healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Red Kelly starts to laugh.\n"+
      "\n"+
      "Red Kelly says: Did you really think I would be that easy?"+NORM+"\n"+
      "\n");
      TO->heal_self(400);
      justonce = 50;
      return 1; }
   return 1;
}
takesp() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        WHT+"Red Kelly throws you hard up against the wall.\n"+
      "\n"+
      "All the energy is knocked out of you."+NORM+"\n"+
      "\n");
      MEAT->add_spell_point(-MEAT->query_sp());
      once = 50;
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
