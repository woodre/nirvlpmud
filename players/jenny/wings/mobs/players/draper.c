inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "kris draper" ||  str == "kris" || str == "draper" || str == "Kris Draper" || str  == "player"; } 
reset(arg)
{
   stuff = random(19);
   ::reset(arg);
    if (arg) return;
set_name("Kris Draper");
    set_race("human");
set_gender("male");
    set_al(300+random(50));
    set_level(18);
    set_hp(350+random(103));
    set_wc(25);
   set_wc_bonus(2);
    set_ac(16);
   if(stuff < 3) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(stuff > 2 && stuff < 18) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   add_money(1100+random(800));}
   if(stuff > 17) {
   add_money(3400+random(200)); }
   if(!random(1700)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1700)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
    set_short(BOLD+RED+"Kris Draper"+NORM);
    set_long(
      "Kris Draper is one of the players for the Detroit Red Wings.\n"+
      "He is an average sized guy with short light colored hair.  He\n"+
      "is wearing a grey sweat stained t-shirt and red shorts.  Kris\n"+
      "is in his eigth NHL season, and plays center.  He is a fast\n"+
      "skater, but not very good offensively.  His job is that of\n"+
      "fourth line checking center, and penalty killer.  Type "+RED+"stats\n"+
      "draper"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "draper") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-10	weight: 185	Born: 5-24-71"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 62nd overall 1989	number: 33	"+RED+"*\n"+
"	*"+WHT+"	         by Winnipeg				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	493	55	76	131	357		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(6) == 3) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in a choke hold","in a headlock","in a bear hug" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Kris Draper gets "+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(10); return 1; }
   return 1;
}
