inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

	if(!present("c-ko"))  {
    MOCO("/players/stark/utena/mon/c-ko.c"),this_object());  }

    if(arg) return;
    set_light(1);

    set_listen("The room is quiet, deeply and incredibly quiet.");
    set_smell("This Hall is kept very clean by the staff, and leaves no scent.");
    set_search("In the shadows of the hall, you see a girl performing.\n");

    short_desc="Mikage Seminar";
    long_desc=
"   The Hall for the Mikage Seminar is one long room.  There are chairs \n"+
"lined up across both long walls.  A group of pictures are hung on the \n"+
"wall near the entrance.  There are two doors in the room.  One to the \n"+
"outer world, and one deeper inside the Mikage Seminar Hall.\n";

items=({
"chairs","Each chair has a card on it",
"card","Every card is pointed toward the door at the end of the hall",
"walls","The long walls are bare except for a few pictures",
"wall","The long walls are bare except for a few pictures",
"pictures","There are shots of different people in black duelists wear",
"doors","Both made of strong wood, one deeper inside, one retreating",
"hall","This is the Hall where the Mikage Seminar is held",
"shadow","You see a shadow of a girl",
"shadows","You see a shadow of a girl"
});

dest_dir=({"/players/stark/utena/room/street1.c", "out",
"/players/stark/utena/room/brose2.c", "enter"
});

}
