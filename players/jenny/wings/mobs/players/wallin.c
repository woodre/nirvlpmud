inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "jesse wallin" ||  str == "jesse" || str == "wallin" || str == "Jesse Wallin" || str  == "player"; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("Jesse Wallin");
    set_race("human");
    set_gender("male");
    set_al(210+random(100));	
    set_level(17);
    set_hp(330+random(40));
    set_wc(24);
    set_ac(14);
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
    set_short(BOLD+RED+"Jesse Wallin"+NORM);
    set_long(
      "Jesse Wallin is one of the players for the Detroit Red Wings.  He\n"+
      "is a fairly big guy at 6-2, 190 lbs.  He has dark hair, and is dressed\n"+
      "in his uniform, complete with gloves, pads, skates, etc.  Jesse is\n"+
      "one of the team's prospects on defense.  He is not yet a full-time\n"+
      "NHL player, but should be soon.  Right now, he is only called up\n"+
      "when there are injuries.  Type "+RED+"stats wallin"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "wallin") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-2	weight: 190	born: 3-10-78"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 26th overall 1996	number: 3	"+RED+"*\n"+
"	*"+WHT+"	         by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	2	0	0	0	2		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
