/*
specials. The heal self special bonus comes to 21.4.  The one that queries the attacker's hp comes to 14.5, i conservativly estimate this going off 25 percent of the time.  The special that queries monster's hp i estimate to go off about 50 percent of the time, so a bonus of 29, and for the negative heal self of half your hp, i'll add a wc bonus of 5.  All together this gives a wc bonus of 70
*/
inherit "/obj/monster"; 
#include "/players/jenny/define.h"
id(str) { return str == "ted lindsay" ||  str == "ted" || str == "lindsay" || str == "Ted Lindsay" || str == "alumni"; } 
object ob;
int onlyonce, enough, number;
reset(arg)
{
onlyonce = 0;
number = 1500+random(200);
enough = 0;
   ::reset(arg);
   if (arg) return;
   set_name("Ted Lindsay");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(29);
   set_hp(1800);
   set_hp_bonus(700);
   set_wc(58);
   set_wc_bonus(70);
   set_ac(30);
   set_ac_bonus(2);
   set_heal(16,2);
    set_dead_ob(this_object());
   add_money(8000+random(4000));

   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   MOCO("/players/jenny/wings/items/tedskates.c"),TO);
   init_command("wear skates");


message_hit = ({
        BOLD+"punches"+NORM," in the mouth, knocking out a few teeth",
        BOLD+"jabs"+NORM," in the eye with his fingers",
        BOLD+"head buts"+NORM," opening up a nasty cut",           
        BOLD+"knees"+NORM," in the groin",
        BOLD+"kicks"+NORM," in the stomach",
        BOLD+"punches"+NORM," in the ribs",
        BOLD+"punches"+NORM," in the arm"
        });

   set_short(BOLD+RED+"Ted Lindsay"+NORM);
   set_long(
      "Ted Lindsay is a Detroit Red Wings alumni.  He has dark hair and a rugged\n"+
      "face.  Although Ted is not all that big, he's one of the toughest and meanest\n"+
      "competitors you'll ever meet.  Ted played in 17 NHL seasons from 1944 to\n"+
      "1965, 14 of them in Detroit.  He had a great combination of toughness, skill,\n"+
      "and leadership which made him one of the best left wingers to ever play the\n"+
      "game.  In 1957, Ted Lindsay was traded as punishment for his efforts to start\n"+
      "a players union.  Ted helped Detroit win 4 Stanley Cup championships, and is\n"+
      "enshrined in the Hockey Hall of Fame.\n");

}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","west");
}
nomove() {
     if(MEAT) {
write("Ted Lindsay says: We're fighting to the end "+MEATN+".\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(420))     if(attacker_ob) { already_fight = 0; attack(); }

    if(TO->query_hp() < 350 && enough < 2) healme();
    if(TO->query_hp() > 1700) { onlyonce = 0; enough = 0; }

    if(TO->query_hp() < number && onlyonce < 2) ruthless();

    if(!random(7)) ouch();

    if(TO->query_hp() < random(1800))      if(attacker_ob) { already_fight = 0; attack(); }

  }
}

ouch() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Ted Lindsay gets "+MEATN+" in a choke hold.\n"+
      "\n"+
      CAP(MEATN)+" starts to get blue in the face."+NORM+"\n"+
      "\n");
      MEAT->heal_self(-65-random(20));
      return 1; }
   return 1;
}

healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        HIG+"Ted Lindsay gets his second wind and starts to feel better.\n"+
      "\n"+
     RED+"Ted says: "+NORM+"I don't think you're gonna beat me "+MEATN+".\n"+
      "\n");
      TO->heal_self(700);
      enough = 5;
      return 1; }
   return 1;
}
ruthless() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        BOLD+"Ted Lindsay throws "+MEATN+" against the wall as hard as he can.\n"+
      "\n"+
     RED+"BLOOD "+NORM+BOLD+"oozes out of "+MEATN+"'s head."+NORM+"\n"+
      "\n"+
    BOLD+"Ted Lindsay says: "+NORM+"Ya like that "+MEATN+"?\n"+
    "\n");
      MEAT->heal_self(-(MEAT->query_hp() / 2));
      onlyonce = 5;
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
