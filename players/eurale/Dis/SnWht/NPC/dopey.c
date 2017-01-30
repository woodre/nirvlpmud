
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("dopey");
set_alias("dwarf");
set_race("human");
set_short("Dopey");
set_long(
	"  Dopey is a thin, gangly dwarf.  He wears a long robe, tied \n"+
	"at the waist and a long purple stocking cap.  His big ears \n"+
	"stick out from the side of his head but he always has a friendly\n"+
	"smile for anyone he meets.\n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Dopey smiles and looks down to see what his feet are doing. \n");
set_a_chat_chance(20);
  load_a_chat("Dopey cries: You big bulley! \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
