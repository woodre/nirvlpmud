#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("marian");
set_alias("maid marian");
multipleIds = ({"maid","marian","maid marian"});
set_race("human");
set_short("Maid Marian");
set_long(
	"  This beautiful young lady with the long flowing auburn tresses\n"+
	"is the love of Robin's life.  She is also the object of the\n"+
	"Sheriff's unwanted affections.  Her creamy complexion and sweet\n"+
	"dispostion make her the envy of nearly every woman in the King's\n"+
	"realm.\n");

  set_hp(400);
  set_level(16);
  set_al(800);
  set_wc(20);
  set_ac(12);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("Marian asks: Have you seen Robin?\n");
  load_chat("Marian smiles ever so sweetly...\n");
set_a_chat_chance(15);
  load_a_chat("Marian screams: R O B I N !!!!\n");
  load_a_chat("Marian bites you......\n");

gold = clone_object("obj/money");
gold->set_money(890);
move_object(gold,this_object());
}
