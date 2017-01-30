#include <ansi.h>
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = RED + "Forbidden Region" + NORM;
    long_desc ="\
    You are standing on a floor of branches and leaves formed by \n\
the trees bellow. All around you are still more trees that seem to \n\
be growing out of the tops of the trees you are standing on. \n\
    The region is surrounded with trees of four distinct types ,\n\
though here in this region they are mixed and mingled among each \n\
other. There are bluewood, redwood, yellowwood and clearwood trees \n\
all sharing this part of the fen. Flashes of light result from \n\
the branches crossing in the slight breeze.\n";
   
    items = ({
         "plate",
         "There are four metal plates. One is mounted on each type of tree",
         "tree",
         "There are four types of trees here. Some are blue, some red, some \n\
yellow and some are strangely clear. There are metal plates \n\
mounted on the 4 nearest trees",
         "redwood tree",
         "A red plate is embedded into it. Maybe you could 'read' it",
         "yellowwood tree",
         "A yellow plate is embedded into it. Maybe you could 'read' it",
         "clearwood tree",
         "A clear plate is embedded into it. Maybe you could 'read' it",
         "bluewood tree",
         "A blue plate is embedded into it. Maybe you could 'read' it. There \n\
are also large boards secured to the tree forming a crude, but \n\
effective ladder 'down'",
         "trees",
         "Odd colored trees, some red, some blue, some yellow and some are \n\
strangely clear. Perhaps you should look at each type of tree",
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
    string color;
    if(!str) {
        notify_fail("What do you want to read?\n");
        return 0;
    }
    if(str == "plate" || sscanf(str,"%s plate",color) != 1) {
        notify_fail("Which plate are you trying to read?\n");
        return 0;
    }
    write("The plate reads:\n");
    switch(color) {
        case "red":    write("\tNorth ---> Region of Fire\n"); break;
        case "clear":  write("\tSouth ---> Region of Air\n"); break;
        case "blue":   write("\tEast  ---> Region of Water\n"); break;
        case "yellow": write("\tWest  ---> Region of Earth\n"); break;
        default:     write("Each of the plates points in a different direction.\n");
    }
    return 1;
}

down(str){
write("You  C L I M B  down the tree.\n");
   say(tpn + "  C L I M B S  down the tree and disappears.\n");
tp->move_player("down#/players/brittany/xanth/vgar.c");
return 1; }
