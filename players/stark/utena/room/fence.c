inherit "/players/stark/room";
#include "/players/stark/defs.h"
int crowd;
reset(arg){
crowd=1;

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}
}


if(!present("shiori"))  {
MOCO("/players/stark/utena/mon/shiori.c"),this_object());  }
if(!present("juri"))  {
MOCO("/players/stark/utena/mon/juri.c"),this_object());  }

    if(arg) return;
    set_light(1);
    set_listen("The clash of brandished blades.");
    set_smell("Sweat from the many practicioners wafts throught the room.");
    /*set_search("There are no secrets beneath the tatami mats.");*/
    short_desc="Fencing Hall";
    long_desc=
"   The Hall of the Fencing Club is a rather large two story room.  The \n"+
"bottom floor is covered in tatami mats.  The second floor is a balcony \n"+
"that lines the room on all sides.  The room is teeming with fencers \n"+
"and their admirers.\n";

items=({
"room","This two story room is the Fencing Hall",
"mats","Tatami mats are made of light green woven straw.  They are resilient under the foot and have a sweet grassy smell",
"tatami","Tatami mats are made of light green woven straw.  They are resilient under the foot and have a sweet grassy smell",
"mat","Tatami mats are made of light green woven straw.  They are resilient under the foot and have a sweet grassy smell",
"balcony","A balcony where students not in the club can watch the matches",
"students","Students above watch on, students below spar in full fencing gear"
});

dest_dir=({
"/players/stark/utena/room/school.c", "east"
});

}


init() {
::init();
add_action("search","search");
}

search(){
	if(crowd){
		write("The crowd shifts away and a new fighter appears.\n");
		MOCO("/players/stark/utena/mon/ruka.c"),this_object());
		crowd=0;
	return 1;}
	write("The crowd is silent and in shock...\nThere is nothing of interest in this room.\n");
return 1;}

