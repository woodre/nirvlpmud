/*
Potion of Giantkind
File: tallpotion.c
Date: 3/24/02
Author: Feldegast
Description:
  Increases height.
*/
#include "/players/feldegast/defines.h"


inherit "/obj/treasure.c";

void reset(int arg)
{
  if(arg) return;
  set_id("potion");
  set_alias("potion of giantkind");
  set_short("Potion of Giantkind");
  set_long(
    "This is a blue bottle filled with a thick, sticky substance.  A\n"+
    "picture on the side of the bottle depicts a tall looking stick\n"+
    "figure.\n"
  );
  set_weight(1);
  set_value(1000);
}

void init()
{
  add_action("cmd_drink", "drink");
  add_action("cmd_drink", "quaff");
  add_action("cmd_drink", "sip");
}

int cmd_drink(string str)
{
  object me;
  int feet, inches;

  me = present(str, this_player());

  if(!str || this_object() != me)
  {
    notify_fail(capitalize(query_verb())+" what?\n");
    return 0;
  }
  feet   = (int)this_player()->query_phys_at(1);
  inches = (int)this_player()->query_phys_at(2);

  if(feet == 7 && inches == 11)
  {
    write("Nothing happens.\n");
  }
  else
  {
    if(inches == 11)
    {
      TP->add_phys_at(1, 1);
      TP->add_phys_at(2, -11);
    }
    else
    {
      TP->add_phys_at(2, 1);
    }
    TP->add_phys_at(3, 1+random(5));
    write("You grow in height!\n");
    say(TPN+" drinks a potion and grows!\n");
  }
  destruct(this_object());
  TP->add_weight(-1);
  return 1;
}
