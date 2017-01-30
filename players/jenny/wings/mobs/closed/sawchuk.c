/*specials - heal_self special at 18.5  conservatively estimate the special that queries your hp to go off 25 percent of the time, so a bonus of 13.75  the special that queries monsters hp I estimate to go off 43 percent of the time, since the healing will keep bringing the hp up, I'd say the average hp throughout the fight will be around 650.  This puts the bonus for that special at 23.65. The total wc bonus is 56
*/
inherit "/obj/monster"; 
#include "/players/jenny/define.h"
id(str) { return str == "terry sawchuk" ||  str == "terry" || str == "sawchuk" || str == "Terry Sawchuk" || str == "alumni"; } 
object ob;
int healnum, enough;
reset(arg)
{
healnum = 400;
enough = 0;
   ::reset(arg);
   if (arg) return;
   set_name("Terry Sawchuk");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(28);
   set_hp(950);
   set_hp_bonus(1125);
   set_wc(55);
   set_wc_bonus(56);
   set_ac(28);
   set_ac_bonus(2);
   set_heal(16,2);
    set_dead_ob(this_object());
   add_money(5000+random(2000));

   MOCO("/players/jenny/wings/items/sblocker.c"),TO);
   init_command("wear blocker");

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

   set_short(BOLD+RED+"Terry Sawchuk"+NORM);
   set_long(
      "Terry Sawchuk is a Detroit Red Wings alumni.  He is an average size man\n"+
      "with very short dark hair.  Terry was a goaltender in the NHL from 1949 to\n"+
      "1970.  He played in Detroit for 13 seasons, helping them win 3 Stanley Cups.\n"+
      "Sawchuk was perhaps the best goalie in NHL history.  At the time of his\n"+
      "retirement he had more wins than any goalie in league history, and still holds\n"+
      "the league record with 103 shutouts.  Terry Sawchuk has been enshrined in\n"+
      "the Hockey Hall of Fame.\n");

}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","west");
}
nomove() {
     if(MEAT) {
write("Terry Sawchuk says: You're staying right here "+MEATN+".\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
         if(  (MEAT->query_mhp() - MEAT->query_hp()) > random(460))     if(attacker_ob) { already_fight = 0; attack(); }

    if(TO->query_hp() < 350 && enough < 2) healme();
    if(TO->query_hp() > 900) { healnum = 400; enough = 0; }

    if(!random(7)) ouch();

    if(TO->query_hp() > random(1500))      if(attacker_ob) { already_fight = 0; attack(); }

  }
}

ouch() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        RED+"Terry Sawchuk gets "+MEATN+" in a choke hold.\n"+
      "\n"+
      CAP(MEATN)+" struggles to even breathe."+NORM+"\n"+
      "\n");
      MEAT->heal_self(-60-random(10));
      return 1; }
   return 1;
}

healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
        CYN+"Terry Sawchuk draws on his inner strength and starts to feel better.\n"+
      "\n"+
     RED+"Terry says: "+NORM+"You cannot possibly beat me.  Why don't you just give up?\n"+
      "\n");
      TO->heal_self(healnum);
      healnum = (healnum * 2) / 3;
     if(healnum < 30) { enough = 5;}
      return 1; }
   return 1;
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
