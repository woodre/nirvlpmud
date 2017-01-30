inherit "/obj/monster";
#include "/players/jenny/define.h"
   int stuff;
id(str) { return str == "doug brown" ||  str == "doug" || str == "brown" || str == "Doug Brown" || str == "player"; } 

reset(arg)
{
   stuff = random(10);
   ::reset(arg);
   if (arg) return;
   set_name("Doug Brown");
   set_race("human");
   set_gender("male");
   set_al(330+random(100));
   set_level(18);
   set_hp(410);
   set_wc(26);
   set_wc_bonus(2);
   set_ac(15);
   if(stuff < 2) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   add_money(2000+random(20));}
   if(stuff > 1) {
   add_money(3300+random(400));}
   if(!random(1900)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1900)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Doug Brown"+NORM);
   set_long(
      "Doug Brown is a player for the Detroit Red Wings.  He is an average\n"+
      "sized guy at 5-10, 185 lbs.  He is wearing dark blue slacks, a white\n"+
      "shirt, and a tie.  Doug is a checking forward, who can be counted on\n"+
      "to chip in 10-20 goals per season.  He is in his fourteenth NHL season,\n"+
      "and his seventh in Detroit.  Type "+RED+"stats brown"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "brown") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-10	weight: 185	Born: 6-12-64"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: NA			number: 17	"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	854	160	214	374	210		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(10) < 2) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "against the wall","to the ground" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Doug Brown "+RED+"throws "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(10); return 1; }
   return 1;
}
