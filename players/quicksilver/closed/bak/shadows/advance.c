#include "/players/blue/closed/lib/shadsecure.h"
inherit"/room/room.c";

reset(arg) {
 
   if(arg) return;

   set_heart_beat(1);
   set_light(1);
   short_desc = "A Shadow Room";
   long_desc = "It is so dark in here your eyes can barely make out anything."+
"\nThis is a small room, completely empty except for a strange black orb "+
"\nfloating against the far wall.\n";

   if(!present("new_mark", this_object())) 
      move_object(clone_object("/players/blue/closed/shadow/new_mark.c"),
         this_object());
   dest_dir = ({
      "/players/blue/closed/shadow/rooms/meeting.c","east"
   });
   

   if(!present("orb", this_object())) {
   move_object(clone_object("/players/blue/closed/shadow/obj/black_orb"),
             this_object());
   }
}

heart_beat() {
   filter_room();
}
