#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = "Dark Caverns";
   long_desc =
   "  A dark and musky cavern with a strange mist swarming\n"+
   "throughout the tunnel.  The tunnel leads back to the west\n"+
   "and continues east into blackness.\n";
   items = ({
         "items","put items here",
});
   
   dest_dir = ({
       "/players/jaraxle/templar/quests/unicorn/rooms/cave4.c","south",
       "/players/jaraxle/templar/quests/unicorn/rooms/cave6.c","north",
});
   
}

realm() { return "NT"; }

init(){
   ::init();
   
   add_action("lock_it","ele");
   add_action("lock_it","word");
   add_action("lock_it","sphere");
   add_action("lock_it","orb");
}
lock_it(arg) {
   write(HIY+"\tYour spell dissipates with no effect"+NORM+"\n");
   return 1; }
