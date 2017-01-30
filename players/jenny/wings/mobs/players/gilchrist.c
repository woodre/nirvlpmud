inherit "/obj/monster";
#include "/players/jenny/define.h"
int stuff;
id(str) { return str == "brent gilchrist" ||  str == "brent" || str == "gilchrist" || str == "Brent Gilchrist" || str == "player"; } 

reset(arg)
{
    stuff = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("Brent Gilchrist");
   set_race("human");
   set_gender("male");
   set_al(310+random(80));
   set_level(18);
   set_hp(300+random(200));
   set_wc(26);
   set_wc_bonus(2);
   set_ac(16);
   if(stuff == 0) { add_money(3000+random(100)); }

   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}

   if(stuff == 2) { add_money(4000+random(100)); }
   if(!random(4000)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Brent Gilchrist"+NORM);
   set_long(
      "Brent Gilchrist is a player for the Detroit Red Wings.  He is an average\n"+
      "sized guy at 5-10, 180 lbs with dark brown hair.  He is wearing red shorts\n"+
      "and a black t-shirt.  Brent is a third to fourth line checking forward, who\n"+
      "will chip in around 10-20 goals per year.  He has had injury problems the\n"+
      "last few years, but seems healthy now.  Brent is in his thirteenth NHL\n"+
      "season.  Type "+RED+"stats gilchrist"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "gilchrist") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-10	weight: 180	Born: 4-3-67"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 79th overall 1985	number: 41	"+RED+"*\n"+
"	*"+WHT+"		 by Montreal				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penality min.	"+RED+"*\n"+
"	*"+WHT+"	706	131	162	293	372		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(20) < 5) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the nose","in the eye","in the mouth","in the groin" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Brent Gilchrist "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(8); return 1; }
   return 1;
}
