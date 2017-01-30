/*special works so the more hp the monster has, the more it's special goes off.  It gives a strategy decision, kill it first, or lapointe.c, which has fewer hp i'll assume hp of 850 for purposes of the wc bonus, I put this number above the halfway point because many will kill lapointe.c first.
bumped wc bonus up to 40 - reflects that lapointe.c is hitting you as well.  it was a much tougher kill than the exp it was worth before
*/
inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "sergei fedorov" ||  str == "sergei" || str == "fedorov" || str == "Sergei Fedorov" || str == "player"; } 
int stuff;
int NUM;
object ob;
reset(arg)
{
   NUM = 1;
   stuff = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("Sergei Fedorov");
   set_race("human");
   set_gender("male");
   set_al(1000);
   set_level(26);
   set_hp(1000+random(400));
   set_wc(46+random(5));
   set_wc_bonus(40);
   set_ac(24+random(4));
   set_ac_bonus(1);
   set_heal(3,2);
   if(stuff == 0) {
   MOCO("/players/jenny/wings/items/skates.c"),TO);
   init_command("wear skates");
   MOCO("/players/jenny/wings/items/gatorade.c"),TO);
   MOCO("/players/jenny/wings/items/powerbar.c"),TO);
   add_money(8000+random(3000)); }
   if(stuff > 0) {
   MOCO("/players/jenny/wings/items/skates.c"),TO);
   init_command("wear skates");
   MOCO("/players/jenny/wings/items/painkillers.c"),TO);
   add_money(8000+random(5000)); }
   if(!random(400)) {
   MOCO("/players/jenny/wings/items/1997ring.c"),TO);
   init_command("wear ring");}
   if(!random(400)) {
   MOCO("/players/jenny/wings/items/1998ring.c"),TO);
   init_command("wear ring");}
   set_short(BOLD+RED+"Sergei Fedorov"+NORM);
   set_long(
      "Sergei Fedorov is a center for the Detroit Red Wings.  He is big guy at\n"+
      "6-2, 198 lbs.  He has light brown hair, and is dressed in his uniform,\n"+
      "gloves, pads, etc.  Sergei is one of the most exciting players in the NHL.\n"+
      "He is one of the best skaters in the game, as well as one of hockey's\n"+
      "most creative playmakers.  He has a very hard shot, and is also one of\n"+
      "the best defensive players in the league.  In 1994, Sergei won the Heart\n"+
      "Trophy, as the league MVP, and he has twice won the Selke Trophy as\n"+
      "the best defensive forward.  Type "+RED+"stats fedorov"+NORM+" to see Sergei's career stats.\n");
}
init() {
  ::init();
add_action("thestats","stats");
add_action("nomove","north");
add_action("nomove","south");
add_action("nomove","west");
add_action("nomove","east");
add_action("nomove","out");
}

	thestats(arg) {
if(arg == "fedorov") {
write(RED+
"\n"+
"	*********************************************************\n"+
"	*							*\n"+
"	*	"+WHT+"hight: 6-2	weight: 198	Born: 12-13-69"+RED+"	*\n"+
"	*							*\n"+
"	*"+WHT+"	Drafted: 74th overall 1989	number: 91	"+RED+"*\n"+
"	*"+WHT+"		 by Detroit				"+RED+"*\n"+
"	*							*\n"+
"	*							*\n"+
"	*"+WHT+"		career totals through 2001		"+RED+"*\n"+
"	*"+WHT+"	games	goals	assists	points	Penalty Min	"+RED+"*\n"+
"	*"+WHT+"	747	333	470	803	499		"+RED+"*\n"+
"	*							*\n"+
"	*********************************************************"+NORM+"\n");
return 1;}}
nomove() {
     if(MEAT) {
write("Sergei has ahold of you and won't let go.\n");
   return 1; }}
heart_beat() {
if(!environment()) return;
if(ob = present("martin lapointe", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } 

   ::heart_beat();
/* no TO if monster dies during regular hb */
  if(!TO) return;
  if(MEAT){
    if( TO->query_hp() > random(2000)) gethit();
    if(random(4) > NUM) gethelp();
  }
}

gethit() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
      int num;
      string *spellhits;
      spellhits = ({ "upside the head","on the arm","on the hand","on the knee","in the groin","in the throat" });
      num = random(sizeof(spellhits));
      say("\n");
       say("Sergei Fedorov "+RED+"slashes "+NORM+MEATN+" "+spellhits[num]+" with his stick.\n");
      MEAT->hit_player(45+random(20)); return 1; }
   return 1;
}
gethelp() {
   if(!environment(this_object())) return 1;
   if(MEAT)
      if(environment() == environment(MEAT)) {
   say("\n"+
         "Martin Lapointe rushes to the aid of his teammate.\n");
            MOCO("/players/jenny/wings/mobs/players/lapointe.c"),ENVTO);
            NUM = 50;
   return 1;}
   return 1;}
