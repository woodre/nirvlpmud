/*  Kit Carson  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("kit");
set_race("human");
set_short("Kit Carson");
set_alias("carson");
set_long(
	"  Christopher Carson (1809-1868)  Frontiersman, trapper, hunter, \n"+
	"soldier, guide to Fremont, Indian agent, brevetted brigadier \n"+
	"general.  He had close contact with Native Americans in many \n"+
	"states and territories. \n");
set_hp(400);
set_level(16);
set_al(20);
set_wc(22);
set_ac(13);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Kit says:  This country is headed for a change. \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+900);
move_object(gold,this_object());
}
