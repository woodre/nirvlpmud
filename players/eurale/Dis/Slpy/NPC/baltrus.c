/*  Baltus Van Tassel  */

inherit "obj/monster.c";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("baltus");
set_alt_name("van tassel");
set_race("human");
set_short("Baltus Van Tassel");
set_alias("dad");
set_long(
	"  Baltus Van Tassel is the wealthiest farmer in the county.\n"+
	"His lavish parties with all their merrymaking have been the \n"+
	"talk of town on many an occasion.  This plump, balding man\n"+
	"with the handlebar moustache and wire-rimmed spectacles is\n"+
	"always on the lookout for those who would court is daughter.\n");
set_level(19);
set_hp(485);
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Baltus says: Welcome... come in. \n");
  load_chat("Baltus surveys the room....\n");
  load_chat("Baltus clears his throat..\n");
set_a_chat_chance(20);
  load_a_chat("Baltus kicks your HARD!! \n");

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold,this_object());
}
