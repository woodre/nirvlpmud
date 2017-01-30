#include "../DEFS.h"

status main(string str) {
   /* ability to speak own guild language */
   object ob;
   if(!str) { write("What do you speak in techie talk?\n"); return 1; }
   ob = first_inventory(environment(TP));
   while(ob) {
      if( (IPOB && ob != TP) ||
           (string)ob->query_real_name() == "_hide_in_shadows_vehicle_")
          tell_object(ob, TPN+" speaks in Techie: "+str+"\n");
      else if(ob != TP) 
          tell_object(ob, "You hear quiet voices in the room.\n");
      ob = next_inventory(ob);
   }
   write("You techie: "+str+"\n");
   return 1;
}
