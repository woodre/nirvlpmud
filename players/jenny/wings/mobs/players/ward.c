/*    Monster special works off opponent's strength.  With str of 20, goes off 1/5 of the time */
inherit "/obj/monster";
#include "/players/jenny/define.h"
int stuff;
id(str) { return str == "aaron ward" ||  str == "aaron" || str == "ward" || str == "Aaron Ward" || str  == "player"; } 
reset(arg)
{ 
   stuff = random(3);
   ::reset(arg);
    if (arg) return;
    set_name("Aaron Ward");
    set_race("human");
    set_gender("male");
    set_al(350+random(100));	
    set_level(18);
    set_hp(400+random(5));
    set_wc(27);
    set_ac(15);
   set_wc_bonus(2+random(2));
    if(random(10) > 2) { set_aggressive(1); }
   if(stuff == 0) { add_money(3150+random(200)); }

   if(stuff == 1) {
   add_money(1000+random(500));
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}

   if(stuff == 2) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(!random(1800)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(3000)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
    set_short(BOLD+RED+"Aaron Ward"+NORM);
    set_long(
      "Aaron Ward is one of the players for the Detroit Red Wings.  He\n"+
      "is a pretty big guy at 6-2, 225 lbs  He has short, blonde hair and\n"+
      "is wearing maze and blue University of Michigan shorts and shirt.\n"+
      "He is a solid fifth or sixth defensemen, who plays a physical game,\n"+
      "but does not contribute much offensively.  Aaron is in his fifth NHL\n"+
      "season.  Type "+RED+"stats ward"+NORM+" to see his career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
}

	thestats(arg) {
if(arg == "ward") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-2	weight: 225	born: 1-17-73"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	drafted: 5th overall 1991	number: 27	"+RED+"*\n"+
"	*"+WHT+"		 by Winnipeg         			"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	penalty min.	"+RED+"*\n"+
"	*"+WHT+"	276	16	27	43	238		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
heart_beat() {
   ::heart_beat();
  if(MEAT){
    if( random(STRMEAT) < 4) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "up against the wall","over the weightlifting bench","to the ground","into the rack of dumbells" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Aaron Ward "+RED+"throws "+NORM+MEATN+" "+spellhits[num]+".\n");
      MEAT->hit_player(13); return 1; }
   return 1;
}
