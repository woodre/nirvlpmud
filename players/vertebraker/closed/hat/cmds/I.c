/* code "borrowed" from open dir */

#include "../std.h"

main(str)
{
   object x; int z; object *inv;
   if(!str || !(x = find_living(str)) )
      {
      write("Not logged on!\n");
      return 1;
   }
   write("You peek into "+CAP(str)+"'s inventory...\n");
   full_inventory(x,"");
   return 1;
}

full_inventory(object ob, string indent) {  
   object *inv;
   int size,x;
   string sh;
   if(!indent) indent="";
   inv = all_inventory(ob);
   size = sizeof(inv);
   sh = (string)ob->short();
   write(indent + (sh ? sh: "INVIS")+"  <"+file_name(ob)+">\n");
   if(!size) return;
   else
      for(x = 0; x < size; x ++)
   full_inventory(inv[x], indent+"    ");
   return;
}
