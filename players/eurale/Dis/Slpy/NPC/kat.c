/*  Katrina Van Tassel  */

inherit "obj/monster.c";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("katrina");
set_alt_name("van tassel");
set_race("human");
set_short("Katrina Van Tassel");
set_alias("katrina van tassel");
set_long(
	"  This is the 18 year old daughter of Baltus Van Tassel, the\n"+
	"wealthiest farmer in the county.  She is the only child of \n"+
	"this strict man and the apple of his eye.  She is a blossom-\n"+
	"ing lass, plump as a partridge, ripe, melting, and rosy-cheeked.\n"+
	"She is also a coquette.\n");
set_level(14);
set_hp(210);
set_al(0);
set_wc(18);
set_ac(11);
set_gender("female");
set_aggressive(0);

set_chat_chance(20);
  load_chat("Katrina flutteres her eyelashes....\n");
  load_chat("Swish.... go her peticoats...\n");
set_a_chat_chance(15);
  load_a_chat("Katrina asks: You'd attack a lady?\n");
  load_a_chat("Katrina SLAPS your face hard...\n");

gold = clone_object("obj/money");
gold->set_money(850);
move_object(gold,this_object());
}
