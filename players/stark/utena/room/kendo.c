inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("saionji"))  {
MOCO("/players/stark/utena/mon/saionji.c"),this_object());  }

    if(arg) return;
    set_light(1);
    set_listen("The room is still and silent.");
    set_smell("Cleaning as part of training has destroyed the sweat smell of the days activities.");
    set_search("There is nothing out of the ordinary for a Kendo Hall.");
    short_desc="Kendo Hall";
    long_desc=
"   The Hall of the Kendo Club is a long simple room.  The floor is \n"+
"done in polished wood.  There is a stand for practicing swords and \n"+
"bokens alike.  The room is sometimes alive with the many practitioners \n"+
"of the Art of Kendo.  But today the darkened room is set up for only \n"+
"one lonely man.\n";

items=({
"room","This long room is made for the practicioners of Kendo",
"floor","The floor has been polished daily as part of training",
"wood","The floor has been polished daily as part of training",
"stand","A stand to hold the practice swords and fighting bokens",
"swords","Most of the swords are practicing swords, light and packing a lesser punch",
"bokens","These solid wooden swords are made for Kendo fights",
"boken","One of many wooden swords"
});

dest_dir=({"/players/stark/utena/room/school.c", "west"
});
}
