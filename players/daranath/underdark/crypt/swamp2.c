#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Underground marsh";
    long_desc=
  "The tunnel continues here, leveling off and bending torwards the east.\n"+
  "Sliding down the rocky pathway, the stream gathers strength and follows\n"+
  "the tunnel eastwards. A step down causes the stream to collect itself,\n"+
  "forming the small underground marsh that lies to the east from here.\n";

    items=({
    "tunnel", "The tunnel is naturally formed from the rock",
    "stream", "The small stream runs down the same trail as the path,\n"+
               "gaining strength as it flows",
    "water", "The water of the stream is fresh and cool",
    "light", "A small amount of light filters through the hole in the\n"+
             "wall from the stairwell area",
    "path", "The rocky path travels down from here",
    "marsh", "The marsh lies to the east from here",
     });

    dest_dir=({
      "/players/daranath/underdark/crypt/swamp1.c","up",
      "/players/daranath/underdark/crypt/swamp3.c","east",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You cannot find anything about the area with the water covering.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

arate() { return "YES"; }


