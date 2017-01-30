#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
     short_desc= "Arena Registration";
    long_desc=
     "The basic entrance into any arena\n";

    items=({
    });

    dest_dir=({
      "/players/daranath/qualtor/arena/entry.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Do you really want to search here?\n"+
          "You are being watched by the arena crew.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

