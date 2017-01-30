#include "../defs.h"

inherit "/players/feldegast/std/shop.c";


void reset(int arg)
{
  if(!present("layton"))
    move_object(clone_object(NPCDIR+"layton.c"),this_object());
  ::reset(arg);
  if(arg) return;
  set_light(1);
  set_short(MAG+"Sorcerous Shop"+NORM);
  set_long(
"  This is a dimly lit shop that smells prominently of incense and\n\
other less fragrant spell ingredients.  Neatly painted shelves and\n\
cabinets containing the paraphernalia of sorcery cover the walls.\n\
A counter is near the back of the shop.\n"
  );
  set_dest_dir( ({
    ROOMPATH+"tower1.c","west"
  }) );
  add_item("majin potion","/players/feldegast/heals/majin.c",1500,20,1);
  add_item("potion of full healing","/players/feldegast/heals/fullheal.c",10000,10,1);
  add_item("mysterious potion","/players/wocket/turtleville/OBJ/heal_potion.c",17000,7,1);
  add_item("regeneration potion","/players/wocket/turtleville/OBJ/regen_potion.c",30000,5,1);
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
  if(!present("layton")) return 0;
  if(!arg){
    notify_fail("Layton says: What can I get for you?\n");
    return 0;
  }
  x=invalid_purchase(arg);
  switch(x)
  {
    case 1: write("Layton says: We do not have that item.\n");
            return 1;
            break;
    case 2: write("Layton says: I'm afraid that would cost more money than you possess.\n");
            return 1;
            break;
    case 3: write("Layton says: I'm afraid we're out of that.\n");
            return 1;
            break;
    case 4: write("Layton says: You appear to be a little overburned at the moment.\n");
            return 1;
            break;
  }

  write("You purchase "+(::purchase(arg))+".\n");
  say((string)this_player()->query_name()+" makes a purchase.\n");
  return 1;
}
