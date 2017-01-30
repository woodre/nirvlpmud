inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "steve yzerman" ||  str == "steve" || str == "yzerman" || str == "Steve Yzerman" || str == "player"; } 
int stuff;
int NUM;
object ob;
reset(arg)
{
   NUM = 1;
   stuff = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("Steve Yzerman");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(25);
   set_hp(900+random(200));
   set_ac(23+random(2));
   set_heal(3,2);
   if(stuff == 0) {
   MOCO("/players/jenny/wings/items/stevestick.c"),TO);
   init_command("wield stick");
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   add_money(5000+random(2000)); }
   if(stuff == 1) {
   MOCO("/players/jenny/wings/items/stevestick.c"),TO);
   init_command("wield stick");
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   MOCO("/players/jenny/wings/items/painkillers.c"),TO); }
   if(stuff == 2) {
   MOCO("/players/jenny/wings/items/stevestick.c"),TO);
   init_command("wield stick");
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   add_money(4000+random(1000)); }
   if(!random(400)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}
   if(!random(400)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_wc(45+random(3));
   set_wc_bonus(26);
   set_short(BOLD+RED+"Steve Yzerman"+NORM);
   set_long(
      "Steve Yzerman is a center for the Detroit Red Wings, and also their\n"+
      "team captain.  He is an average size guy at 5-11, 180 lbs with dark\n"+
      "brown hair, and wearing red shorts and a grey t-shirt.  Steve has had\n"+
      "a Hall Of Fame career.  He is one of the top scorers in NHL history\n"+
      "and has also become a good defensive player, winning the Selke Trophy\n"+
      "as the top defensive forward in 1999.  Type "+RED+"stats yzerman"+NORM+" to see\n"+           "Steve's career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
add_action("nomove","north");
add_action("nomove","south");
add_action("nomove","west");
add_action("nomove","east");
}

	thestats(arg) {
if(arg == "yzerman") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 5-11	weight: 180	Born: 5-9-65"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 4th overall 1983	number: 19	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	Penalty Min	"+RED+"*\n"+
"	*"+WHT+"	1310	645	969	1614	834		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
nomove() {
     if(MEAT) {
write("Steve has ahold of you and won't let go.\n");
   return 1; }}
heart_beat() {
if(!environment()) return;
if(ob = present("darren mccarty", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } 

   ::heart_beat();
  if(MEAT){
    if((50 - INTMEAT)  > random(100)) gethit();
    if(random(4) > NUM) gethelp();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in a choke hold","in a headlock","in a hammerlock","in a bear hug","in a full nelson","in a wrist lock" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Steve Yzerman gets "+MEATN+" "+RED+spellhits[num]+NORM+".\n");
      MEAT->hit_player(30+random(26)); return 1; }
   return 1;
}
gethelp() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
   say("\n"+
         "Darren McCarty rushes to the aid of his teammate.\n");
            MOCO("/players/jenny/wings/mobs/players/mccarty.c"),ENVTO);
            NUM = 50;
   return 1;}
   return 1;}
