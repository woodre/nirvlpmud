inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "boyd devereaux" ||  str == "boyd" || str == "devereaux" || str == "Boyd Devereaux" || str  == "player"; } 
reset(arg)
{ 
   ::reset(arg);
    if (arg) return;
    set_name("Boyd Devereaux");
    set_race("human");
    set_gender("male");
    set_al(200+random(100));	
    set_level(17);
    set_hp(350+random(5));
    set_wc(23+random(2));
    set_ac(14);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
    set_short(BOLD+RED+"Boyd Devereaux"+NORM);
    set_long(
      "Boyd Devereaux is one of the players for the Detroit Red Wings.\n"+
      "He is a fairly big guy at 6-2, 195 lbs.  He has short dark hair, and\n"+
      "is wearing a grey t-shirt and blue shorts.  He is a forward, in his\n"+
      "fourth NHL season, and first with the wings.  He plays on a checking\n"+
      "line, and doesn't score many goals.  Type "+RED+"stats devereaux"+NORM+" to\n"+                "see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "devereaux") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-2	weight: 195	born: 4-16-78"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 6th overall 1996	number: 21	"+RED+"*\n"+
"	*"+WHT+"		 by Edmonton         			"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	230	20	37	57	63		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
