#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("highwayman");
set_alias("man");
set_race("human");
set_short("Highwayman");
set_long(
	"  This is but one of the many ruffians that lurk along Memory\n"+
	"Lane waiting to catch some unsuspecting traveler off guard.  He\n"+
	"strikes without warning and will fight to the death for the\n"+
	"booty he covets.\n");

  set_hp(475);
  set_level(19);
  set_al(0);
  set_wc(28);
  set_ac(16);
  set_heal(2,5);
  set_aggressive(1);

set_chat_chance(20);
  load_chat("Hold it!  Hand over your valuables! \n");
  load_chat("The highwayman smirks at you....\n");
set_a_chat_chance(15);
  load_a_chat("The highwayman attacks with a vengence.... \n");

set_chance(8);
set_spell_dam(random(25));
set_spell_mess1(
  "The highwayman SMASHES his enemy in the face!\n");
set_spell_mess2(
  "The highwayman SMASHES you in the face!\n");

gold = clone_object("obj/money");
gold->set_money(3500 +random(300));
move_object(gold,this_object());
}

init() {
  ::init();
  add_action("north","north"); }

north() {
object ob;
  ob = present("highwayman");
  if(ob) {
	write("A highwayman blocks the road.\n");
	return 1; }
return 1;
}
