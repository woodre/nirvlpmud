
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("grumpy");
set_alias("dwarf");
set_race("human");
set_short("Grumpy");
set_long(
	"  This poor fellow can't remember the last time he had a decent\n"+
	"day.  His constant frowning is enough to make you want to tickle\n"+
	"him.  His full, white beard and wrinkled brow make him a dead \n"+
	"giveaway.\n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Grumpy says:  What a crappy day! \n");
set_a_chat_chance(20);
  load_a_chat("Grumpy hollars: That does it... you're dead now! \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
