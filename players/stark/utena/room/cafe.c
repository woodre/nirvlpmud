inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}

}


if(!present("yuuko"))  {
MOCO("/players/stark/utena/mon/yuuko.c"),this_object());  }
if(!present("aiko"))  {
MOCO("/players/stark/utena/mon/aiko.c"),this_object());  }
if(!present("keiko"))  {
MOCO("/players/stark/utena/mon/keiko.c"),this_object());  }
if(!present("nanami"))  {
MOCO("/players/stark/utena/mon/nanami.c"),this_object());  }

if(arg) return;
    set_light(1);
    set_listen("Conversations from the many tables combine to a low murmur about the room.\n");
    set_smell("Many delicious and exquisite smells fill this room.");
    set_search("There is nothing special about this room.");
    short_desc="Ohtori Academy Cafeteria";
    long_desc=
"This is the cafeteria of Ohtori Academy.  This is a gathering place \n"+
"for the students.  Many deadly challenges have been made in this \n"+
"comfortable setting.  There are tables and chairs scattered around the \n"+
"area.  Windows overlook the grassy quad a floor below.  There is a \n"+
"stairwell leading downward.  The cafeteria extends east to a balcony.  \n"+
"There is a hallway to the west that leads to the Music room.\n";

items=({
"student","Student sit down in groups around the tables",
"windows","You can see the quad below.  But you could get a better view from the balcony",
"balcony","A balcony overlooking the campus",
"stair","A stairway leading to the first floor",
"stairs","A stairway leading to the first floor",
"stairwell","A stairway leading to the first floor",
"stairway","A stairway leading to the first floor",
"tables","Clean white tables give room for four to five students",
"chairs","Chairs are placed around tables and some alone",
"hallway","The only interesting room down the hallway is the Music room"
});

dest_dir=({
"/players/stark/utena/room/school.c", "down",
"/players/stark/utena/room/piano.c", "west",
"/players/stark/utena/room/balcony.c", "east"
});
}
