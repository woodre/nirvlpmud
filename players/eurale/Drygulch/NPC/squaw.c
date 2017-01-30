/*  an indian squaw  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("squaw");
set_race("human");
set_short("an Indian squaw");
set_long(
	"  This is one of the camp squaws.  Her job is to cook, clean \n"+
	"and see that the teepee is well kept for her brave. \n");
set_level(12);
set_hp(180);
set_al(0);
set_wc(16);
set_ac(9);
set_aggressive(0);

set_chat_chance(5);
  load_chat("The squaw looks away so as not to offend. \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+550);
move_object(gold,this_object());
}
