/*   special heals.  will average over 5 heals, sometimes more, sometimes less */
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "larry murphy" ||  str == "larry" || str == "murphy" || str == "Larry Murphy" || str  == "player"; } 
int NUM;
reset(arg)
{
   NUM = 400+random(75);
   ::reset(arg);
   if (arg) return;
   set_name("Larry Murphy");
   set_race("human");
   set_gender("male");
   set_al(700+random(150));
   set_level(20);
   set_hp(500+random(10));
   set_wc(30);
   set_hp_bonus(200);
   set_ac(16);
    add_money(4700+random(500));
   if(!random(1000)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1000)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Larry Murphy"+NORM);
   set_long(
      "Larry Murphy is one of the players for the Detroit Red Wings.\n"+
      "He is a fairly big guy at 6-1, 210 lbs.  He is in his late 30's, and\n"+
      "has short, light brown hair.  Larry is still wet, and wrapped in\n"+
      "a white towel.  Throughout his career, he has quietly put up\n"+
      "numbers which rank him among the best defensemen of all-\n"+
      "time.  Larry is a slow skater, with only an average shot, but\n"+
      "his intelligence and excellent instincts have allowed him to have\n"+
      "a long and distinguished career.  He has played in more NHL\n"+
      "games than anyone except the great Gordie Howe.  Type "+RED+"stats\n"+
      "murphy"+NORM+" to see his career stats.\n");
   
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "murphy") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-1	weight: 210	born: 3-8-61"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 4th overall 1980	number: 55	"+RED+"*\n"+
"	*"+WHT+"	         by Los Angeles				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	1615	287	929	1216	1084		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
   if(TO->query_hp() < NUM) healme();
}

healme() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n"+
         MAG+ "Larry regains his composure and feels a little better."+NORM+"\n");
      TO->heal_self(31+random(20));
      NUM = NUM - random(200);
      return 1; }
   return 1;
}
