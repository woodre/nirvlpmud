#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Hallway within the Crypt";
    long_desc=
  "A naturally formed tunnel slopes downward from your vantage point,\n"+
  "leading down a rocky pathway into the darkness. Soft light filters in\n"+
  "from the stairwell to the south, giving the area some illumination at\n"+
  "its upper end. A small stream of water breaks from a hole in the wall\n"+
  "and runs down the corridor down into the darkness.\n";

    items=({
    "tunnel", "The tunnel is naturally formed from the rock",
    "stream", "The small stream runs down the same trail as the path,\n"+
              "gaining strength as it flows",
    "water", "The water of the stream is fresh and cool",
    "light", "A small amount of light filters through the hole in the\n"+
             "wall from the stairwell area",
    "path", "The rocky path travels down from here",
    "pathway", "The rocky pathway travels down from here",
     });

    dest_dir=({
      "/players/daranath/underdark/crypt/swamp2.c","down",
      "/players/daranath/underdark/crypt/entry.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find small blind fish within the running water.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


arate() { return "YES"; }
