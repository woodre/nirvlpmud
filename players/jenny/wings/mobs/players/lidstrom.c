/*   his special will heal him 3 times for 41+random(20)  hp_bonus of 150  */
inherit "/obj/monster";
#include "/players/jenny/define.h"
int NUM, stuff;
id(str) { return str == "nicklas lidstrom" ||  str == "nicklas" || str == "lidstrom" || str == "Nicklas Lidstrom" || str == "nick" || str == "player"; } 
reset(arg)
{
NUM = 400;
stuff = random(2);
   ::reset(arg);
    if (arg) return;
set_name("Nicklas Lidstrom");
    set_race("human");
set_gender("male");
    set_al(1000);
    set_level(20);
    set_hp(505);
    set_wc(35+random(2));
    set_hp_bonus(150);
    set_ac(18);
   if(!random(700)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}
   if(!random(700)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   if(stuff == 0) { add_money(4200+random(2000)); }
   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
    set_short(BOLD+RED+"Nicklas Lidstrom"+NORM);
    set_long(
      "Nicklas Lidstrom is one of the players for the Detroit Red\n"+
      "Wings.  He is tall wiry guy, about 6-2, 190 lbs, with short\n"+
      "blonde hair.  Nick is wearing a yellow polo short, and blue\n"+
      "jeans.  He is in his tenth NHL season, and plays defense.  Nick\n"+
      "is one of the top defensemen in the NHL.  He is a perennial\n"+
      "all-star, and has been a finalist for the Norris, and Lady Bing\n"+
      "trophies several times.  He is a great offensive player, and is\n"+
      "also able to be one of the top defensive players, without being\n"+
      "overly physical.  Type "+RED+"stats lidstrom"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "lidstrom") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-2	weight: 190	Born: 4-28-70"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 53rd overall 1989	number: 5	"+RED+"*\n"+
"	*"+WHT+"	         by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	775	136	431	567	200		"+RED+"*\n"+
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
         CYN+ "Nicklas catches his second wind and feels better."+NORM+"\n");
   TO->heal_self(41+random(20));
NUM = NUM - 150;
 return 1; }
return 1;
}
