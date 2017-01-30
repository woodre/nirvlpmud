inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "igor larionov" ||  str == "igor" || str == "larionov" || str == "Igor Larionov" || str  == "player"; } 
reset(arg)
{ 
   stuff = random(10);
   ::reset(arg);
    if (arg) return;
    set_name("Igor Larionov");
    set_race("human");
    set_gender("male");
    set_al(900+random(100));	
    set_level(20);
    set_hp(400);
    set_wc(35+random(5));
    set_ac(18+random(5));
    set_ac_bonus(1+random(2));
   set_wc_bonus(11);
   if(stuff < 6) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);}
   if(stuff > 5) {
   add_money(4200+random(1600)); }
   if(!random(1000)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1000)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
    set_short(BOLD+RED+"Igor Larionov"+NORM);
    set_long(
      "Igor Larionov is one of the players for the Detroit Red Wings.\n"+
      "He is an average sized guy at 5-9, 170 lbs.  He has short, light\n"+
      "brown hair, and thin rimmed glasses.  Igor is wearing a black\n"+
      "shirt and grey sweat pants.  He is the third line center, and gets\n"+
      "time on both the power play and penalty killing units.  Igor is a\n"+
      "great playmaker, who would rather pass than shoot.  Igor spent\n"+
      "his prime years playing in the former Soviet Union, where he lead\n"+
      "his team to Olympic gold medals in 1984 and 1988.  After years\n"+
      "of fighting to gain his freedom, Igor received permission to come\n"+
      "to North America in 1989.  He is considered one of the greatest\n"+
      "Russian athletes of all time.  Type "+RED+"stats larionov "+NORM+"to see his\n"+
      "career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "larionov") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-9	weight: 170	born: 12-3-60"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 214th overall 1985	number: 8	"+RED+"*\n"+
"	*"+WHT+"		 by Vancouver         			"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	728	147	400	547	358		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
  ::heart_beat();
  if(random(10) == 8) healme();
         if(TO->query_hp() > random(600))     if(attacker_ob) { already_fight = 0; attack(); }
 }

      healme() {
  if(!environment(this_object())) return 1;
  if(MEAT)
   if(environment() == environment(MEAT)) {
    say("\n"+
         CYN+ "Igor catches his breath and feels a little better."+NORM+"\n");
   TO->heal_self(10+random(10));
 return 1; }
return 1;
}
