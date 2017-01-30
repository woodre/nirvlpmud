#include "/players/fred/ansi.h"
inherit "obj/monster.c";

object collar;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("mr. Kitty");
set_alias("kitty");
set_race("creature");
set_short("Mr. Kitty");
set_long(
  "  Mr. Kitty is Cartman's pet cat.  He is always hanging around to\n"+
  "see if Eric will actually share or drop some food.\n");
  
set_level(3);
set_hp(45);
set_al(0);
set_wc(7);
set_ac(4);
set_aggressive(0);
set_chat_chance(5);
  load_chat("Mr. Kitty goes Meow.\n");
  load_chat("Mr. Kitty looks up at Cartman.\n");

   collar = clone_object("/players/fred/SP/Obj/collar.c");
   move_object(collar, this_object());
}


