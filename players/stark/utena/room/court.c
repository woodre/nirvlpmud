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

    set_listen("Undecipherable din flows forth from the student body all around.");
    set_smell("Perfume, sweat, and hormones waft around mostly undetectable.");
    set_search("You shouldn't search other student's possesions!  Nothing seem unordinary\n");

    short_desc="Ohtori Academy Courtyard";
    long_desc=
"   The courtyard is broken into four grassy quadrants.  The grid is \n"+
"made by the cut of two separate paths.  Many students congregate and \n"+
"spend their off time here.  There is an atrium off in a corner by the \n"+
"school.  \n";

items=({
"quadrants","The courtyard is divided into four parts",
"grid","Four small grass plots",
"students","Students talk, relax, and walk about the courtyard",
"atrium","A steel atrium you could 'enter'",
"paths","Two paths cross in the center of the court"
});

dest_dir=({
"/players/stark/utena/room/garden.c", "enter",
"/players/stark/utena/room/school.c", "north",
"/players/stark/utena/room/tree.c", "west",
"/players/stark/utena/room/street1.c", "east"
});

}

init() {
::init();
add_action("blocked","south");
}

blocked() {
write("The passage south is blocked until further notice.\n");
return 1;
}
