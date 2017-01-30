#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

int ishere;

reset(arg){
  if(!present("guy")){ 
    move_object(clone_object("players/softly/algiers/mobs/guy.c"),this_object());
  }
  if(!present("fish")){ 
    move_object(clone_object("players/softly/algiers/mobs/fish.c"),this_object());
  }
  if(arg) return;
  set_light(1);

  short_desc = "Sugar Mill";
  long_desc ="\n\
  The inside of a large wooden building is lit with torches.\n\
Large vats and a few unfamiliar machines have been pushed\n\
against the walls leaving a large open space in the center.\n\
An earthen lined pit is in the center of the space, stained\n\
and wet in places.  A few rough wooden benches are placed\n\
around the pit, providing sitting space for spectators.  A\n\
few small steel cages sit off to the side.\n";
  add_smell("building", "The building smells strongly of burnt sugar.");
  items = ({
    "torches", 
    "Lit wooden staves stand around the room",
    "walls", 
    "Horizontal planks of unpainted lumber line the room",
    "floor",
    "The floor is of hard packed earth",
    "road",
    "The brown earthen road is very dusty",
    "building",
    "An open raw wood building that smells like burnt sugar",
    "pit",
    "The pit is a hard packed dirt floor raised to eye level",
    "vats",
    "Huge steel vats that were once used to boil sugar cane",
    "machines",
    "Industrial grade machines of unknown purpose",
    "space",
    "The center is quite open",
    "benches",
    "Rough hand hewn slabs of wood on legs",
    "cages",
    "Steel cages, some filled with fighting gamecocks\n\
and others with their doors open and a few feathers\n\
inside",
    "spectators",
    "All sorts of townspeople wait for the next fight to begin",
  });
  add_property("NF");
  dest_dir = ({
    "/players/softly/algiers/rooms/road17.c","leave",
  });
}

exit(ob) 
{ 
  if(ob->is_player()) 
    { 
      if(present("Vizard", this_object())) present("Vizard", this_object())->decrease_ishere(); 
    }
}
