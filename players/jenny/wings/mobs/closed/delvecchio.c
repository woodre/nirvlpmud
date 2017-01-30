/*specials - one for healing, one for damage.  The more hp he has, the more damage he does, the less hp you have, the more he heals.  I used my most reasonable guestimate in figuring out ac and wc bonus's.  I figured for ac bonus, the average mhp-hp diferential would be 100 or so, and for the wc bonus, I estimated the spell chance around 36 percent
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "alex delvecchio" ||  str == "alex" || str == "delvecchio" || str == "Alex Delvecchio" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Alex Delvecchio");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(24);
   set_hp(870+random(100));
   set_wc(43);
   set_wc_bonus(18);
   set_ac(23);
   set_ac_bonus(30);
   set_heal(3,2);
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
   set_short(BOLD+RED+"Alex Delvecchio"+NORM);
   set_long(
      "Alex Delvecchio is a Detroit Red Wing alumni.  He is an average size\n"+
      "man with short brown hair and a round face.  Alex played Center in\n"+
      "Detroit for 22 years from 1951 to 1973, winning 3 Stanley Cups.  He\n"+
      "was one of the best playmaking centers in the league, spending much\n"+
      "of his career playing on a line with Gordie Howe.  When Alex finished\n"+
      "his career, he was the second leading scorer in NHL history.  Alex has\n"+
      "been enshrined in the Hockey Hall of Fame.\n");
}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","west");
}
nomove() {
     if(MEAT) {
write("Alex says: Oh no!  You wanted to fight, so we are fighting.\n");
gethit();
   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( TO->query_hp() > random(1600)) gethit();
    if( (MEAT->query_mhp() - MEAT->query_hp()) > random(400)) healme();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the head","in the ribs","in the mouth","in the nose","in the stomach","in the eye" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Alex Delvecchio "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(35+random(30)); return 1; }
   return 1;
}
healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
         CYN+ "Alex says:  "+NORM+"You do not look so good my friend.\n"+
                    "            I think I will beat you.\n");
      TO->heal_self(50+random(20));
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
