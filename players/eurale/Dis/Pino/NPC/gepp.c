/*  Geppetto  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("geppetto");
set_race("human");
set_short("Geppetto");
set_long(
	"  Meet Geppetto the carver.  He's been swallowed by Monstro the\n"+
	"whale while searching for his Pinocchio.  This kind old gentle-\n"+
	"man with the white hair and moustache to match has spent many \n"+
	"years waiting for this moment... and now look at him!\n");
set_level(19);
set_hp(475);
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Geppetto coughs.....\n");
  load_chat("Geppetto hollars: HELP!! \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+2000);
move_object(gold,this_object());
}
