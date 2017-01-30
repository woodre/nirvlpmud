inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "chris osgood" ||  str == "chris" || str == "osgood" || str == "Chris Osgood" || str == "player"; } 
int stuff;
reset(arg)
{
   stuff = random(4);
   ::reset(arg);
   if (arg) return;
   set_name("Chris Osgood");
   set_race("human");
   set_gender("male");
   set_al(870+random(130));
   set_level(20);
   set_hp(500+random(20));
   set_wc(25+random(5));
   set_ac(20+random(5));
   set_wc_bonus(4+random(2));
   if(stuff == 0) { add_money(4500+random(1000)); }
   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/eqbag.c"),TO);}
   if(stuff == 2) {MOCO("/players/jenny/wings/items/omask.c"),TO);
   init_command("wear mask");
   set_ac_bonus(2);
   MOCO("/players/jenny/wings/items/eqbag.c"),TO);
   add_money(2500+random(2000));}
   if(stuff == 3) {MOCO("/players/jenny/wings/items/goaliepads.c"),TO);
   init_command("wear pads");
   set_ac_bonus(2);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/eqbag.c"),TO);}
   if(!random(800)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}
   if(!random(700)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Chris Osgood"+NORM);
   set_long(
      "Chris Osgood is a goaltender for the Detroit Red Wings.  He\n"+
      "is an average size guy at 5-10, 178 lbs, with blonde hair and\n"+
      "boyish looks.  He is wearing a black t-shirt and dark blue shorts.\n"+
      "Chris is in his eighth year in the NHL.  He occasionally gives\n"+
      "up a bad goal, but overall, he plays very well, especially in the\n"+
      "playoffs.  Chris rarely gets much credit for his accomplishments,\n"+
      "because he has always played on a good team.  His winning\n"+
      "percentage ranks him up there with the great goalies of all-time.\n"+
      "Type "+RED+"stats osgood"+NORM+" to see Chris's career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "osgood") {
write(RED+
     "\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-11	weight: 178	Born: 11-26-72"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 54th overall 1991	number: 30	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	wins	losses	ties	GAA		"+RED+"*\n"+
"	*"+WHT+"	389	221	110	46	2.40		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(100) < 15) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n");
       say("Chris Osgood picks up his goal stick and wacks "+MEATN+" in the head.\n"+
        BOLD+RED+"                      Blood "+NORM+"gushes out.\n");
      MEAT->hit_player(30); return 1; }
   return 1;
}
