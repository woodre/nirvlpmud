
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
	"  Every family has a member that's 'unique.'  This little porker \n"+
	"is that member of the Swine family that lives along Piglet \n"+
	"Parkway.  She's a real 'libber.'  She built this stone and \n"+
	"mortar house by herself and has taken a few self-defense \n"+
	"classes on the side to be prepared. \n");
set_hp(random(80)+460);
set_level(19);
set_al(0);
set_aggressive(0);

set_ac(16);
set_wc(28);

set_chat_chance(20);
  load_chat("The piggy oinks... \n");
  load_chat("Little pig does a few pushups... \n");
  load_chat("Little pig asks:  Wanna arm wrestle? \n");

gold = clone_object("obj/money");
gold->set_money(random(50)+1975);
move_object(gold,this_object());
}
