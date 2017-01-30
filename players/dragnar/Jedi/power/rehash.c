#include "../defs.h"

main() {
   int i;
   object *ob;
   object gobj;

   ACTIONS->rehash();
   ob=users();
   for(i=0; i < sizeof(ob); ++i) {
      gobj = present("jedi_object",ob[i]);
      if(gobj){
         if (ob[i] && environment(ob[i])) {
            move_object(gobj, environment(gobj));
         }
      }
   }
   write("OK, actions rehashed.\n");
   return 1;
}
