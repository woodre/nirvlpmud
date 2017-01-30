#include "/players/catacomb/misc/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("pikon");
set_race("durkor");
set_short("Pikon, the blacksmith");
set_long(
  "  A man that has been hardened by his many hours crafting\n"+
  "with his hammer and anvil.  He now sells his wares in this\n"+
  "shop.  Type '"+WHT+"list"+NORM+"' and he will give you a list of all of the\n"+
  "items you can '"+WHT+"buy"+NORM+"' from him.\n");
 
set_level(17);
set_hp(350);
set_al(0);
set_dead_ob(this_object());
set_aggressive(0);
add_money(100);
set_wc(24);
set_ac(14);

}
  