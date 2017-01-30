/*  Brom Bones  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("brom");
set_alt_name("bones");
set_race("human");
set_short("Brom Bones");
set_alias("brom bones");
set_long(
	"  Brom Bones was a ruggedly handsome young man.  His skill at\n"+
	"horsemanship is well known.  He is foremost at most races and\n"+
	"cockfights and, with the leadership that bodily strength confers\n"+
	"in rustic life, he is the umpire in all disputes.  He is always\n"+
	"ready for either a fight or a frolic, but has more mischief \n"+
	"than ill will in his makeup.  And with all his overbearing\n"+
	"roughness, there is a strong dash of waggish good humor at \n"+
	"bottom.\n");
set_level(19);
set_hp(485);
set_al(0);
set_wc(28);
set_ac(16);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Brom laughs and continues his story...\n");
  load_chat("Brom whispers something to his friend...\n");
set_a_chat_chance(20);
  load_a_chat("Brom says: I'll give you a good thumpin' now!\n");
  load_a_chat("Brom throws a 'haymaker' at you...\n");
  load_a_chat("Brom grins as he takes a swing..\n");

gold = clone_object("obj/money");
gold->set_money(950);
move_object(gold,this_object());
}
