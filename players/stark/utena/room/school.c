inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

	if(!present("a-ko"))  {
    MOCO("/players/stark/utena/mon/a-ko.c"),this_object());  }
    if(!present("b-ko"))  {
    MOCO("/players/stark/utena/mon/b-ko.c"),this_object());  }

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}

}

    if(arg) return;
    set_light(1);

    set_listen("Undecipherable din flows forth from the student body all around.");
    set_smell("Perfume, sweat, and hormones are rampant in this close environment.");
    set_search("In the shadows of the hall, you see two girls performing.\n");

    short_desc="Halls of Ohtori Academy";
    long_desc=
"   A long hallway stretches out before you.  It is a sea of students \n"+
"and lockers.  Classroom doors break through to serve as beacons.  \n"+
"There is a stairwell leading upward.  Opposite the stairs, the school \n"+
"grounds open up to the south.  Classrooms are in all other directions.\n";

items=({
"hallway","A tiled hallway connecting all of the classrooms",
"halls","A tiled hallway connecting all of the classrooms",
"hall","A tiled hallway connecting all of the classrooms",
"students","Students move alone and in groups at all speeds",
"lockers","Lockers are placed everywhere along the hall",
"locker","One of many lockers",
"doors","There are many doors along this hallway, one just to the north reads 'Student Council'",
"door","Wow... a door",
"stair","A stairway leading to the second floor",
"stairs","A stairway leading to the second floor",
"stairwell","A stairway leading to the second floor",
"stairway","A stairway leading to the second floor",
"grounds","The main quad is to the south",
"shadow","You see a shadow of two girls",
"shadows","You see a shadow of two girls"
});


dest_dir=({
"/players/stark/utena/room/court.c", "south",
"/players/stark/utena/room/fence.c", "west",
"/players/stark/utena/room/kendo.c", "east",
"/players/stark/utena/room/cafe.c", "up",
"/players/stark/utena/room/school2.c","north"
});
}