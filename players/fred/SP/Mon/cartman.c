#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object pie;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("cartman");
set_alias("eric");
set_race("human");
set_short("Eric Cartman");
set_long(
  "  Cartman is a little fat kid that almost always wears a blue hat\n"+
  "and a red shirt.  He is constantly harrassed about being overweight\n"+
  "but he will readily argue that he's not fat, just big boned.\n");

add_money(200);
set_level(8);
set_hp(120);
set_al(0);
set_wc(12);
set_ac(7);
set_aggressive(0);
set_chat_chance(5);
  load_chat("Cartman yells: No Kitty! That's my pot pie!\n");
set_a_chat_chance(10);
  load_a_chat("Cartman says: You will Respect my Authorita!\n");
  
	pie = clone_object("/players/fred/SP/Obj/ppie.c");
      move_object(pie, this_object());
}


