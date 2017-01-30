#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("woman");
set_alias("englishwoman");
set_race("human");
set_short("Englishwoman");
set_long(
	"  This ordinary English woman is dressed in a wool skirt and\n"+
	"sweater to keep out the chill of the damp.  She is one of the\n"+
	"many women who live and work around London.\n");

set_level(17);
  set_hp(450);
  set_al(50);
  set_wc(24);
  set_ac(14);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("The Englishwoman looks out the window...\n");
set_a_chat_chance(15);
  load_a_chat("The Englishwoman SCREAMS...... \n");

gold = clone_object("obj/money");
gold->set_money(900+random(100));
move_object(gold,this_object());
}
