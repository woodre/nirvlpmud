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
   
   short_desc = BLU+"A gloomy cellar"+NORM;
   long_desc =
   "     The cellar is gloomy and a cool breeze fills the air.  In the\n"+
   "corner of the room, you notice an old mare's shoe on the floor.  On\n"+
   "the castle wall gourd runs alongside a small crevice.  The gourd grows \n"+
   "from inside the crevice and runs along the length of the wall.\n";
   
   items = ({
         "gourd","A dried vine growing on the castle wall",
         "crevice","A small crack on the wall, maybe you could 'reach' inside",
         "wall","The cellar wall has gourd growing from a small crevice",
         "cellar","The cellar is gloomy and cool breezes fill the air",
         "shoe","An old rusty piece of metal, bent in the shape of a U",
         "floor","An old mare's shoe is on the floor, in the corner",
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
