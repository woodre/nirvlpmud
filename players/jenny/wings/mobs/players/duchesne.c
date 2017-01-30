inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "steve duchesne" ||  str == "steve" || str == "duchesne" || str == "Steve Duchesne" || str == "player"; } 

reset(arg)
{
   stuff = random(10);
   ::reset(arg);
   if (arg) return;
   set_name("Steve Duchesne");
   set_race("human");
   set_gender("male");
   set_al(500+random(120));
   set_level(19);
   set_hp(450);
   set_wc(29+random(3));
   set_wc_bonus(3);
   set_ac(16);
   if(stuff < 4) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(stuff > 3 && stuff < 8) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   add_money(2000+random(20));}
   if(stuff > 7) {
   add_money(3600+random(400)); }
   set_short(BOLD+RED+"Steve Duchesne"+NORM);
   set_long(
      "Steve Duchesne is a player for the Detroit Red Wings.  He is an\n"+
      "average sized guy at 5-11, 195 lbs, with short dark hair.  He is wearing\n"+
      "khaki shorts and a navy blue shirt.  Steve has enjoyed a 15 year career\n"+
      "in the NHL.  He is a good offensive defensemen, but is sometimes\n"+
      "careless defensively.  Though not as good as he once was, he still has\n"+
      "a few decent years left in him.  Type "+RED+"stats duchesne"+NORM+" to see his\n"+
      "career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "duchesne") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-11	weight: 195	Born: 6-30-65"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: NA			number: 28	"+RED+"*\n"+
"	*"+WHT+"		 					"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	1049	224	510	734	796		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(10) < 2) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the stomach","in the groin","in the thigh"});
      num = random(sizeof(spellhits));
      say("\n");
       say("Steve Duchesne "+RED+"knees "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(15); return 1; }
   return 1;
}
