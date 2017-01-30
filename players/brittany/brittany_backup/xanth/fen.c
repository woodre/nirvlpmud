#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = RED+"Forbidden Region"+NORM;
   long_desc =
     "     The region is surrounded with bluewood and redwood trees.  The.\n"+
   "trees are twisted into the shape of pretzels.  There is a huge\n"+
   "boulder at the end of the path and a plate is embedded into it.\n";
   
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
         "/players/brittany/xanth/air.c","south",
         "/players/brittany/xanth/water.c","east",
         "/players/brittany/xanth/earth.c","west",
              });
}

init() {
   ::init();
   add_action("read","read");
   add_action("search","search");
   add_action("down","down");
  }

search(){
  notify_fail("You find nothing of interest.\n");
  return 0;
}

read(str) {
    if(!str || str != "plate") {
        notify_fail("What do you want to read?\n");
        return 0; }
 
    write(
   "The plate reads:\n\n"+
   "North ---> Region of Fire\n"+
   "South ---> Region of Air\n"+
   "East  ---> Region of Water\n"+
   "West  ---> Region of Earth\n");
     return 1;
}

down(str){
write("You  C L I M B  down the tree.\n");
   say(tpn+"  C L I M B S  down the tree and disappears.\n");
tp->move_player("down#/players/brittany/xanth/vgar.c");
return 1; }
