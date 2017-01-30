
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("anastasia");
set_race("human");
set_short("Anastasia");
set_alias("daughter");
set_alt_name("tasia");
set_long(
	"  Anastasia has red hair and a ruddy complexion.  Her upturned \n"+
	"nose and pouty lips give you the impression that she thinks she \n"+
	"might be just a little better than you. \n");
set_hp(450);
set_level(17);
set_al(0);
set_aggressive(0);

set_ac(14);
set_wc(24);

set_chat_chance(20);
  load_chat("Anastasia says: I'm going to the ball.\n");

gold = clone_object("obj/money");
gold->set_money(random(50)+940);
move_object(gold,this_object());
}
