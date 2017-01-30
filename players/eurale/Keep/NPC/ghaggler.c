/*  Modified October 2001 to conform to /doc/build/RULES/monster.guide */

#include "/players/eurale/defs.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("ghaggler");
set_race("creature");
set_short(HIG+"Ghaggler"+NORM);
set_long(
	"This ghaggler is a 7 foot tall humanoid with a tough, horny,\n"+
	"hairless hide.  He has pointed ears with large earlobes, a\n"+
	"long, thin snout and a huge mouth filled with large teeth.\n"+
	"The front teeth are curved inward like fish hooks to grasp\n"+
	"and hold prey.  He has slit-like eyes that are jet black with\n"+
	"tiny white pupils in the center.  His blunt tail extends no\n"+
	"more than a few inches.  His hands and feet are webbed which\n"+
	"makes him an exceptional swimmer.\n");

set_level(20);
set_hp(550);
set_al(0);
if(!present("trident")) {
move_object(clone_object("players/eurale/Keep/OBJ/trident"),TO); }
init_command("wield trident");
set_wc(30 + random(8));
set_ac(17);
set_aggressive(0);

set_chat_chance(15);
  load_chat("The ghaggler inches closer to the water...\n");
  load_chat("HIIIIISSSSSSSSSSSSSSS......\n");
set_a_chat_chance(15);
  load_a_chat("The ghaggler spits in your eye.....\n");
  load_a_chat("The ghaggler dodges your attack...\n");

set_chance(8);
set_spell_dam(30);
set_spell_mess1(
  HIG+"\nYou see the trident penetrate flesh.....\n\n"+NORM);
set_spell_mess2(
  HIG+"\nYou feel the trident penetrate your flesh.....\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(3000 + random(1500));
move_object(gold,this_object());
}
