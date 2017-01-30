#include "defs.h"

inherit "/players/feldegast/std/generic_shop.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("balin")) 
    move_object(clone_object(MON_PATH+"sakadib.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc="Sakadi's Fine Goods";
  long_desc=
"  A plush red carpet covers the floor of this tastefully decorated\n"+
"shop.  The goods are kept in teak display cases with glass covers.\n"+
"A display window looks out on Merchant Plaza and a counter is in the\n"+
"back of the store.\n"+
"Commands: list, buy, sell, value\n";
  items=({
    "window","You see merchants haggling over goods outside",
  });
  dest_dir=({
    PATH+"smerch.c","out",
  });
  move_object(clone_object(OBJ_PATH+"vase.c"),storage);
  move_object(clone_object(OBJ_PATH+"watch.c"),storage);
  move_object(clone_object(OBJ_PATH+"statue.c"),storage);
  move_object(clone_object(OBJ_PATH+"lamp.c"),storage);
  move_object(clone_object(OBJ_PATH+"8-ball.c"),storage);
  move_object(clone_object(OBJ_PATH+"sheath.c"),storage);
  move_object(clone_object(OBJ_PATH+"sextant.c"),storage);
  move_object(clone_object(OBJ_PATH+"bottle.c"),storage);
}