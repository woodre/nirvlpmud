#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("cavemon")) {
  int a, b; a = 0; b = (random(4)+1);
while(a<b){
  int c; c = random(20);
if(c == 0) move_object(clone_object(ROOT+"mon/goblin6.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/goblin5.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/sledge.c"),this_object());
if(c == 3) move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
if(c == 4) move_object(clone_object(ROOT+"mon/lurker.c"),this_object());
if(c == 5) move_object(clone_object(ROOT+"mon/lurker.c"),this_object());
if(c == 6) move_object(clone_object(ROOT+"mon/chul.c"),this_object());
if(c == 7) move_object(clone_object(ROOT+"mon/chul.c"),this_object());
if(c == 8) move_object(clone_object(ROOT+"mon/maw.c"),this_object());
if(c == 9) move_object(clone_object(ROOT+"mon/maw.c"),this_object());
if(c ==10) move_object(clone_object(ROOT+"mon/mudman.c"),this_object());
if(c ==11) move_object(clone_object(ROOT+"mon/mudman.c"),this_object());
if(c ==12) move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
if(c ==13) move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
if(c ==14) move_object(clone_object(ROOT+"mon/goblin2.c"),this_object());
if(c ==15) move_object(clone_object(ROOT+"mon/goblin2.c"),this_object());
if(c > 15) move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
  a++; }
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Caves"+NORM);
long_desc=
"The darkness of the caves is lessened here, a glowing fungus on the walls is\n"+
"shedding enough light for you to see by. The passage itself heads back east to\n"+
"the main cave, and west deeper into the rock.\n";

items=({
"darkness","The darkness here is cut buy the glowing fungus",
"fungus","The softly glowing fungus sheds enough light for you to see by",
"cave","You stand within a large cave, giving you some shelter from the rocky\n"+
     "wastes. The caves itself looks natural, while a natural tunnel runs\n"+
     "northwards from here",
"rock","The rock within the cave grows darker the further you explore inwards",
"passage","The tunnel passage runs east into the main cave and west from here",
"walls","The natural rock walls grow darker the further into the cave you look",
"wall","The natural rock walls grow darker the further into the cave you look",
    });

    dest_dir=({
  ROOT+"caves_entry.c","east",
  ROOT+"caves5.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing of interest is found in the area.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
