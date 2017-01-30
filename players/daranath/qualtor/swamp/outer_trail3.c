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
     "road","The roadway is in poor shape and rarely travelled",
     "roadway","The roadway is in poor shape and rarely travelled",
     "rock","Large chunks of rock from the damaged wall are strewn about the area",
     "rocks","Large chunks of rock from the damaged wall are strewn about the area",
     "weeds","The weeds grow everywhere, everywhere!!!",
    });

    dest_dir=({
     "/players/daranath/qualtor/swamp/outer_trail4.c","north",
     "/players/daranath/qualtor/swamp/outer_trail2.c","south",
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


