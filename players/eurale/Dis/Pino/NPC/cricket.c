/*  Jiminy Cricket  */

inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("jiminy cricket");
set_alt_name("jiminy");
set_race("creature");
set_short("Jiminy Cricket");
set_alias("cricket");
set_long(
	"  This green little fellow is never without his red vest, black\n"+
	"topcoat, blue tophat, spats and his umbrella.  He is said to be\n"+
	"over a hundred years old and can talk.\n");
set_level(16);
set_hp(400);
set_al(800);
set_wc(22);
set_ac(13);
set_aggressive(0);

set_chat_chance(20);
  load_chat("Jiminy says: Always let your conscience be your guide.\n");
  load_chat("Jiminy implores:  Quick quick..Geppetto needs help!\n");
set_a_chat_chance(20);
  load_a_chat("Jiminy hops to the side of your attack...\n");
  load_a_chat("Jiminy ask: Your conscience told you THIS?\n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
