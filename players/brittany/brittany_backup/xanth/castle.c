#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int tapestry;
reset(arg) {
   if(arg) return;
   set_light(1);
   
   short_desc = BLU+"Castle Roogna"+NORM;
   long_desc =
   "     Inside the main entrance, along the long corridor a huge tapestry\n"+
   "hangs on the wall.  Something about the pictures on the tapestry draws\n"+
   "your attention.  At the end of the corridor a doorway leads to another\n"+
   "room.\n";
   
   items = ({
         "tapestry","The tapestry plays over a sequence several hundred years in the past",
         "pictures","The pictures are dull, maybe you should try to 'clean' the tapestry",
         "stairs","The stairs off of the kitchen leads down to the cellar",
         "corridor","A long corridor inside at the main entrance of the castle",
         "shadows","The dark images casted throughout the castle",
         "ghosts","The dead souls that roam the castle in search of their spirit",
         "cellar","It is too dark to see the cellar from here",
          });

   dest_dir = ({
              });
}

init() {
   add_action("clean_tapestry","clean");
   add_action("open","open");
}
clean_tapestry(str) {
   if(!str || str != "tapestry") {
   write("What do you want to clean?\n");
   return 1;}

     if(tapestry){
    write("You try to clean the tapestry and it still looks dull.\n");
          return 1;
}
}
