inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "brendan shanahan" ||  str == "brendan" || str == "shanahan" || str == "Brendan Shanahan" || str == "player"; } 
int stuff;
reset(arg)
{
   stuff = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("Brendan Shanahan");
   set_race("human");
   set_gender("male");
   if(!random(2)) {set_aggressive(1); }
   set_al(820+random(120));
   set_level(20);
   set_hp(450+random(15));
   set_wc(33+random(11));
   set_wc_bonus(6);
   set_ac(15+random(2));
   if(stuff == 0) { add_money(3700+random(3000)); }
   if(stuff > 0) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(!random(850)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(850)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Brendan Shanahan"+NORM);
   set_long(
      "Brendan Shanahan plays left wing for the Detroit Red Wings.\n"+
      "He is a big guy at 6-3, 220 lbs with dark hair.  He is wrapped\n"+
      "in a towel and enjoying the sauna.  Brendan is in his fourteenth\n"+
      "NHL season, and on his way to a Hall of Fame career.  He\n"+
      "has a great combination of skills for a hockey player.  He can fight,\n"+
      "check, and is also one of the best goal scorers in the league.  Type\n"+
      RED+"stats shanahan"+NORM+" to see Brendan's career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "shanahan") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-3	weight: 220	Born: 1-23-69"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 2nd overall 1987	number: 14	"+RED+"*\n"+
"	*"+WHT+"		 by New Jersey				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	Penalty Min	"+RED+"*\n"+
"	*"+WHT+"	1028	466	489	955	1935		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(100) < 17) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      say("\n");
       say("Brendan takes a large rock out of the barrel and wacks "+MEATN+" in the head.\n"+
        BOLD+RED+"                      Blood "+NORM+"squirts all over.\n");
      MEAT->hit_player(36); return 1; }
   return 1;
}
