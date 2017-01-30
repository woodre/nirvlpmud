inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

    if(arg) return;
    set_light(1);
    set_listen("The forest is silent.");
    set_smell("You smell nothing out of the ordinary.");
    set_search("You search forest floor and find a path north");
    short_desc="A dimly lit forest";
    long_desc=
"   The forest canopy thins out from the west.  There is a defined \n"+
"path that curves farther to the southwest.  As the path curves to the \n"+
"north the foliage gets sparse and the grass beneath your feet becomes \n"+
"denser.\n";


items=({
"canopy","A ceiling of trees and their foliage",
"grass","A field of wild grass getting shorter as it leads north",
"path","An open path leading to the north",
"foliege","Grass and ferns at the floor, branches and leaves at the ceiling"
});

dest_dir=({
"/room/south/sforst17", "southwest"
});
}

init() {
::init();
add_action("north","north");
}

north(){
write_file("/players/stark/utena/log/enter",
 this_player()->query_real_name()+" entered on "+ctime(time())+"\n");
write("\n"+
	"You start walking northward...\n"+
	"The forest and all signs of it drift behind...\n"+
	"As you leave the forest a new world opens up...\n"+
	"You enter the world of Ohtori Academy...\n"+
	"Into the story of "+MAG+"Shoujo Kakumei Utena"+NORM+".\n\n");
TP->move_player("north#/players/stark/utena/room/grass");
return 1;}
