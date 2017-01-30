#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("queen")){
move_object(clone_object(ROOT+"mon/cent_queen.c"),this_object());
}
move_object(clone_object(ROOT+"mon/centipede2.c"),this_object());
move_object(clone_object(ROOT+"mon/centipede2.c"),this_object());
move_object(clone_object(ROOT+"mon/centipede2.c"),this_object());
move_object(clone_object(ROOT+"mon/centipede2.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Plateau Cave"+NORM);
long_desc=
"The cliffs up on the Gundar Plateau easily hide this small cave from sight. \n"+
"Light streams in through the cave mouth, and the shallow depth of the cavern\n"+
"keeps it well illuminated. A good amount of sand covers the rocky floor,\n"+
"making the whole cavern almost seem like a beach up in the sky.\n";

items=({
"cliffs","The plateau cliffs extend out over the top of the plateau",
"plateau","Its difficult to see the plateau from inside the cave",
"cave","This small cave is a perfect home for any type of large flying creature",
"sand","The sand has been bleached over time by the sun, making the cave look like a beach",
"beach","The cave looks like a beach, there is no beach here",
"floor","The rocky floor is covered in sand",
"cavern","The cavern is well illuminated by light this high up on the plateau",
    });

    dest_dir=({
  ROOT+"plateau9.c","climb",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The cavern is quite empty, save for the sand everywhere.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
