/*  Pinocchio  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("pinocchio");
set_race("human");
set_short("Pinocchio");
set_alias("puppet");
set_long(
	"  This little wooden puppet was turned human by the Blue Fairy.\n"+
	"His feathered cap and big blue bow tie go nicely with his red \n"+
	"shorts.  He's trying hard to make himself worthy of being human.\n");
set_level(18);
set_hp(450);
set_al(0);
set_wc(26);
set_ac(15);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Pinocchio whines: I want to be a real boy.\n");
  load_chat("Pinocchio asks: Have you seen Geppetto?\n");
set_a_chat_chance(20);
  load_a_chat("Pinocchio bats you with his wooden arm....\n");
  load_a_chat("The wooden boy JUMPS on your foot!\n");

gold = clone_object("obj/money");
gold->set_money(random(100)+950);
move_object(gold,this_object());
}
