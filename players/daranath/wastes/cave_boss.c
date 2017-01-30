#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
move_object(clone_object(ROOT+"mon/demon.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin6.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin5.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Lair of "+HIR+"Cormax"+NORM);
long_desc=
"At the end of the largest tunnel leading from the main cave, the area is greatly\n"+
"changed from the rest of the complex. Small fires burn randomly around the area\n"+
"seemingly feeding off the rocks themselves. A large pool of liquid rests on the\n"+
"far side of the chamber, while small tunnels lead both east and west.\n";

items=({
"complex","The complex consists of a large cave with 3 tunnels leading from it.\n"+
     "Plus, a large pool of stagnant liquid sits against the far wall",
"fires","Several small fires burn with the cave, shedding light around the area",
"liquid","A pool of a strange stagnant liquid is here, nothing that you would want to bathe in",
"pool","A large pool of a strange liquid takes up the northern edge of the chamber",
"area","The chamber is quite large, with three tunnels leading from the main area, \n"+
     "heading south, east and west. A large pool of liquid rests against the \n"+
     "northern cave wall",
"rock","The rocks are on fire here, shedding light around the chamber",
"rocks","The rocks are on fire here, shedding light around the chamber",
"tunnels","Small tunnels run east and west, while the main one heads back south",
    });

    dest_dir=({
  ROOT+"caves1.c","south",
  ROOT+"caves3.c","east",
  ROOT+"caves2.c","west",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Larger footprints are mixed in with the goblin ones here.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }
