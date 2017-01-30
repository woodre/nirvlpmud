#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Fire Region"+NORM;
   long_desc =
   "     A ring of fire rages along the border of this region.  The\n"+
   "land beyond it is burned and full of ashes.  On one side\n"+
   "an eternal forest fire rages.  On the other side, a lake of fire\n"+
   "occasionally belches up mushroom clouds of flame.  A huge\n"+
   "blackened heart-shaped ball is suspended in mid-air.\n";
   
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
         "/players/brittany/xanth/fen.c","south",
         "/players/brittany/xanth/infenter.c","in",
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
