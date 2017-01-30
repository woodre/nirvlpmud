/* approved by Mythos <11-4-96> */

/* Updated monster's level and wc,ac and added spells to
strengthen by Pestilence per Dragnar 8-9-2014 */
#define ETO environment(this_object())
#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

if(!present("plasma")) {
/* Chalice replaced by plasma 8/18/02 - Eurale
  move_object(clone_object("players/eurale/Fiend/OBJ/silver_chalice"),
*/
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/plasma"),
  this_object()); }

set_name(HIR+"Count Dracula"+NORM);
set_alias("count");
set_alt_name("count dracula");
set_race("vampire");
set_short("Count Dracula");
set_long(
	"  A stunningly good looking man with palid skin and coal black\n"+
	"hair. He wore a black tie and tails with his patent leather\n"+
	"shoes.  The 1931 horror show, Dracula, opened on Valentine's\n"+
	"Day with the hungarian actor, Bela Lugosi, starring in the lead.\n"+
	"From the moment Lugosi appeared on the screen and announced 'I\n"+
	"am....Dracula,' he remained the 'King of the Living Dead.'\n");

set_level(26);
  set_hp(1600);
  set_al(-100);
  set_wc(52);
/*
  set_wc_bonus(12);
*/
  set_ac(28);
  set_ac_bonus(18);
  set_heal(35,5);
  set_aggressive(1);
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Dracula glares at you.....\n");
set_a_chat_chance(15);
  load_a_chat("Dracula hisses.....\n");
  load_a_chat("Dracula runs his tongue over his long fangs...\n");

/*
set_chance(10);
set_spell_dam(50);

set_spell_mess1(
  "\n\nDracula BITES into the jugular and "+RED+"B L O O D "+NORM+
	" spurts across the room.\n\n");
set_spell_mess2(
  "\n\nDracula BITES into #TN#'s jugular and "+RED+"B L O O D"+NORM+
	" spurts across the room.\n\n");
*/

add_spell("bite",
  "\n\nDracula BITES into your jugular and $R$B L O O D$N$ spurts across the room.\\n",
  "\n\nDracula BITES into the jugular and $R$B L O O D$N$ spurts across the room.\n\n",
10,50,0,0);

add_spell("drain",
"#MN# sinks his fangs into #TN#'s neck\n",
"#MN# sinks his fangs into #TN#'s neck\n",
30,"40-60",0,3,"heal_me");


}

id(str) { return (::id(str) || str == "dracula"); }
monster_died() {
  tell_room(environment(this_object()),
  "\n\nWith "+RED+"B L O O D"+NORM+" running from his nose and mouth..\n"+
  "\nCount Dracula falls to the earth.... dead.\n\n");
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/plasma"),ETO);
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/plasma"),ETO);
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/plasma"),ETO);
  move_object(clone_object("/players/eurale/VAMPIRES/OBJ/plasma"),ETO);
return 0; }
heal_me( object target, object room, int damage ) {
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(HIR+"Dracula drains "+HIW+ATT_NAME+"'s blood"+NORM+", making him feel refreshed!\n"+NORM);
       tell_object(attacker_ob,
HIR+"Dracula drains your blood"+NORM+", making him feel refreshed!\n"+NORM);
heal_self(20+random(15));
}
