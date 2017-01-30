inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}
}

    if(arg) return;
    set_light(1);

    set_listen("The din of the student body has since faded to a few streaming conversations.");
    set_smell("Nothing intesting.");
    set_search("You find nothing out of ordinary, except the building to the north.");

    short_desc="Ohtori Academy";
    long_desc=
"   The path turns into a road, still made for walking and not driving\n"+
"however.  The main part of the school is to the west, but a few more \n"+
"of the halls are scattered near the exit.  The road carries eastward \n"+
"to some of the dorms, and the city.  The Mikage Seminar Hall is to the \n"+
"north.\n";

items=({
"path","A path you can follow west and east",
"road","A path you can follow west and east",
"school","Most of the Academy is to the west",
"halls","Some halls have been placed away from the main part of the Academy",
"dorms","Large dorms for students are of to the east",
"hall","The Mikage Seminar Hall can be 'enter'ed from here"
});

dest_dir=({
"/players/stark/utena/room/brose1.c", "enter",
"/players/stark/utena/room/street2.c", "east",
"/players/stark/utena/room/court.c", "west"
});

}
