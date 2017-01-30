#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"The Void"+NORM;
   long_desc =
   "     Beyond the border of Earth is an imperceptible swirl of\n"+
   "nothingness.  No landmarks can be seen from outside.  Inside, it\n"+
   "is a smooth gently sloping valley.  The Void is all an illusion,\n"+
   "the absence of all physical reality.  Footprints glow in the Void.\n";
   
   items = ({
         "boulder","A huge rock with an imprint of a hairy fist knocked into it",
         "plate","A metal plate with something wrote on it",
         "tree","A metal plate is embedded into the tree, maybe you could 'read' it",
         "redwood tree","A plate is embedded into it, maybe you could 'read' it",
         "bluewood tree","An oddly shaped tree, the wood is the color of blue, climb\n"+
         "'down' to exit",
         "trees","Odd shaped trees, some red and some blue",
          });

   dest_dir = ({
         "/players/brittany/xanth/fire.c","north",        
              });
}

init() {
   ::init();
   add_action("search","search");
  }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}
