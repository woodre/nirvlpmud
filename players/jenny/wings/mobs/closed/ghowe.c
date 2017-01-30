/*
heal self bonus 24.3   bonus that queries your hp 16.8 goes off 28 percent of the time.  Bonus that queries monsters hp 30, goes off half the time   the bonus that takes half your hp, goes off 3 times, i'll set the bonus at 15 for that total bonus at 86
*/
inherit "/obj/monster"; 
#include "/players/jenny/define.h"
id(str) { return str == "gordie howe" ||  str == "gordie" || str == "howe" || str == "Gordie Howe" || str == "alumni"; } 
object ob;
int  enough, number, healnumber;
reset(arg)
{
number = 1500+random(200);
healnumber = 1000;
enough = 0;
   ::reset(arg);
   if (arg) return;
   set_name("Gordie Howe");
   set_race("human");
   set_gender("male");

   set_al(1000);
   set_level(29);
   set_hp(1800);
   set_hp_bonus(1500);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/gstick.c"),TO);
   init_command("wield stick");
   set_wc(60);
   set_wc_bonus(86);
   set_ac(32);
   set_heal(16,2);
   add_money(10000+random(4000));
    set_dead_ob(this_object());

message_hit = ({
        BOLD+"punches"+NORM," in the mouth, knocking out a few teeth",
        BOLD+"jabs"+NORM," in the eye with his fingers",
        BOLD+"head buts"+NORM," opening up a nasty cut",           
        BOLD+"knees"+NORM," in the groin",
        BOLD+"kicks"+NORM," in the stomach",
        BOLD+"punches"+NORM," in the ribs",
        BOLD+"punches"+NORM," in the arm"
        });

   set_short(BOLD+RED+"Gordie Howe"+NORM);
   set_long(
      "Gordie Howe is a Detroit Red Wings alumni.  He is a big guy with light brown\n"+
      "hair and a receding hairline.  Gordie played in the NHL for 26 years, from 1946\n"+
      "to 1980.  The first 25 years were with Detroit.  During the 1970's, he played 6\n"+
      "seasons in the rival World Hockey League before coming back to the NHL for\n"+
      "one last season in 1980.  Gordie was arguably the best player in NHL history.\n"+
      "At the time of his retirement, he owned nearly every career scoring record.  He\n"+
      "was a big, powerful right winger with great goal scoring and playmaking skills.\n"+
      "Gordie was also one of the toughest players in the league.  He didn't go looking\n"+
      "for fights, but if someone got him mad, they paid the price.  There may never be\n"+
     "a player like Howe again.  While most players are washed up in their late 30's,\n"+
     "Gordie was still a phenomenal player into his late 40's and early 50's.  Gordie\n"+
     "Howe has been enshrined in the Hockey Hall of Fame.\n"); 

}
init() {
  ::init();
add_action("nomove","south");
add_action("nomove","west");
}
nomove() {
     if(MEAT) {
write("Gordie Howe says: We are just getting started "+MEATN+".\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(410))     if(attacker_ob) { already_fight = 0; attack(); }

  if(MEAT){ already_fight = 0; attack(); }
    if(TO->query_hp() < 350 && enough < 2) healme();
    if(TO->query_hp() > 1750) {  enough = 0; healnumber = 1000; number = 1500+random(200); TO->set_wc(60); TO->set_ac(32); }

    if(TO->query_hp() < number) ruthless();

    if(!random(7)) ouch();

    if(TO->query_hp() < random(1800))      if(attacker_ob) { already_fight = 0; attack(); }

  }
}

ouch() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Gordie Howe gets "+MEATN+" in a choke hold.\n"+
      "\n"+
      CAP(MEATN)+" starts to get blue in the face."+NORM+"\n"+
      "\n");
      MEAT->heal_self(-75-random(20));
      return 1; }
   return 1;
 }

healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        HIY+"Gordie Howe gets his second wind and starts to feel better.\n"+
      "\n"+
     RED+"Gordie says: "+NORM+"I don't think you can beat me "+MEATN+".\n"+
      "\n");
      TO->heal_self(healnumber);
      healnumber = 500;
      enough ++;
      return 1; }
   return 1;
}
ruthless() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        BOLD+"Gordie Howe throws "+MEATN+" against the wall as hard as he can.\n"+
      "\n"+
     RED+"BLOOD "+NORM+BOLD+"oozes out of "+MEATN+"'s head."+NORM+"\n"+
      "\n"+
    BOLD+"Gordie Howe says: "+NORM+"Are you sure you want to fight me "+MEATN+"?\n"+
    "\n");
      MEAT->heal_self(-(MEAT->query_hp() / 2));
      number = number - 700;
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
