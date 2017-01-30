#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Caves"+NORM);
long_desc=
"The darkness of the caves is lessened here, a glowing fungus on the walls is\n"+
"shedding enough light for you to see by. The passage ends here, leaving your\n"+
"only option to be turning around back torwards the main cave.\n";

items=({
"darkness","The darkness here is cut buy the glowing fungus",
"fungus","The softly glowing fungus sheds enough light for you to see by",
"cave","The main cave of Cormax sits east of your current postition",
"light","The cave light is provided by a glowing fungus in the walls",
"passage","The tunnels end here, making you turn back east",
"walls","The natural rock walls grow darker the further into the cave you look",
"wall","The natural rock walls grow darker the further into the cave you look",
    });

    dest_dir=({
  ROOT+"cave_boss.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is found in the passage.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
