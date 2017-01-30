/*  Sleep Hollow Boy  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("boy");
set_race("human");
set_short("Sleepy Hollow Boy");
set_alias("sleepy hollow boy");
set_long(
	"  This strapping lad is one of the local ruffians.  He spends\n"+
	"a great deal of his time here in the pub.  He is a follower of\n"+
	"Brom Bones, the leader of the Boys.\n");
set_level(17);
set_hp(435);
set_al(-25);
set_wc(24);
set_ac(14);
set_aggressive(0);

set_chat_chance(20);
  load_chat("The Sleepy Hollow Boy sips his ale....\n");
set_a_chat_chance(20);
  load_a_chat("The Boy pummels you in the stomach....\n");

gold = clone_object("obj/money");
gold->set_money(950);
move_object(gold,this_object());
}
