#include "/players/fred/closed/bloodfist/defs.h"

status main(string str, object PO, object User)
{ 
  string ob;
  object item, next;
  item = first_inventory(User);
  while(item)
  {
    next = next_inventory(item);
    if(!living(item))
    {
      if(item->short())
      {
        write(item->short()+ "...\n");
        ob = (string)item->query_name();
        /* item->wield(ob); */
        if(item->armor_class() || item->is_armor())
          command("wear "+ob, User);
      }
        if(item->weapon_class() || item->is_weapon())
        {
          if(User->query_weapon())
            command("unwield", User);
        command("wield "+ob, User);
        }
     }  
     item = next;
   }
 return 1;
}
