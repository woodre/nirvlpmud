/*  the Drygulch barber  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("barber");
set_race("human");
set_short("the Drygulch barber");
set_long(
	"  This short, stout man has neatly trimmed hair and a waxed, \n"+
	"handlebar moustache.  He is ready to serve the people of Drygulch.\n");
set_level(14);
set_hp(210);
set_al(0);
set_wc(18);
set_ac(11);
set_aggressive(0);

set_chat_chance(5);
  load_chat("The barber says:  Care for a cut and shave today? \n");
  load_chat("The barbers kicks the hair into neat piles with his boot.\n");

gold = clone_object("obj/money");
gold->set_money(random(80)+775);
move_object(gold,this_object());
}
