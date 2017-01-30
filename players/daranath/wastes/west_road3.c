#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plains"+NORM);
long_desc=
"The roadway ends abruptly in a tangled pile of rock and stone. A wide swath\n"+
"has been cut into the earth, disrupting the roadway's path and tearing the\n"+
"surrounding landscape apart. You can either follow the channel that was cut\n"+
"into the earth southwest, or cross over it and continue heading westbound.\n";

items=({
"roadway","The ancient roadway is cut in half by the lava trail",
"rock","The passage of the lava has disrupted the local earth",
"stone","The passage of the lava has disrupted the local earth",
"swath","The swath looks like it is the remnants of an ancient lava flow",
"earth","The earth has been torn up by an ancient lava flow",
"channel","The ancient flow of lava has created a channel that you can walk in",
    });

    dest_dir=({
  ROOT+"west_road2.c","east",
  ROOT+"vapor1.c","west",
  ROOT+"west_road4.c","southwest",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is found about the area.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
