inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "darren mccarty" ||  str == "darren" || str == "mccarty" || str == "Darren McCarty" || str == "player"; } 
int stuff;
object ob;
reset(arg)
{
   stuff = random(5);
   ::reset(arg);
   if (arg) return;
   set_name("Darren McCarty");
   set_race("human");
   set_gender("male");
   set_al(750+random(100));
   set_level(19);
   set_hp(450);
   set_wc(31);
   set_wc_bonus(7);  
   set_ac(15);
   set_heal(3,2);
   if(stuff == 0) { add_money(3000+random(2000)); }
   if(stuff > 0) {
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);}
   if(!random(1500)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}

   if(!random(1500)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Darren McCarty"+NORM);
   set_long(
      "Darren McCarty plays right wing for the Detroit Red Wings.  He\n"+
      "is a big guy at 6-1, 214 lbs.  Darren has curly light brown hair\n"+
      "and is wearing blue shorts and a grey t-shirt.  Darren is in his eighth\n"+
      "NHL season, and has become an important part of this team.  He is\n"+
      "their best fighter, and also scores 10-20 goals per year.  Anyone who\n"+
      "attacks one of the Detroit's star players knows they will also have to\n"+
      "deal with him.  Type "+RED+"stats mccarty"+NORM+" to see Darren's career stats.\n");
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
if(arg == "mccarty") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-1	weight: 214	Born: 4-1-72"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 46th overall 1992	number: 25	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	Penalty Min	"+RED+"*\n"+
"	*"+WHT+"	465	95	133	228	989		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
nomove() {
write("McCarty has ahold of you and won't let go.\n");
return 1;}
heart_beat() {
if(!environment()) return;
if(ob = present("steve yzerman", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } 

   ::heart_beat();
  if(MEAT){
    if( random(100) < 28) gethit();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "in the nose","in the mouth","in the eye" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Darren McCarty "+RED+"punches "+NORM+MEATN+" "+spellhits[num]+" with a hard left.\n");
      MEAT->hit_player(25); return 1; }
   return 1;
}
