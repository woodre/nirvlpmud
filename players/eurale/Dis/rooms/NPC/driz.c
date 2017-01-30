
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("drizella");
set_race("human");
set_short("Drizella");
set_alias("daughter");
set_alt_name("driz");
set_long(
	"  Drizella is a short, plump, raven haired girl.  She has much \n"+
	"the same dispostion as her mother.  Her crooked teeth match her\n"+
	"general attitude.\n");
set_hp(450);
set_level(18);
set_al(0);
set_aggressive(0);

set_ac(15);
set_wc(26);

set_chat_chance(20);
  load_chat("Drizella asks: How do I look?  How do I look? \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+975);
move_object(gold,this_object());
}
