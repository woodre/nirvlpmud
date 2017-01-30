/*  Figaro - the cat  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("figaro");
set_race("creature");
set_short("Figaro");
set_alias("cat");
set_long(
	"  Figaro is a small black cat with a white stomach and socks.\n"+
	"She spends her time sleeping in the sun or watching Cleo, the\n"+
	"goldfish, swim around his fish bowl.\n");
set_level(12);
set_hp(194);
set_al(0);
set_wc(16);
set_ac(9);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Meow.........meow........... \n");
  load_chat("Figaro rubs up against your leg.... \n");
set_a_chat_chance(25);
  load_a_chat("Figaro scratches at your eyes.....\n");
  load_a_chat("Figaro BITES your leg...\n");

gold = clone_object("obj/money");
gold->set_money(600);
move_object(gold,this_object());
}
