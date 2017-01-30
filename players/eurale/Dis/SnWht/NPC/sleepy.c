
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("sleepy");
set_alias("dwarf");
set_race("human");
set_short("Sleepy");
set_long(
	"  This is Mr. slow motion himself.  He never seems to get enough\n"+
	"sleep.  His clothes are always disheveled and he has perpetual\n"+
	"bags under his eyes.\n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Sleepy yawns...... \n");
set_a_chat_chance(20);
  load_a_chat("Sleepy takes a half-hearted swing.... \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
