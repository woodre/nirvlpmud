inherit "room/room";
#include "room.h"
#include "/players/hippo/bs.h"

reset(arg) {
   if(arg) return;
   short_desc = "URINE";
   long_desc="WHoo, what an ugly tasting fluid is this, man!\n";
    dest_dir =
   ({
      "/rooms/jetty2.c","rise",
    }) ;
    set_light(1) ;
}

init()  {
	::init();
   add_action("rise","rise");
	}

rise() {
say(this_player()->query_name()+" arises from a pool of urine.\n");
move_object(this_player(),"/room/jetty2.c");
write("You just left this lady body with her urine. You smell awfull\n"+
   "now, and it'll take a while before you get your normal swetty\n"+
   "air around you again.\n");
command("look",this_player());
return 1;
}
