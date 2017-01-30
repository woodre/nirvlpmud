#include "defs.h"

inherit "/players/feldegast/std/shop.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("valatia"))
    move_object(clone_object(MON_PATH+"valatia.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=HIM+"Magic Shop"+NORM;
  long_desc=
    "  This is a dusty shop with herbs, potions, scrolls, and rare and exotic\n"+
    "artifacts carefully placed on mahogany shelves.  An oriental carpet with\n"+
    "gold thread sewn into it covers the floor.  In the back of the shop is\n"+
    "a mahogany counter.\n"+
    "Commands: list, buy\n";
  items=({
  });
  dest_dir=({
    PATH+"sroy.c","out",
  });
  add_item("Glowing orb",OBJ_PATH+"gorb.c",1200,2+random(5),1);
  add_item("Whore's Weed",OBJ_PATH+"abortion.c",2000,1+random(5),1);
  add_item("Hemlock",OBJ_PATH+"hemlock.c",5000,2+random(3),1);
  add_item("Ancient scroll", OBJ_PATH+"scroll-witch.c", 250, 1, 0);
/*
  add_item("Teleportation Scroll",OBJ_PATH+"scroll-escape.c",2500,random(5),1);
*/
  add_item("Carrier pigeon",OBJ_PATH+"pigeon.c",800,random(6),1);
}
void init()
{
  ::init();
  add_action("buy","buy");
  add_action("buy","purchase");
  add_action("list","list");
}

int buy(string arg)
{
  int x;
  if(!present("sorceress")) return 0;
  if(!arg) return 0;
  x=invalid_purchase(arg);
  switch(x)
  {
    case 1: write("Valatia says: We do not have that item.\n");
            return 1;
            break;
    case 2: write("Valatia says: That would cost more money than you possess.\n");
            return 1;
            break;
    case 3: write("Valatia says: I am out of that.\n");
            return 1;
            break;
    case 4: write("Valatia says: You appear to be a little overburned at the moment.\n");
            return 1;
            break;
  }

  write("You purchase "+(::purchase(arg))+".\n");
  say((string)this_player()->query_name()+" makes a purchase.\n");
  return 1;
}
