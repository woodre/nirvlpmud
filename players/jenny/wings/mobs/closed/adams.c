/*specials - wc bonus 22 - heal_self special goes off 1/8 of the time, 50 average damage, and it's multiplied by 2 because it's heal_self instead of hit_player.  That part comes to 12.5, for the other special, i figured it should average going off 1/4 of the time, wc of 40 that part comes to 10.  12+10 is how I get a bonus of 22
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "jack adams" ||  str == "jack" || str == "adams" || str == "Jack Adams" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Jack Adams");
   set_race("human");
   set_gender("male");
   set_al(500);
   set_level(25);
   set_hp(1220+random(60));
   set_wc(40);
   set_wc_bonus(22);
   set_ac(24);
   set_heal(3,2);
   add_money(9000+random(4000));
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

   set_short(BOLD+RED+"Jack Adams"+NORM);
   set_long(
      "Jack Adams is a Detroit Red Wings alumni.  He is a middle aged man with\n"+
      "dark hair, a receding hairline, and a round face.  Although a good player in\n"+
      "the early 1900's, Jack's connection to Detroit is as a coach and general\n"+
      "manager from 1927 to 1962.  He built seven Stanley Cup championship\n"+
      "teams in his tenure.  Though not well liked by his players, Adams was\n"+
      "respected as a winner.  The NHL coach of the year award has been named\n"+
      "in his honor, and he has been enshrined in the Hockey Hall of Fame.\n");

}
init() {
  ::init();
add_action("nomove","south");
add_action("nomove","east");
}
nomove() {
     if(MEAT) {
write("Jack Adams says: Oh no!  I'm going to kill you.\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(350))     if(attacker_ob) { already_fight = 0; attack(); }

    if(!random(8)) ouch();

  }
}

ouch() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Jack Adams throws "+MEATN+" up against the wall.\n"+
      "\n"+
      "Jack says: Ole Jack is gonna have to teach you some manners."+NORM+"\n"+
      "\n");
      MEAT->heal_self(-40-random(20));
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
