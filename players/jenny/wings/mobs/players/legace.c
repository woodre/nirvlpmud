inherit "/obj/monster";
#include "/players/jenny/define.h"
int stuff;
id(str) { return str == "manny legace" ||  str == "manny" || str == "legace" || str == "Manny Legace" || str  == "player" || str == "goalie"; } 
reset(arg)
{
   stuff = random(3);
   ::reset(arg);
    if (arg) return;
set_name("Manny Legace");
    set_race("human");
set_gender("male");
    set_al(300+random(50));	
    set_level(18);
    set_hp(350+random(75));
    set_wc(21);
   set_wc_bonus(3);
    set_ac(22);

   if(stuff == 0) { add_money(3200+random(200)); }

   if(stuff > 0) {
   add_money(1200+random(300));
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);}
    set_short(BOLD+RED+"Manny Legace"+NORM);
    set_long(
      "Manny Legace is the backup goalie for the Detroit Red Wings.\n"+
      "He is on the smallish side at 5-9, 185 lbs.  He is fully dressed in\n"+
      "his uniform, face mask, goalie pads, blocker, chest protector, etc.\n"+
      "This is basically his second full NHL season.  He bounced around\n"+
      "a lot in the minors before earning the backup job in Detroit.  Type\n"+
      RED+"stats legace"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "legace") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-9	weight: 185	born: 2-4-73"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 188th overall 1993	number: 34	"+RED+"*\n"+
"	*"+WHT+"	         by Hartford				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	wins	losses	ties	GAA		"+RED+"*\n"+
"	*"+WHT+"	60	30	14	7	2.25		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(8) == 3) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "over the top of the head","across the back","on the forearm", "on the knee" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Manny Legace "+RED+"wacks "+NORM+MEATN+" "+spellhits[num]+" with his goalie stick.\n");
      MEAT->hit_player(20); return 1; }
   return 1;
}
