inherit "/obj/monster";
#include "/players/jenny/define.h"
int stuff;
id(str) { return str == "tomas holmstrom" ||  str == "tomas" || str == "holmstrom" || str == "Tomas Holmstrom" || str == "tom" || str  == "player"; } 
reset(arg)
{ 
   stuff = random(3);
   ::reset(arg);
    if (arg) return;
    set_name("Tomas Holmstrom");
    set_race("human");
    set_gender("male");
    set_al(350+random(150));    
    set_level(18);
    set_hp(370+random(15));
    set_wc(21);
    set_ac(22);
    set_wc_bonus(2);
    if(!random(4)) { set_aggressive(1); }
   if(stuff == 0) { add_money(2900+random(1000)); }
   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(stuff == 2) { add_money(3400+random(1000)); }
   if(!random(3000)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1500)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
    set_short(BOLD+RED+"Tomas Holmstrom"+NORM);
    set_long(
      "Tomas Holmstrom is one of the players for the Detroit Red Wings.  He\n"+
      "is a stocky guy at 6-0, 210 lbs  He has short, blonde hair and is wearing\n"+
      "dark blue shorts and a white t-shirt.  Tomas is a tough forward who likes\n"+
      "to play in front of the net, screening the goalie and scoring on rebounds.\n"+
      "He takes a beating every game, but doesn't let that stop him from doing\n"+
      "his job.  He is in his fifth NHL season.  Type "+RED+"stats holmstrom"+NORM+" to\n"+
      "see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "holmstrom") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-0	weight: 210	Born: 1-23-73"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 257th overall 1994	number: 96	"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	331	53	87	140	229		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if(random(20) < 4) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the throat","in the nose","in the stomach","in the mouth","in the groin","in the eye" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Tomas Holmstrom "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(10); return 1; }
   return 1;
}
