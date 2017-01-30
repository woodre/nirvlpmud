#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Mountain Climb";
    long_desc=
      "The wind tears at your hair and equipment as you traverse the\n"+
      "pathway here. Flashes of light streak about the area at a more\n"+
      "regular pace, the lightning from the clouds illuminating the\n"+
      "area all about.\n";

    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "path", "The mountain path extends up and down the mountain's face",
      "mountain", "The dark mountain rises up above you, beckoning..",
    });

    dest_dir=({
      "/players/daranath/clearing/mclimb3.c","up",
      "/players/daranath/clearing/mclimb1.c","down",
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


