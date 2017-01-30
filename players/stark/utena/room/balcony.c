inherit "/players/stark/room.c";
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

    set_listen("Quiet conversations go on without the overpowering noise of the large cafeteria crowd.");
    set_smell("Many delicious smells waft in from the west.");
    set_search("Outside of a great view, this room has nothing to show.");

    short_desc="Balcony";
    long_desc=

"   This balcony juts out away from the cafeteria and main building.  \n"+
"It is covered on one end, and left open on another.  There are tables \n"+
"and chairs dispersed throughout the area.  The railing is done in \n"+
"steel.  From here you could "+HIR+"view"+NORM+" most of the campus.\n";

items=({
"campus","You could "+HIR+"view"+NORM+" the campus from here",
"balcony","It's what you're standing on",
"cafeteria","The area to the west where students dine",
"tables","Clean white tables give room for four to five students",
"chairs","Chairs are placed around tables and some alone",
"railing","The Ohtori Academy signet is woven out of curved steel"
});

dest_dir=({
"/players/stark/utena/room/cafe.c", "west"
});

}

init(){
::init();
add_action("view","view");
}

view(){
write(
"Ohtori Academy, a school like no other.  It has crafted and created some \n"+
"of the smartest, greatest, and most powerful people in the world.  From \n"+
"here, you can see the bustling of students on the paths and some on the \n"+
"plush lawns.  The two storied building has one main area, with two wings \n"+
"as is common.  The tower at the center of the main area looms high above \n"+
"the rest of the school.  It is where the heads of the school conduct their \n"+
"business.  Fighting the tower for visual superiority is the massive forest \n"+
"at the end of the Academy Grounds.  The forest seems to be one very large \n"+
"tree, but could just blend that way.  Normal students cannot get close \n"+
"enough to the fabled 'Dueling Forest' to examine it properly.\n");
say(TPN+" walks over to the railing and views the school grounds.\n");
return 1; }
