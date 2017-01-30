inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "mathieu dandenault" ||  str == "mathieu" || str == "dandenault" || str == "Mathieu Dandenault" || str == "player"; } 

reset(arg)
{
   stuff = random(7);
   ::reset(arg);
   if (arg) return;
   set_name("Mathieu Dandenault");
   set_race("human");
   set_gender("male");
   set_al(350+random(50));
   set_level(18);
   set_hp(380+random(45));
   set_wc(25);
   set_wc_bonus(2);
   set_ac(16+random(2));

   if(stuff < 2) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   add_money(1250+random(400));}
   if(stuff > 1) {
   add_money(3000+random(1000));}
   if(!random(2500)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(2500)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Mathieu Dandenault"+NORM);
   set_long(
      "Mathieu Dandenault is one of the players for the Detroit Red\n"+
      "Wings.  He is a fairly big man, about, 6-1, 195 lbs, with short,\n"+
      "dark brown hair.  Mathieu is in full uniform, with his game\n"+
      "jersey, hockey pants, padding, gloves, helmet, etc.  Mathieu\n"+
      "is in his sixth NHL season, and has split time between playing\n"+
      "right wing and defense.  He is a very fast skater, but not gifted\n"+
      "offensively.  He is an effective third to fourth line winger, or\n"+
      "fifth or sixth defensemen.  Type "+RED+"stats dandenault"+NORM+" to see\n"+
      "Mathieu's career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "dandenault") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-1	weight: 195	Born: 2-3-76"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 49th overall 1994	number: 11	"+RED+"*\n"+
"	*"+WHT+"	         by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	396	33	65	98	194		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(STEMEAT) < 4) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the throat","on the hand","on the forearm","on the knee","over the top of the head","on the ankle" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Mathieu Dandenault "+RED+"slashes "+NORM+MEATN+" "+spellhits[num]+" with his stick.\n");
      MEAT->hit_player(10); return 1; }
   return 1;
}
