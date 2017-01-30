#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= ("Storm Mountain (Peak)");
    long_desc=
      "The dark clouds cover the top of the mountain pathway with a\n"+
      "sinister shadow, the peak of the rocky climb clearly in view.\n"+
      "The only light source remains the continued lightning overhead,\n"+
      "flashing with brilliant blue and bright yellow hues.\n";

    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "path", "The mountain path extends up and down the mountain's face",
      "peak", "The peak of the mountain seems to level off into a large\n"+
              "area spreading to the north of your position",
      "mountain", "The dark mountain rises up above you, beckoning..",
    });

    dest_dir=({
      "/players/daranath/clearing/mpeak.c","north",
      "/players/daranath/clearing/mclimb2.c","down",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing along the mountain path.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


