#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Necromancer Donation";
    long_desc=
   "A small chamber white the same white marble walls as the rest of the\n"+
   "Necromancer Stronghold, this room is primarily used as a donation\n"+
   "area. Necromancers can leave unused or extra equipment for thier\n"+
   "brothers and sisters.\n";

    items=({
     "room","The room has the same white marble walls as the guild",
     "walls","The white marble is covered with blood stains",
     "wall","The white marble is covered with blood stains",
     "marble","Expensive white marble makes up the guild hall",
    });

    dest_dir=({
      "/players/daranath/guild/room/necro4.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Bits of bone and areas of dried blood are all about the room.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

