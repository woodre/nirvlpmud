/*  Bill Tilghman  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("bill");
set_race("human");
set_short("Bill Tilghman");
set_alias("tilghman");
set_long(
	"  William Matthew Tilghman (1854-1924)  Frontiersman, scout, \n"+
	"buffalo hunter and one of the best old-time Western lawmen. \n"+
	"Brought many an outlaw to justice.  Became an Oklahoma senator. \n");
set_level(14);
set_hp(210);
set_al(0);
set_wc(18);
set_ac(11);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Bill silently looks around the room. \n");
  load_chat("Bill smiles and gives you a little wink. \n");
  load_chat("Bill asks:  Can I get a quick shave? \n");

gold = clone_object("obj/money");
gold->set_money(random(80)+775);
move_object(gold,this_object());
}
