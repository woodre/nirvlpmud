/*  J. Worthington Foulfellow - the fox  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("foulfellow");
set_alt_name("jwf");
set_race("creature");
set_short("J. Worthington Foulfellow");
set_alias("fox");
set_long(
	"  J. Worthington Foulfellow was a crafty fox.  He was partly \n"+
	"to blame for Pinocchio quitting school and joining the theatre.\n"+
	"He carried a cane, had patched knees and elbows on his clothes \n"+
	"and doffed a worn out old tophat.\n");
set_level(17);
set_hp(435);
set_al(-25);
set_wc(24);
set_ac(14);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Foulfellow whispers: Wanna go to Pleasure Island?\n");
  load_chat("Foulfellow tips his hat.....\n");

gold = clone_object("obj/money");
gold->set_money(950);
move_object(gold,this_object());
}
