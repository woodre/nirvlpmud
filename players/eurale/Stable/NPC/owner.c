/*  stable owner  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("owner");
set_race("human");
set_short("The stable owner");
set_long(
	"  This large, burly man has obviously worked for a living all his \n"+
	"life.  His toughened hands and sweaty clothes are a testament to \n"+
	"the hard way of life he's chosen.  Underneath his clothes, however\n"+
	"you sense strong muscles from the years of hard labor.\n");
set_level(18);
set_hp(450);
set_al(0);
set_wc(24);
set_ac(15);
set_aggressive(0);

set_chat_chance(20);
  load_chat("The owner says:  Can I help you, sir? \n");
  load_chat("The owner asks:  Would you like to board your horse? \n");
  load_chat("He kicks a small dirt clod with his heavy boot. \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+1000);
move_object(gold,this_object());
}
