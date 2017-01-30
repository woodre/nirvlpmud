#include "../def.h"

int s;

cmd_ready(string str)
{
   object ob, oc;
   object offwep, shadow, firstshad;
   if(s)
      return 0;
   s=1;
   command(query_verb(), this_player());
   s=0;
   if(!this_player()->query_weapon()) return 1;
   ob=first_inventory(this_player());
   while(ob)
   {
      oc = next_inventory(ob);
      if(ob->short() && ob->weapon_class() && !ob->query_wielded())
         {
         oc=next_inventory(ob);
         write("Offwield: "+ob->short()+"... ");
         if(!ob->two_handed() && !(this_player()->query_weapon()->two_handed()) && (ob->offwield_function() != 2))
            {
               "/players/snow/dervish/master"->offwield(ob->query_name());
         }
         }
      ob=oc;
   }
   return 1;
}
