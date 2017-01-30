inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "martin lapointe" ||  str == "martin" || str == "lapointe" || str == "Martin Lapointe" || str == "player"; } 
int stuff;
object ob;
reset(arg)
{
   stuff = random(2);
   ::reset(arg);
   if (arg) return;
   set_name("Martin Lapointe");
   set_race("human");
   set_gender("male");
   set_al(700+random(200));
   set_level(19);
   set_hp(450+random(10));
   set_wc(32);
   set_wc_bonus(6);
   set_ac(14);
   set_heal(3,2);
   if(stuff == 0) { add_money(3500+random(1000)); }
   if(stuff > 0) {
   MOCO("/players/jenny/wings/items/shinpads.c"),TO);
   init_command("wear pads");
  set_ac_bonus(2);
   add_money(2500+random(1000)); }
   set_short(BOLD+RED+"Martin Lapointe"+NORM);
   if(!random(1700)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1700)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_long(
      "Martin Lapointe plays right wing for the Detroit Red Wings.  He is\n"+
      "a strong guy at 5-11, 208 lbs.  Martin has short dark hair and is dressed\n"+
      "in his uniform, gloves, pads, etc.  This is his eighth NHL season, and\n"+
      "Martin has become a valuable member of this team.  He combines\n"+
      "strength, fighting ability, and a pretty good scoring touch.  If someone\n"+
      "tries to take liberties with one of the team's star players, they usually\n"+
      "have to answer to Lapointe.  Type "+RED+"stats lapointe"+NORM+" to see Martin's career stats.\n");
}
init() {
  ::init();
if(!((int)this_player()->query_ghost()))
{
add_action("thestats","stats");
add_action("nomove","north");
add_action("nomove","south");
add_action("nomove","west");
add_action("nomove","east");
add_action("nomove","out");
}
}

	thestats(arg) {
if(arg == "lapointe") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-11	weight: 208	Born: 9-12-73"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 10th overall 1991	number: 20	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	Penalty Min	"+RED+"*\n"+
"	*"+WHT+"	552	108	122	230	888		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
nomove() {
write("Lapointe has ahold of you and won't let go.\n");
return 1;}
heart_beat() {
if(!environment()) return;
if(ob = present("sergei fedorov", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } 

   ::heart_beat();
  if(MEAT){
    if( random(100) < 20) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the nose","in the mouth","in the eye","in the jaw" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Martin Lapointe "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+" with a hard right.\n");
      MEAT->hit_player(30); return 1; }
   return 1;
}
