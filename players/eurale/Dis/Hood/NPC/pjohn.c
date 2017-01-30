#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("john");
set_alias("prince");
set_alt_name("prince john");
set_race("human");
set_short("Prince John");
set_long(
	"  This cowardly gentleman is nothing but a pawn to the evil\n"+
	"Sheriff.  He's managed to work his way into a position of power\n"+
	"and now takes great delight in exploiting the King's servants.\n"+
	"The Royal ring he wears gives weight to his postion but not to\n"+
	"his character.\n");

  set_hp(500);
  set_level(20);
  set_al(-100);
  set_wc(30);
  set_ac(18);
  set_aggressive(0);
if(!present("ring")) {
move_object(clone_object("players/eurale/Dis/Hood/OBJ/ring"),
	this_object()); }
init_command("wear ring");
  set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Prince offers his ring for you to kiss..\n");
  load_chat("What do you need? asks the Prince disgustedly\n");
set_a_chat_chance(15);
  load_a_chat("The Prince winces as he hits you....\n");
  load_a_chat("The Prince screams for help....\n");
  load_a_chat("The Prince barks: I never said I couldn't fight!\n");

gold = clone_object("obj/money");
gold->set_money(3500);
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
  "\nWhere was that DAMN Sheriff when I needed him?...\n");
return 0; }
