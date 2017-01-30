
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("bashful");
set_alias("dwarf");
set_race("human");
set_short("Bashful");
set_long(
	"  This is the timid dwarf.  He's always afraid he might do some-\n"+
	"thing wrong or hurt someone's feelings.  He has a long white \n"+
	"beard, dark eyes and a bulbus nose. \n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Bashful says: Jeez, sorry.... didn't mean to do that.\n");
  load_chat("Bashful blushes.....\n");
set_a_chat_chance(20);
  load_a_chat("Bashful says: Should I help? \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
