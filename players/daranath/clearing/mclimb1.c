#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Mountain Climb";
    long_desc=
      "The rocky climb up the face of the mountain begins here, spanning\n"+
      "as far as you can see upwards into the depths of the peak. Light\n"+
      "flashes every once in a while from the dark clouds overhead. The\n"+
      "path continues up into the mountains and down to the crossroads\n"+
      "below.\n";

    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "path", "The mountain path extends up and down the mountain's face",
      "crossroads", "The path meets a rocky trail below at the crossing\n"+
                    "below your position",
      "mountain", "The dark mountain rises up above you, beckoning..",
    });

    dest_dir=({
      "/players/daranath/clearing/mclimb2.c","up",
      "/players/daranath/clearing/mcross.c","down",
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


