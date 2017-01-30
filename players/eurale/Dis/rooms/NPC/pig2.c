
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("pig");
set_race("creature");
set_short("Little Pig");
set_alias("little pig");
set_long(
	"  This rotund little porker is one of the Swine family that \n"+
	"lives along Piglet Parkway.  Because of his dislike of hard \n"+
	"work, he made his house of sticks. \n");
set_hp(random(80)+410);
set_level(18);
set_al(0);
set_aggressive(0);

set_ac(15);
set_wc(26);

set_chat_chance(20);
  load_chat("The piggy oinks... \n");
  load_chat("Little pig asks:  Do you feel a draft? \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+975);
move_object(gold,this_object());
}
