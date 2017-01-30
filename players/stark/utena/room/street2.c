inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}
}

if(!present("wakaba"))  {
MOCO("/players/stark/utena/mon/wakaba.c"),this_object());  }

    if(arg) return;
    set_light(1);

    set_smell("Nothing out of the ordinary.");
    set_search("You find it odd that you can't enter the town, but shrug it off.\n");
    set_listen("You hear the voices of students off to the west.\n");
    short_desc="Outside Ohtori Academy";
    long_desc=
"   The road leads westward towards Ohtori Academy.  The students' \n"+
"dorms are all along this road.  To the north is a large dorm with a \n"+
"garden in front of it.  The road continues further east to a \n"+
"neighboring town.\n";

items=({
"path","A path you can follow west",
"road","A path you can follow west",
"dorms","Large dorms for students are of to the east",
"dorm","A small dorm can be 'enter'ed from here",
"town","A small town can be seen down the hill from here",
"garden","A small rose garden is layed out in front of the dorm"
});

dest_dir=({
"/players/stark/utena/room/dorm.c", "enter",
"/players/stark/utena/room/street1.c", "west"
});

}

init(){
::init();
add_action("east","east");
}

east(){
write("You start to walk towards the town, but... decide to stay near the school.\n");
return 1; }

