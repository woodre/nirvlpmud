#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Hallway of Bone";
    long_desc=
   "A small hallway with the same marble walls, three exits lead from the\n"+
   "chamber, heading north, south and east. A doorway also leads west\n"+
   "but the area behind the doorway seems to have collapsed. Bits and\n"+
   "pieces of stone are strewn about the area, making you tread carefully\n"+
   "through here.\n";

    items=({
     "room","The room has the same white marble walls as the guild",
     "walls","The white marble is covered with blood stains",
     "wall","The white marble is covered with blood stains",
     "marble","Expensive white marble makes up the guild hall",
    });

    dest_dir=({
      "/players/daranath/guild/room/necro6.c","north",
      "/players/daranath/guild/room/necro7.c","south",
      "/players/daranath/guild/room/necro2.c","east",
      "/players/daranath/guild/room/necro8.c","west",
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

realm() {return "NT";}

