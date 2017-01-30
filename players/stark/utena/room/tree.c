inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("mari"))  {
MOCO("/players/stark/utena/mon/mari.c"),this_object());  }
if(!present("tsuwabuki"))  {
MOCO("/players/stark/utena/mon/tsuwabuki.c"),this_object());  }

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}
}

    if(arg) return;
    set_light(1);
    set_listen("You hear the whisperings of young students.");
    set_smell("The wild grass and flowers give off a pleasent scent.");
    set_search("You search the grassy knoll, but find no gunman or anything else interesting.");
    short_desc="Ohtori Academy Grounds";
    long_desc=
"   The path bends around a grassy knoll.  The grass continues to a \n"+
"field in the south.  On the slope of the knoll a tree offers up \n"+
"some shade.\n";

items=({
"knoll","A sloping bump in the grass",
"grass","A field of wild grass",
"tree","A tree offering shade to anyone looking to relax"
});

dest_dir=({
"/players/stark/utena/room/grass.c", "south",
"/players/stark/utena/room/court.c", "east"
});
}

