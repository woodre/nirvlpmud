#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

status
RangerPower(string item_name, string type)
{
  object item;
  object *items;
  int i;
  int count;

  if(!item_name)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must specify an item.\"\n");
    return 1;
  }

  if(!previous_object()->QMorphed())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You can only access your pack when you\
are morphed.\"\n");
    return 1;
  }

  items = (mixed *) "/players/guilds/Rangers/Commands/Pack.c"->ListItem(
    (string) this_player()->query_real_name());
  if(items == 0)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You do not have any items in your pack.\"\n");
    return 1;
  }

  for(i=0; i<sizeof(items); i++)
  {
    if(items[i])
    {
      if(items[i]->id(item_name))
      {
        item = items[i];
        count += 1;
        if(MASTER->QPowerPoints(type) < item->query_weight())
        {
          tell_object(this_player(),
            "Zordon tells you: \"There is not enough power to store that \
item.\"\n");
          return 1;
        }

        move_object(item,environment(previous_object()));
        MASTER->APowerPoints( - ( (int)item->query_weight()), type);
        write("You teleport " + item_name +
          " from your Power Pack to your inventory.\n");
        "/players/guilds/Rangers/Commands/Pack.c"->RemoveItem(
          this_player()->query_real_name(),item);
        return 1;
      }
    }
    else
    {
      "/players/guilds/Rangers/Commands/Pack.c"->RemoveItem(
        this_player()->query_real_name(),item);
      item = 0;
    }
  }
  if(!(item))
  {
    tell_object(this_player(),
      "Zordon tells you: \"You do not have " + item_name +
      " in your pack.\"\n");
    return 1;
  }
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("Your pack is a virtual storage area. You may use it to store\n\
items you do not wish to carry.\n Each transaction will cost some\n\
Power Points.  The heavier the item, the more power it will consume.\n\
You must be morphed to use the pack. The items remain in the pack\n\
even if you log off the mud. Items will NOT carry over a reboot cycle.\n\
Commands:\n\nunpack <item>             moves specified item from the pack to you\n");
  return 1;

}
