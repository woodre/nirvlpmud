#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Field of Triumph";
    long_desc=
     "The basic entrance into any arena\n";

    items=({
    });

    dest_dir=({
      "/players/daranath/qualtor/arena/entry.c","north",
      "/players/daranath/qualtor/arena/five.c","south",
      "/players/daranath/qualtor/arena/three.c","east",
      "/players/daranath/qualtor/arena/two.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of the Arena brings nothing of interest.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


