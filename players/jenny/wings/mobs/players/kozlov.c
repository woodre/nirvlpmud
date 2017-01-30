inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "vyacheslav kozlov" ||  str == "vyacheslav" || str == "kozlov" || str == "Vyacheslav Kozlov" || str == "slava" || str == "player"; } 
reset(arg)
{
   stuff = random(20);
   ::reset(arg);
    if (arg) return;
set_name("Vyacheslav Kozlov");
    set_race("human");
set_gender("male");
    set_al(620+random(100));
    set_level(19);
    set_hp(451);
    set_wc(25+random(7));
   set_wc_bonus(2);
    set_ac(16+random(2));
   if(stuff < 7) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(stuff > 6 && stuff < 15) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(stuff > 14) {
   add_money(3800+random(50)); }
   if(!random(1000)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1000)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
    set_short(BOLD+RED+"Vyacheslav Kozlov"+NORM);
    set_long(
      "Vyacheslav Kozlov is one of the players for the Detroit Red\n"+
      "Wings.  He is an average sized guy, about 5-10, 185 lbs. with\n"+
      "short brown hair.  Slava is wearing a grey t-shirt and black\n"+
      "Shorts.  He is in his ninth NHL season, and plays left wing.\n"+
      "Slava is a talented, but inconsistent player.  He is a good skater,\n"+
      "stick-handler, and scorer.  Slava usually plays his best hockey\n"+
     "in the playoffs.  Type "+RED+"stats kozlov"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "kozlov") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-10	weight: 185	Born: 5-3-72"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 45th overall 1990	number: 13	"+RED+"*\n"+
"	*"+WHT+"	         by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	607	202	213	415	376		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
  ::heart_beat();
  if(random(8) == 4) gethit();
 }

      gethit() {
  if(!environment(this_object())) return 1;
  if(MEAT)
   if(environment() == environment(MEAT)) {
int num;
string *spellhits;
    spellhits = ({ "in the gut","in the nose","in the eye","in the mouth" });
num = random(sizeof(spellhits));
    say("Slava "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+".\n");
   MEAT->hit_player(12); return 1; }
return 1;
}
