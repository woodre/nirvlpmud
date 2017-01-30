#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object mask, gold;
  ::reset(arg);
  if(arg) return;

set_name("phantom");
set_alias("the phantom");
set_race("human");
set_short("Phantom of the Opera");
set_long(
	"  This mutilated musician wears a mask and lives beneath the\n"+
	"the opera house.  Because his face has never been seen, they \n"+
	"call him 'the Phantom'.  Lon Chaney played the part of Eric\n"+
	"Claudin in this 1925 silent movie, The Phantom of the Opera.\n");

set_level(20);
  set_hp(500);
  set_al(0);
  mask = clone_object("players/eurale/Fiend/OBJ/mask.c");
  move_object(mask,this_object());
  init_command("wear mask");
  set_wc(28);
  set_ac(18);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("The Phantom adjusts his mask....\n");
  load_chat("Eyes peer at you through the mask...\n");
set_a_chat_chance(15);
  load_a_chat("The phantom dodges your attack...\n");
  load_a_chat("The phantom ducks.....\n");

gold = clone_object("obj/money");
gold->set_money(3900);
move_object(gold,this_object());
}
