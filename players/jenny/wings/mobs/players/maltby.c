inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "kirk maltby" ||  str == "kirk" || str == "maltby" || str == "Kirk Maltby" || str == "player"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Kirk Maltby");
   set_race("human");
   set_gender("male");
   set_al(375+random(100));
   set_level(18);
   set_hp(400);
   set_wc(28);
   set_wc_bonus(2);
   set_ac(15);
    add_money(3000+random(1000));
    if(!random(3)) { set_aggressive(1); }
   if(!random(1750)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1750)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Kirk Maltby"+NORM);
   set_long(
      "Kirk Maltby is a player for the Detroit Red Wings.  He is a strong guy at\n"+
      "6-0 195 lbs.  He is dripping wet, and wrapped in a thick white towel.\n"+
      "Kirk is a third to fourth line checking forward, who plays a physical\n"+
      "game, and will chip in around 10 goals per year.  He is in his eighth NHL\n"+
      "season.  Type "+RED+"stats maltby"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "maltby") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-0	weight: 195	Born: 12-22-72"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 65th overall 1992	number: 18	"+RED+"*\n"+
"	*"+WHT+"		 by Edmonton				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	474	65	52	117	434		"+RED+"*\n"+
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
      spellhits = ({ "against the wall","to the ground"});
      num = random(sizeof(spellhits));
      say("\n");
       say("Kirk Maltby "+RED+"throws "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(10); return 1; }
   return 1;
}
