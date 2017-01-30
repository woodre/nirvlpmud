
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("sneezy");
set_alias("dwarf");
set_race("human");
set_short("Sneezy");
set_long(
	"  AAAHHHHCCCHHHHOOOO!  Sniff!  This good natured dwarf has some \n"+
	"serious allergies to the forest.  You never see him without a hanky\n"+
	"in his hand.  His blue eyes are always clouded with the tears \n"+
	"brought on by his hay fever.\n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Sneeezy sneezes and wipes his nose.... \n");
set_a_chat_chance(20);
  load_a_chat("Sneezy coughs and takes a BIG swing... \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
