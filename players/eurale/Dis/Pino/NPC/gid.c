/*  Gideon - the alley cat  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("gideon");
set_alt_name("alley cat");
set_race("creature");
set_short("Gideon");
set_alias("cat");
set_long(
	"  Gideon was a tabby colored alley cat.  He has been known to \n"+
	"associate with J. Worthington Foulfellow.  He wears a brown \n"+
	"cloak and carries a walking stick.\n");
set_level(17);
set_hp(435);
set_al(-25);
set_wc(24);
set_ac(14);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Gideon chuckles to himself...\n");
  load_chat("Gideon purrrrrs.......\n");

gold = clone_object("obj/money");
gold->set_money(950);
move_object(gold,this_object());
}
