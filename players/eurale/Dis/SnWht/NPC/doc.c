
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("doc");
set_alias("dwarf");
set_race("human");
set_short("Doc");
set_long(
	"  Doc is the only dwarf who wears spectacles.  His bright red\n"+
	"stocking cap and coat to match really set off his short gray \n"+
	"beard.  He does a great job of keeping all the other dwarves\n"+
	"fit as a fiddle..... all except poor Sneezy.\n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Doc asks: You feeling all right today? \n");
set_a_chat_chance(20);
  load_a_chat("Doc sneers: I'll make you feel a lot worse now! \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
