inherit "/players/stark/room";
#include "/players/stark/defs.h"
int found;
reset(arg){

found=0;
if(!present("mamiya"))  {
MOCO("/players/stark/utena/mon/mamiya.c"),this_object());  }
if(!present("mikage"))  {
MOCO("/players/stark/utena/mon/mikage.c"),this_object());  }

    if(arg) return;
    set_light(0);

    set_listen("There is a small dripping sound near the pool.");
    set_smell("The poor air circulation has left the room a bit dank.");
    /*set_search("There are several caskets lying around....");*/

    short_desc="The Black Rose Society meeting room.";
    long_desc=
"   A dark room deep below the footfalls of Ohtori Academy lies the \n"+
"birthplace of the Black Rose Society.  Here lies one hundred dead \n"+
"duelists.  Their caskets line the walls.  In the middle of the room \n"+
"there is a square glass pool.  There is one open casket near the pool.\n";

items=({
"duelists","These duelists were killed long ago to be used for Mikage's plans.  Their souls and powers have been drained into their rings",
"caskets","There are 100 caskets lining the wall.  Each containing the deceased body of a Duelists",
"pool","A single black rose is being cared for",
"casket","The body has been preserved perfectly",
"body","This is the body of an unknown duelist, his dueling ring still on his finger",
"ring","The Dueling Ring gone black is the signature of the Black Rose Society"
});

dest_dir=({
"/players/stark/utena/room/brose1.c", "up"
});

}


init() {
::init();
add_action("search","search");
}

search(){
	if(found){
		write("You find caskets and a single black rose... nothing more.\n");
	return 1;}
	write("You find a small sum of money in a box near the roses pool.\n");
	this_player()->add_money(1000+random(2000));
	found=1;
return 1;}