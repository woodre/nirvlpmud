inherit "/obj/monster";
#include "/players/jenny/define.h"
int stuff;
id(str) { return str == "todd gill" ||  str == "todd" || str == "gill" || str == "Todd Gill" || str == "player"; } 

reset(arg)
{
    stuff = random(2);
   ::reset(arg);
   if (arg) return;
   set_name("Todd Gill");
   set_race("human");
   set_gender("male");
   set_al(370+random(100));
   set_level(18);
   set_hp(400);
   set_wc(24+random(5));
   set_wc_bonus(2);
   set_ac(16);
    if(!random(5)) { set_aggressive(1); }
   if(stuff == 0) {
   add_money(1100+random(300));
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}

   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   add_money(1200+random(200));}
   set_short(BOLD+RED+"Todd Gill"+NORM);
   set_long(
      "Todd Gill is a player for the Detroit Red Wings.  He is a decent sized\n"+
      "guy at 6-0 180 lbs.  He is wearing navy blue shorts and a grey t-shirt.\n"+
      "Todd is a solid defensemen, who has been playing in the NHL for 15\n"+
      "years.  Type "+RED+"stats gill"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "gill") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-0	weight: 180	Born: 11-9-65"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 25th overall 1984	number: 23	"+RED+"*\n"+
"	*"+WHT+"		 by Toronto				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	966	82	266	348	1189		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(100) < 27) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the stomach","in the ribs","in the mouth","in the eye","in the nose"});
      num = random(sizeof(spellhits));
      say("\n");
       say("Todd Gill "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(8); return 1; }
   return 1;
}
