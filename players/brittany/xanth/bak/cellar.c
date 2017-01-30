#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int GATES;
int close;
int open;
reset(arg) {
   open = 0;
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"A Room"+NORM;
   long_desc =
   "     A room on the second floor of the main complex.  A large bed\n"+
   "is in the corner of the room, with a woodburning fireplace in the\n"+
   "middle of the wall.  A heavy wooden table near a wide window over-\n"+
   "looking the courtyard.\n";
   
   items = ({
         "bed","A large bed",
         "fireplace","A woodburning fireplace",
         "fireplace","A small crack on the wall, maybe you could 'reach' inside",
         "wall","The wall has a fireplace in the middle of it",
         "table","A heavy wooden table",
         "window","An open window with wood trim around it's frame",
          });

   dest_dir = ({
              });
}

init() {
   add_action("in","in");
   add_action("open","open");
}
in(str) {
   if(!open) {
      write("The gates block your way.\n");
      return 1;
   }
   this_player()->move_player("in#/players/brittany/kadath/kadath2.c");
   return 1;
}
open(str) {
   if(!str) {
      write("Open what?\n");
      return 1;
   }
   if(str == "gates" && !open) {
      write("The gates squeak as you open them.\n");
      GATES = 0;
      open = 1;
      return 1;
   }
   if(str == "gates" && open) {
      write("The gates are already open.\n");
      return 1;
   }
}
