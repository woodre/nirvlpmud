#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
  object name_of_item;
  object next;
  object ob;
  int    wea;
  
  name_of_item = first_inventory(User);
  
  while (name_of_item)
  {
    next = next_inventory(name_of_item);
    
    if(!living(name_of_item))
    {
      if(str = (string)name_of_item->short())
      {
        if(name_of_item->weapon_class() || name_of_item->armor_class() || name_of_item->is_armor())
        {
          write (str+ "...\n");
          ob = (object)name_of_item->query_name();
          name_of_item->wield(ob);
          if(name_of_item->armor_class() || name_of_item->is_armor())
              command("wear "+ob, User);
          else if (name_of_item->weapon_class() || name_of_item->is_weapon() || !name_of_item->query_wielded())
          	  command("offwield "+ob, User);
        }
      }
    }
    name_of_item = next;
  }
  
  command("save", User);
  return 1;
}
