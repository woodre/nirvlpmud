#include "../scar.h"

main(str) {
   object scar;

  if(this_player()->is_player() && this_player()->query_level() < 30 ) {
     return 0;
   }
   write_file(LOGFILE, ctime()+" " +capitalize(environment(previous_object())->query_name()) +
      " did new_scar. Reason: "+str+".\n");
   write("Resetting scar...\n");
   destruct(previous_object());
   scar = clone_object(SCAROBJ);
   move_object(scar, this_player());
   return 1;
}
