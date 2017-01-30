inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "jason williams" ||  str == "jason" || str == "williams" || str == "Jason Williams" || str  == "player"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Jason Williams");
    set_race("human");
    set_gender("male");
    set_al(200+random(100));	
    set_level(17);
    set_hp(350+random(10));
    set_wc(24);
    set_ac(14);
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
    set_short(BOLD+RED+"Jason Williams"+NORM);
    set_long(
      "Jason Williams is one of the players for the Detroit Red Wings.  He\n"+
      "is an average sized guy at 5-11, 188 lbs.  He has short blonde hair\n"+
      "and is dressed in red shorts and a black t-shirt.  He is a rookie forward,\n"+
      "who is only called up to the team when there are injuries.  Type "+RED+"stats\n"+
      "williams"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "williams") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-11	weight: 188	born: 8-11-80"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: never drafted		number: 29	"+RED+"*\n"+
"	*"+WHT+"	         					"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	5	0	3	3	2		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
