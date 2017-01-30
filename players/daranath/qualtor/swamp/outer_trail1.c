#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Outside the Walls of Qual'tor";
    long_desc=
     "A small roadway leads from the southern gate of Qual'tor to the\n"+
     "edge of the swamp and along the outside of the eastern wall.\n"+
     "The wall itself has seen better days, but it still serves to keep\n"+
     "the denziens of the swamp at bay. The roadway runs north\n"+
     "and west from here.\n";

    items=({
     "area","The land here is completely bare and ready for construction.\n"+
         "You wonder just how much this lot goes for....",
    });

    dest_dir=({
     "/players/daranath/qualtor/swamp/outer_trail2.c","north",
     "/players/daranath/qualtor/swamp/swamp1.c","east",
     "/players/daranath/qualtor/wayin2.c","west",
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

