#include "/players/vertebraker/define.h"
#define PATH "/players/vertebraker/castle/new/"

inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short("A dimly lit forest");
   set_long(
      "    A shady path wraps around the twisting forest here, leading to\n"+
      "a tall wooden signpost further to the west.  Light pierces through\n"+
      "the loose canopy of leaves above your head, momentarily blinding\n"+
      "you.  Twigs crack under your feet as you step.\n");
   set_light(1);
   add_item(
      "path","The path appears to wrap further to the west");
   add_item(
      "forest","Spruce and maple trees decorate the landscape around you,\n"+
      "reaching to the sky in their majesty");
   add_item(({"canopy","leaves"}),
      "A thin, loose amount of leaves acts as a canopy above your head,\n"+
      "acting as a kind of sunvisor");
   add_item("twigs","Twigs crack and pop under your feet as you walk");
   add_listen("main","A few birds chirp in the distance.");
   add_item("signpost","A signpost looms to the west");
   add_exit(PATH+"vortex","west");
   add_exit("/room/south/sforst24","east");
   if(!present("imp")) move_object(clone_object("/players/vertebraker/closed/shardak/obj/fun_imp"), this_object());
}
