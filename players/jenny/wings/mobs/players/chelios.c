/* special attack based on opponent's hit points.  Average hp throughout the fight is assumed to be in the low 200's.  This assumes the special will go off about half the time.  Also keep in mind the dangerous nature of this, each hit brings your hp lower, making the special even more likely to go off next round, making death a real possibility.  For these reasons, I feel a wc bonus of 20 is justified.
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "Chris Chelios" ||  str == "chris" || str == "chelios" || str == "chris chelios" || str == "player"; } 

reset(arg)
{
   stuff = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("Chris Chelios");
   set_race("human");
   set_gender("male");
   set_al(750+random(150));
   set_level(21);
   set_hp(600+random(50));
   set_wc(34+random(3));
   set_wc_bonus(20);
   set_ac(19);
   set_heal(10,5);
   if(!random(3)) { set_aggressive(1); }
   if(stuff == 0) {
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   add_money(3000+random(1000)); }
   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO); }
   if(stuff == 2) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   add_money(3500+random(1000)); }
   set_short(BOLD+RED+"Chris Chelios"+NORM);
   set_long(
      "Chris Chelios is a defensemen for the Detroit Red Wings.  He is a fairly\n"+
      "big guy at 6-1, 186 lbs, with short dark hair.  Chris is an 18 year NHL\n"+
      "veteran, who has had an outstanding career.  He is everything you want\n"+
      "a defensemen to be.  He combines offensive ability, great defense, toughness,\n"+
      "and fighting ability.  In his prime, Chris was arguably the best defensemen\n"+
      "in the world.  Though his skills have diminished with age, he is still a force\n"+
      "to be reckoned with.  Type "+RED+"stats chelios"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
add_action("block","north");
add_action("block","east");
}

	thestats(arg) {
if(arg == "chelios") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-1	weight: 186	Born: 1-25-62"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 40th overall 1981	number: 24	"+RED+"*\n"+
"	*"+WHT+"		 by Montreal				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	1181	168	667	835	2430		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}

block() {
     if(MEAT) {
          write("Chris grabs you and throws you to the ground.\n");
          TP->add_hit_point(-(15+random(10)));
          return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( MEAT->query_hp() < random(450)) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the stomach","in the groin","in mouth","in the face","in the eye","in the throat"});
      num = random(sizeof(spellhits));
      say("\n");
       say("Chris Chelios "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+" as hard as he can.\n");
      MEAT->hit_player(30+random(20)); return 1; }
   return 1;
}
