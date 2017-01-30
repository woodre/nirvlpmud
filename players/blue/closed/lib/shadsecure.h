#include "/players/blue/closed/lib/basic.h"
#define LOG "/players/blue/closed/shadow/logs/BAD_ENTER"

filter_room() {
   object ob, tmp;
   ob = first_inventory(TO);
   while(ob) {
      tmp = next_inventory(ob);
      if(ob->is_player()) {
      if(ob->query_real_name() == "bismark") {
         tell_object(ob, "You are not wanted here.\n");
         tell_object(ob, "Thank you for using the ACME room cleaner.\n");
         destruct(ob);
         set_heart_beat(0);
         set_heart_beat(1);
         write_file(LOG, "Bismark got dested.\n");
      }
      if(ob&&!present("shadow-mark",ob)) {
         tell_object(ob, "You do not belong here.\n");
         move_object(ob, "/room/church");
         command("look", ob);
      }
   }
      ob = tmp;
   }
   return 1;
}
