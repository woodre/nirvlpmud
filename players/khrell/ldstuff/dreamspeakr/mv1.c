#include "/players/dreamspeakr/closed/ansi.h"
#define PATH "/players/dreamspeakr/mesa/"

inherit "room/room";

reset(arg) {
  if(!present("totem", this_object())){
     move_object(clone_object("/players/dreamspeakr/CASTLE/OBJ/totem2.c"), this_object());
  }
  if(arg) return;
     set_light(1);

     short_desc = HIG+"Mancos Canyon"+NORM;
     long_desc =
         "\n"+
         "\tThis is the great majestic Mancos Canyon, well \n"+
         "known territory to the Anasazi indian tribes.  Pinon pine \n"+
         "trees and Juniper bushes grow in abundance alongside the \n"+
         "Mancos River that flows beside this well traveled canyon \n"+
         "bottom. \n"+
         "\n"
;

     items = ({
         "bushes","Hard wood bushes filled with colorful berries",
         "berries","Beautiful blue-green Juniper berries look quite \n"+
            "appetizing.  Myth says that they even have medicinal values",
         "river","Crystal clear waters that wind their way down through \n"+
            "the canyon.  Occasionally you see a large fish jump out to \n"+
            "catch a bug from atop the water", 
         "trees","Tall pine trees filled with hanging nuts provide cool \n"+
            "shade on the canyon bottom.  One of the larger trees appear\n"+
            "to have been used to sharpen the claws of some wild beast",
            "bottom","A rocky sandstone bottom winds alongside the riverbank",
});

dest_dir = ({
     PATH+"mv2.c","north",
});
}

init() {
  ::init();
  add_action("listen","listen");
}

listen() {
  write("You close your eyes and listen.... you hear the babbling\n"+
        "river and the whisper of the wind through the pines.  Off\n"+
        "in the distance you can hear the slight sounds of a song-\n"+
        "bird singing.\n");
  return 1; 
}
