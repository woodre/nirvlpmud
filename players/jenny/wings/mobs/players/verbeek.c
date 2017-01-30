inherit "/obj/monster";
#include "/players/jenny/define.h"
int stuff;
id(str) { return str == "pat verbeek" ||  str == "pat" || str == "verbeek" || str == "Pat Verbeek" || str == "player"; } 

reset(arg)
{
   stuff = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("Pat Verbeek");
   set_race("human");
   set_gender("male");
   set_al(450+random(200));
   set_level(19);
   set_hp(450);
   set_wc(30+random(3));
   set_wc_bonus(3);
   set_ac(15);
   if(!random(3)) { set_aggressive(1);}
   if(stuff == 0) { add_money(1700+random(100)); 
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}

   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}

   if(stuff == 2) { add_money(3700+random(300)); }
   set_short(BOLD+RED+"Pat Verbeek"+NORM);
   set_long(
      "Pat Verbeek is a player for the Detroit Red Wings.  He is a small, but\n"+
      "feisty, guy at 5-9, 190 lbs.  Pat has short brown hair, and is wearing\n"+
      "green shorts and a grey t-shirt.  Throughout his 18 year career, Pat\n"+
      "has always been a consistent goal scorer, as well as a very physical\n"+
      "player.  Although not as good as he once was, Pat is still a valuable\n"+
      "member of this team.  Type "+RED+"stats verbeek"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "verbeek") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-9	weight: 190	Born: 5-24-64"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 43rd overall 1982	number: 15	"+RED+"*\n"+
"	*"+WHT+"		 by New Jersey				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	1360	515	528	1043	2833		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(STRMEAT) < 5) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the stomach","in the groin","in the face","in the knee"});
      num = random(sizeof(spellhits));
      say("\n");
       say("Pat Verbeek "+RED+"kicks "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(12); return 1; }
   return 1;
}
