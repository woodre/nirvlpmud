inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "maxim kuznetsov" ||  str == "maxim" || str == "kuznetsov" || str == "Maxim Kuznetsov" || str  == "player"; } 
reset(arg)
{
   stuff = random(2);
   ::reset(arg);
    if (arg) return;
    set_name("Maxim Kuznetsov");
    set_race("human");
    set_gender("male");
    set_al(260+random(100));	
    set_level(17);
    set_hp(350+random(5));
    set_wc(22+random(5));
    set_ac(13+random(3));
   if(stuff == 0) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);}
    set_short(BOLD+RED+"Maxim Kuznetsov"+NORM);
    set_long(
      "Maxim Kuznetsov is one of the players for the Detroit Red Wings.\n"+
      "He is a very big guy at 6-5, 198 lbs.  Maxim has dark hair, and is\n"+
      "wearing a white t-shirt and black sweat pants.  He is a rookie\n"+
      "defensemen, finally getting a chance to play in the NHL.  Type "+RED+"stats\n"+                        "kuznetsov"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "kuznetsov") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-5	weight: 198	born: 3-24-77"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 26th overall 1995	number: 32	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit         			"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	25	1	2	3	23		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
