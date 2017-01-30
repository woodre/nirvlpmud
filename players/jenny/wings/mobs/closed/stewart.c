/*specials - wc bonus 22 for the big special, plus I added another 2 for the extra hit that happens when you are low on hp
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "black jack stewart" ||  str == "jack" || str == "black jack" || str == "black" || str == "stewart" || str == "Black Jack Stewart" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Black Jack Stewart");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(24);
   set_hp(920+random(60));
   set_wc(44);
   set_wc_bonus(24);
   set_ac(23);
    add_money(3000+random(100));
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

   set_short(BOLD+RED+"Black Jack Stewart"+NORM);
   set_long(
      "Black Jack Stewart is a Detroit Red Wings alumni.  He is an average size guy\n"+
      "with dark hair and dark brown eyes.  Stewart was an NHL defensemen from\n"+
      "1938 to 1952.  He played his first 10 seasons with Detroit.  Stewart was a\n"+
      "one of the best defensemen in the league, and earned his nickname because\n"+
      "his opponents said he hit like a blackjack.  He has been enshrined in the\n"+
    "Hockey Hall of Fame.\n");
}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","east");
add_action("nomove","leave");
}
nomove() {
     if(MEAT) {
write("Black Jack says: Real men stay and fight!\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if(  (MEAT->query_mhp() - MEAT->query_hp()) > 200)     if(attacker_ob) { already_fight = 0; attack(); }

    if(random(100) < 22) { gethit();

  }
}}
gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the head","in the ribs","in the groin" });
      num = random(sizeof(spellhits));
      say("\n"+
          BOLD+RED+"Black Jack gives a crunching check and knocks "+MEATN+" to the ground."+NORM+"\n"+
        "\n"+
       "Black Jack starts to "+RED+"kick "+NORM+MEATN+" "+spellhits[num]+".\n"+
       "\n");
      MEAT->hit_player(80+random(40)); return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
