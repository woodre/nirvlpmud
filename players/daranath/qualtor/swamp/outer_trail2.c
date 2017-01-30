#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
    short_desc= "Outside the Walls of Qual'tor";
    long_desc=
     "The small roadway leads north and south just outside of the eastern\n"+
     "wall of Qual'tor. The roadway itself is rather worn and poorly\n"+
     "travelled, weeds and large chunks of rock preventing a smooth\n"+
     "ride along it.\n";

    items=({
     "area","The land here is completely bare and ready for construction.\n"+
         "You wonder just how much this lot goes for....",
    });

    dest_dir=({
     "/players/daranath/qualtor/swamp/outer_trail3.c","north",
     "/players/daranath/qualtor/swamp/outer_trail1.c","south",
/*
     "/players/daranath/qualtor/mansion/lot14.c","east",
*/
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Nothing of interest is about the roadway.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


