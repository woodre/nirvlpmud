#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("geomancer")){
move_object(clone_object(ROOT+"mon/geomancer.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= "Storm Mountain ("+YEL+"Geomancer Guild Hall"+NORM+")";
    long_desc=
"A large and neatly organized room, set within the stone of the cave\n"+
"itself. Stone shelves and bookcases have been carved into the walls, as\n"+
"have a variety of tables and chairs set onto the floor. A strange\n"+
"fungus grows on the walls, shedding light through the cavern.\n";
                                                                      
    items=({
"room","The room is carved from the cave itself",
"stone","The stone here is the same dark grey color as most of the lands\n"+
     "surrounding Qual'tor",
"cave","The cave has been shaped and changed my earth magic. Shelves are \n"+
     "formed in the walls and large blocks of stone make tables",
"walls","The walls are dark grey stone",
"fungus","The strange fungus originates from Gundar, and has been brought\n"+
     "here to shed light throughout the room",
"light","The little bit of light in the chamber is from the strange fungus",
"chairs","The chairs are large chunks of stone rising from the floor",
"tables","The tables are large chunks of stone rising from the floor",
"shelves","The shelves are built from the stone of the walls",
"bookcases","The bookcases are built from the stone of the walls",
    });

    dest_dir=({
      "/players/daranath/clearing/marea6.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("The shelves and bookcases have long been looted by vandals and thieves.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

