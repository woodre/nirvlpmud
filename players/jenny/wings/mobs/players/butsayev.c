inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "yuri butsayev" ||  str == "yuri" || str == "butsayev" || str == "Yuri Butsayev" || str  == "player"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Yuri Butsayev");
    set_race("human");
    set_gender("male");
    set_al(200+random(100));	
    set_level(17);
    set_hp(300+random(100));
    set_wc(23);
    set_ac(15);
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
    set_short(BOLD+RED+"Yuri Butsayev"+NORM);
    set_long(
      "Yuri Butsayev is one of the players for the Detroit Red Wings.\n"+
      "He is a fairly big guy at 6-1, 200 lbs.  He has dark hair, and is\n"+
      "dressed in his uniform, complete with gloves, pads, skates, etc.\n"+
      "Yuri is a pretty good checking forward.  He does not score a\n"+
      "lot, but is a solid third or fourth line player.  He is not yet a\n"+
      "full-time NHL player, and is only called up to the team when\n"+
      "there are injuries.  Type "+RED+"stats butsayev"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "butsayev") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-1	weight: 200	born: 10-11-78"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 49th overall 1997	number: 22	"+RED+"*\n"+
"	*"+WHT+"	         by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	72	6	4	10	16		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
