/*  Ichabod Crane  */

inherit "obj/monster.c";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("ichabod");
set_alt_name("crane");
set_race("human");
set_short("Ichabod Crane");
set_alias("ichabod crane");
set_long(
	"  Ichabod Crane was an itinerant schoolmaster.  To see him him\n"+
	"strolling along with his coat flapping and fluttering around \n"+
	"him, one might well mistake him for some scarecrow escaped from\n"+
	"a corn field.  He was tall and exceedingly lank.  His head was\n"+
	"small and flat on top with a long pointed nose that looked like\n"+
	"a weather vane perched on his spindle neck.\n");
set_level(17);
set_hp(425);
set_al(-25);
set_wc(24);
set_ac(14);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Ichabod demanded:  Pay attention...\n");
  load_chat("Ichabod preached: Spare the rod and spoil the child.\n");
set_a_chat_chance(25);
  load_a_chat("Ichabod begs: I'll leave town, I promise!\n");
  load_a_chat("Ichabod wimpers as he dodges your attack..\n");

gold = clone_object("obj/money");
gold->set_money(950);
move_object(gold,this_object());
}
