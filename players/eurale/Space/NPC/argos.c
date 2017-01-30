#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("argos");
set_race("creature");
set_short(HIB+"Argos"+NORM);
set_long(
	"  This argos is an amoeba-like creature with one large, central\n"+
	"eye with a tripartite pupil and a hundred lashless, inhuman eyes\n"+
	"and many sharp_toothed mouths.  It can extrude several pseudo-\n"+
	"pods, each tipped with a fanged maw.  It moves by slithering\n"+
	"and has been known to cling to walls and ceilings and might\n"+
	"even levitate.\n");

set_level(19);
  set_hp(400 + random(75));
  set_al(0);
  set_wc(25 + random(4));
  set_ac(15);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Something smells like a bouquet of flowers...\n");
  load_chat("The Argos makes a 'squishy' sound as it moves...\n");
set_a_chat_chance(15);
  load_a_chat("The argos makes a feeble attempt to grab you...\n");
  load_a_chat("You feel a slight prick from the Argos's maw...\n");

gold = clone_object("obj/money");
gold->set_money(1800 + random(300));
move_object(gold,this_object());
}
