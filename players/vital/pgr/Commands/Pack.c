#pragma strict_types
#include <ansi.h>
#include "../RangerDefs.h"

mapping Items;

string *ListItem(string player_name);
void RemoveItem(string player_name, object item);
void AddItem(string player_name, object item);

status
RangerPower(string item_name, string type)
{
  object item;
  if(!item_name)
  {
    tell_object(this_player(),
      "Zordon tells you: \"You must specify an item.\"\n");
    return 1;
  }
  if(previous_object()->QNinja())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You are cannot use the pack as a Ninja.\"\n");
    return 1;
  }
  if(!previous_object()->QMorphed())
  {
    tell_object(this_player(),
      "Zordon tells you: \"You cannot use your pack unless Morphed.\"\n");
    return 1;
  }
  if(!present(item_name,environment(previous_object())))
  {
    tell_object(this_player(),
      "Zordon tells you: \"You do not have " + item_name +
      " in your inventory.\"\n");
    return 1;
  }
  item = present(item_name, environment(previous_object()));
  if( !(item->get()) ||
      item->drop() > 0 ||
      item->query_weight() > 10 ||
      living(item) )
  {
    tell_object(this_player(),
      "Zordon tells you: \"You can't use that item with the pack.\"\n");
    return 1;
  }
  if(MASTER->QPowerPoints(type) < item->query_weight())
  {
    tell_object(this_player(),
      "Zordon tells you: \"There is not enough power to store that item.\"\n");
    return 1;
  }
  move_object(item,this_object());
  MASTER->APowerPoints( -( (int) item->query_weight()), type);
  tell_object(this_player(),
    "Zordon tells you: \"You teleport " + item_name +
    " to your Power Pack.\"\n");
  this_object()->AddItem(this_player()->query_real_name(),item);
  return 1;
}

status
QRangerInfo() { return 1; }

status
RangerInfo()
{
  write("Your pack is a virtual storage area.\n\
You may use it to store items you do not wish to carry.\n\
Each transaction will cost some Power Points.  The heavier\n\
the item, the more power it will consume.\n\
You must be morphed to use the pack.\n\
The items remain in the pack even if you log off the mud.\n\
Items will NOT carry over a reboot cycle.\n\
Commands:\n\n\
pack <item>             moves specified item to the pack\n\
ri pack                 see pack contents.\n");
  return 1;
}

void
AddItem(string player_name, object item)
{
  object *items;
  if(Items == 0) Items = ([ ]);
  if(!(items = Items[player_name]))
    Items[player_name] = ({ item });
  else
    Items[player_name] += ({ item });
}

void
RemoveItem(string player_name, object item)
{
  object *items;
  if(Items == 0) Items = ([ ]);
  if(!(items = Items[player_name]))
  {

  }
  else
    Items[player_name] -= ({ item });
}

string *
ListItem(string player_name)
{
  object *items;
  if(Items == 0) Items = ([ ]);
  if(!(items = Items[player_name]))
    return 0;
  else 
    return Items[player_name];
}
