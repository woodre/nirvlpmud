inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("student"))  {
	if(random(2)>0){
		MOCO("/players/stark/utena/mon/student.c"),this_object());
	}

}

    if(arg) return;
    set_light(1);

    set_smell("The wild grass and flowers give off a pleasent scent.");
    set_listen("Laughter is heard northward.");
    set_search("The only thing of importance is a small sign.");

    short_desc="Ohtori Academy Grounds";
    long_desc=
"   Waves of grass ripple in the field from a gentle wind.  To the \n"+
"northeast you can see a large school campus.  You have just stepped \n"+
"onto the grounds of Ohtori Academy.  There is a sign posted at the \n"+
"side of the path.\n";

items=({
"field","An open field of wild grass",
"grass","An open field of wild grass",
"school","A two story school shaped in half circle",
"campus","A two story school shaped in half circle",
"grounds","This is where you are",
"sign","A small sign you can read"
});

dest_dir=({
"/players/stark/utena/room/tree.c", "north",
"/players/stark/utena/room/connection.c", "south"
});

}
init(){
::init();
add_action("read","read");
}

read(arg){
if(!arg){ write("read what?\n"); return 1; }
if(arg == "sign"){
write("\n"+
"___________________________________________________________________\n"+
"|                                                                  |\n"+
"| Welcome to Ohtori Academy.                                       |\n"+
"| Based on the Japanese Anime: Shoujo Kakumei Utena                |\n"+
"|  Translated:  Revolutionary Girl Utena.                          |\n"+
"| This is a world of Duelists and Roses.  Please enjoy             |\n"+
"|                                                           Stark  |\n"+
"|__________________________________________________________________|\n");
return 1; }
write("read what?\n");
return 1; }

