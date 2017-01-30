inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "norm ullman" ||  str == "norm" || str == "ullman" || str == "Norm Ullman" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Norm Ullman");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(23);
   set_hp(820+random(60));
   set_wc(45);
   set_wc_bonus(42);
   set_ac(20);
   set_heal(3,2);
   set_ac_bonus(13);
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

   set_short(BOLD+RED+"Norm Ullman"+NORM);
   set_long(
      "Norm Ullman is a Detroit Red Wings alumni.  He is an average size guy\n"+
      "with short brown hair.  Norm played center in the NHL for 20 years, from\n"+
      "1955 to 1975.  The first 13 of those years were with Detroit.  He was a\n"+
      "quiet and underrated player whose career numbers ranked him with the best\n"+
      "centers of all-time.  Ullman was admired for his consistency and durability.\n"+
      "He has been enshrined in the Hockey Hall of Fame.\n");
}
init() {
  ::init();
add_action("nomove","south");
add_action("nomove","east");
}
nomove() {
     if(MEAT) {
write("Norm says: You're not going anywhere!\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(1000))   healme(); }     

    if(TO->query_hp() < random(900))    if(attacker_ob) { already_fight = 0; attack();  already_fight = 0; attack(); }

  }
healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
         CYN+ "Norm seems to feed off your weakness."+NORM+"\n"+
                    "\n");
      TO->heal_self(50+random(30));
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
