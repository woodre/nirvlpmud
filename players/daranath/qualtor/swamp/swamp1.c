#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Qual'tor Swamp";
    long_desc=
     "You stand at the northern edge of the swamp just outside the walls\n"+
     "of Qual'tor. The swamp itself lies south from here, while just to\n"+
     "the west a roadway can be seen running about the exterior of the\n"+
     "city.\n";

    items=({
     "roadway","The road itself is little travelled....",
     "swamp","The swamp is full of many dangers for rookie adventurors",
     "city","Qual'tor was a ruined city that is on its way back",
    });

    dest_dir=({
     "/players/daranath/qualtor/swamp/swamp2.c","south",
     "/players/daranath/qualtor/swamp/outer_trail1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("The swamp makes you a little too nervous to search thoroughly.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

