#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";
#define ATTACKED (this_object()->query_attack())
object fang;
object fang2;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("viper");
set_alt_name("snake");
set_race("serpent");
set_short("A medium-sized viper");
set_long(
  "  A serpent that is roughly 6 feet in length.  Although it is not\n"+
  "fully developed, the viper has lived for a number of years growing\n"+
  "stronger after each kill.\n");
 
set_level(16);
set_hp(300);
set_al(-200);
set_ac(13);
set_wc(22);
set_aggressive(1);
set_chat_chance(2);
  load_chat("The snake slithers around trying to surround its foe.\n");

fang = clone_object("/players/catacomb/MF/items/fang.c"); 
move_object(fang, this_object());

fang2 = clone_object("/players/catacomb/MF/items/fang.c"); 
move_object(fang2, this_object());
}

