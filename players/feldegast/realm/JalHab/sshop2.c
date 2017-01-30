#include "defs.h"

inherit "/players/feldegast/std/shop.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("sakadi"))
    move_object(clone_object(MON_PATH+"sakadic.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=HIC+"Sakadi's Fine Equipment"+NORM;
  long_desc=
"  A plush blue carpet covers the floor of this tastefully decorated\n\
upper-class shop.  Various pieces of ornate and custom made armor are\n\
displayed in teak display cases with glass covers.  A display window\n\
next to the counter looks out onto the market square.\n\
Commands: list, buy\n";
  items=({
  });
  dest_dir=({
    PATH+"smark.c","out",
  });
  add_item("Steel shield",ARM_PATH+"shield.c",400,6+random(3),3);
  add_item("Steel gauntlets",ARM_PATH+"gauntlet2.c",1000,5+random(5),2);
  add_item("Silver shield",ARM_PATH+"silv_shield.c",1200,8,3);
  add_item("Plumed helmet",ARM_PATH+"helmet.c",200,4+random(6),1);
  add_item("Golden Helm",ARM_PATH+"ghelm.c",8000,2,4);
  add_item("Ring mail",ARM_PATH+"ringmail.c",1200,3+random(3),3);
  add_item("Golden Breastplate",ARM_PATH+"gplate.c",60000,1,8);
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
  if(!present("sakadi")) return 0;
  if(!arg) return 0;
  x=invalid_purchase(arg);
  switch(x)
  {
    case 1: write("Calis says: We do not have that item.\n");
            return 1;
            break;
    case 2: write("Calis says: I'm afraid that would cost more money than you possess.\n");
            return 1;
            break;
    case 3: write("Calis says: I'm afraid we're out of that.\n");
            return 1;
            break;
    case 4: write("Calis says: You appear to be a little overburned at the moment.\n");
            return 1;
            break;
  }

  write("You purchase "+(::purchase(arg))+".\n");
  say((string)this_player()->query_name()+" makes a purchase.\n");
  return 1;
}
