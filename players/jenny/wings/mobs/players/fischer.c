inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "jiri fischer" ||  str == "jiri" || str == "fischer" || str == "Jiri Fischer" || str == "player"; } 

reset(arg)
{
   stuff = random(10);
   ::reset(arg);
   if (arg) return;
   set_name("Jiri Fischer");
   set_race("human");
   set_gender("male");
   set_al(400+random(100));
   set_level(19);
   set_hp(450);
   set_wc(29);
   set_wc_bonus(3);
   if(stuff < 3) {
   MOCO("/players/jenny/wings/items/hgloves.c"),TO);
   init_command("wear gloves");
   set_ac_bonus(2);
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);}
   if(stuff > 2) {
   add_money(3600+random(1000));}
   set_ac(16);
   set_short(BOLD+RED+"Jiri Fischer"+NORM);
   set_long(
      "Jiri Fischer is a young defensemen for the Detroit Red Wings.  He is\n"+
      "a big guy at 6-5, 225 lbs.  He has short brown hair, and is dressed\n"+
      "in his full uniform, including jersey, hockey pants, pads, gloves, etc.\n"+
      "Jiri is in his second NHL season, and has a bright future in the NHL.\n"+
      "In addition to his impressive size, he is a good skater, has good\n"+
      "offensive instincts, and a hard shot.  Type "+RED+"stats fischer"+NORM+" to see\n"+
      "Jiri's career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "fischer") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-5	weight: 225	Born: 7-31-80"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 25th overall 1998	number: 2	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	107	1	16	17	104		"+RED+"*\n"+
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
      spellhits = ({ "in the throat","on the hand","on the forearm","on the knee","over the top of the head","on the ankle" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Jiri Fischer "+RED+"slashes "+NORM+MEATN+" "+spellhits[num]+" with his stick.\n");
      MEAT->hit_player(15); return 1; }
   return 1;
}
