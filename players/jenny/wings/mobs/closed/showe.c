/*specials - wc bonus 25 - add_hp special goes off 1/7 of the time, 65 average damage, and it's multiplied by 1.5 because it's add_hp instead of hit_player.  That part comes to 14, for the other special, i figured it should average going off 1/4 of the time, wc of 45 that part comes to 11.  14+11 is how I get a bonus of 25
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "syd howe" ||  str == "syd" || str == "howe" || str == "Syd Howe" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Syd Howe");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(24);
   set_hp(900+random(100));
   set_wc(45);
   set_wc_bonus(25);
   set_ac(20);
   set_heal(3,2);
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

   set_short(BOLD+RED+"Syd Howe"+NORM);
   set_long(
      "Syd Howe is a Detroit Red Wings alumni.  He is a smaller than average guy\n"+
      "with short dark hair.  No relation to the great Gordie Howe, Syd played in\n"+
      "the NHL for 17 years from 1929 to 1946, 11 of those years were in Detroit.\n"+
      "Howe was a talented forward who helped Detroit win 3 Stanley Cups, and\n"+
      "still holds the Detroit record for most goals in a game with 6.  Syd Howe\n"+
    "has been enshrined in the Hockey Hall of Fame.\n");
}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","east");
add_action("nomove","leave");
}
nomove() {
     if(MEAT) {
write("Syd Howe says: I thought you wanted to fight!\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(330))     if(attacker_ob) { already_fight = 0; attack(); }

    if(!random(7))  takehp();

  }
}

takehp() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        BLU+"Syd Howe gets you in a choke hold.\n"+
      "\n"+
      "He starts choking the life out of you."+NORM+"\n"+
      "\n");
      MEAT->add_hit_point(-50-random(30));
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
