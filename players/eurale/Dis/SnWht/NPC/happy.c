
inherit "obj/monster";
reset(arg) {

object gold;
::reset(arg);
if(arg) return;
set_name("happy");
set_alias("dwarf");
set_race("human");
set_short("Happy");
set_long(
	"  This rotund, jovial fellow is always happy to see a new day.\n"+
	"His white beard is kept close-cropped and he always has a word\n"+
	"of encouragement or praise for his fellow dwarves.\n");
set_hp(400);
set_level(16);
set_al(0);
set_wc(22);
set_aggressive(0);
set_ac(13);

set_chat_chance(20);
  load_chat("Happy waves and says:  Good day! \n");
  load_chat("Happy hums a catchy tune... \n");
set_a_chat_chance(20);
  load_a_chat("Happy says: You'll get a good spanking now! \n");

gold = clone_object("obj/money");
gold->set_money(random(100)+850);
move_object(gold,this_object());
}
