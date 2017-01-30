/*specials - wc bonus 25 for the double hit that goes off when the monster gets below 200 hp, the wc bonus for that part comes to 17.6 wc*2 / 5 cause it goes off 20 percent of the time.  The other bonus goes off when the players hp are high, that's less of an exact science to calculate, so I just put it between 8 and 9, wich is justified if it even goes off 1/5 of the time, for most players, it should go off more than that.
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "ebbie goodfellow" ||  str == "ebbie" || str == "goodfellow" || str == "Ebbie Goodfellow" || str == "alumni"; } 
object ob;
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Ebbie Goodfellow");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(24);
   set_hp(1000);
   set_wc(44);
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

   set_short(BOLD+RED+"Ebbie Goodfellow"+NORM);
   set_long(
      "Ebbie Goodfellow is a Detroit Red Wings alumni.  He is an average size guy\n"+
      "with short dark hair.  Ebbie played in the NHL for 14 years from 1929 to\n"+
      "1943, playing his whole career in Detroit.  He started out as a center, but\n"+
      "switched to defense after a few years and became one of the top defensemen\n"+
      "in the league.  In 1943, he became the last player/coach to guide his team\n"+
      "to a Stanley Cup.  Ebbie Goodfellow is enshrined in the Hockey Hall of Fame.\n");
}
init() {
  ::init();
add_action("nomove","north");
add_action("nomove","east");
add_action("nomove","leave");
}
nomove() {
     if(MEAT) {
write("Ebbie says: You're staying right here!\n");
         if(attacker_ob) { already_fight = 0; attack();}

   return 1; }}
heart_beat() {
   ::heart_beat();
  if(MEAT){
        if( (MEAT->query_mhp() - MEAT->query_hp()) < random(150))     if(attacker_ob) { already_fight = 0; attack(); }

    if(TO->query_hp() < 200)  if(attacker_ob) { already_fight = 0; attack();  already_fight = 0; attack();}

  }
}
monster_died() { 
  write_file("/players/jenny/logs/alumni", MEATN+" killed "+TO->query_name()+" on "+ctime()+"\n"); 
return 0;}
