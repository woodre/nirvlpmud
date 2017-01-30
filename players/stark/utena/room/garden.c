inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("anthy"))  {
MOCO("/players/stark/utena/mon/anthy.c"),this_object());  }

    if(arg) return;
    set_light(1);

    set_smell("The sweet scent of roses.");
    set_listen("Anthy is gently singing.");
    set_search("You find many beautiful roses.");

    short_desc="Rose Garden";
    long_desc=
"   The Rose Garden is a caged atrium made especially for the roses.  \n"+
"Many breeds of roses have been grown in this greenhouse, but it is \n"+
"mostly filled with red roses.  It is also the cage of the Rose Bride.  \n"+
"This is where she has spent most of her time up until recently.\n";

items=({
"atrium","This gardenhouse was made specially for the Rose Bride",
"roses","Many beautiful roses fill this room.  Rare, exotic, plain and pure.  All kinds can be found",
"greenhouse","This greenhouse helps the many Roses grow",
"cage","This caged room was made specially for the Rose Bride"
});

dest_dir=({
"/players/stark/utena/room/court.c", "out"
});

}
    query_no_fight() {return 1;}