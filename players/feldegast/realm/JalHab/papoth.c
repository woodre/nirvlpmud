#include "defs.h"

inherit "/players/feldegast/std/shop.c";

void reset(int arg) {
  ::reset(arg);
  if(!present("p'salin"))
    move_object(clone_object(MON_PATH+"psalin.c"),this_object());
  if(arg) return;
  set_light(1);
  short_desc=HIY+"The Apothecary"+NORM;
  long_desc=
"  As you enter this shop, your nose is assailed by the herbs and\n\
potions that line its shelves.  The rear portion of the shop is a\n\
workshop with several workbenches covered with bottles, retorts, a\n\
mortar and pestle, and a small woodstove.\n";
  items=({
    "herbs","The herbs are placed in wooden buckets with labels on\n"+
            "each of the buckets that you can read",
    "potions","The potions are placed in neat little bottles and vials\n"+
              "for easy consumption.  There are labels next to each set\n"+
              "of vials that you can read",
    "workbenches","The benches are made out of stone, wood being too scarce\n"+
                  "to use in such commonplace furniture",
    "bottles","Quite possibly the rarest and most fascinating objects in\n"+
              "this shop.  These magical devices can be used to contain\n"+
              "small objects, and yet their surface is translucent so that\n"+
              "you can actually see INSIDE of them",
    "retorts","A complicated alchemical apparatus",
    "mortar","A stone bowl used for grinding herbs and powders",
    "pestle","An implement used to grind herbs",
    "woodstove","The fire in the stove is out right now",
  });
  dest_dir=({
    PATH+"pwell.c","north",
  });
  add_item("majin potion",HEAL_PATH+"majin.c",1500,20,1);
  add_item("vita potion",HEAL_PATH+"vita.c",1500,20,1);
  add_item("valdit berries",HEAL_PATH+"valdit_berries.c",4500,20,1);
  add_item("tubor root",HEAL_PATH+"root.c",2800,15,2);
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
  if(!present("p'salin")) return 0;
  if(!arg) return 0;
  x=invalid_purchase(arg);
  switch(x)
  {
    case 1: write("P'salin says: We do not have that item.\n");
            return 1;
            break;
    case 2: write("P'salin says: I'm afraid that would cost more money than you possess.\n");
            return 1;
            break;
    case 3: write("P'salin says: I'm afraid we're out of that.\n");
            return 1;
            break;
    case 4: write("P'salin says: You appear to be a little overburned at the moment.\n");
            return 1;
            break;
  }

  write("You purchase "+(::purchase(arg))+".\n");
  say((string)this_player()->query_name()+" makes a purchase.\n");
  return 1;
}
