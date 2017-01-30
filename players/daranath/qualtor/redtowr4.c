#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";
   int a;

reset(int arg){
   a=0;
  if(!arg){

    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "Bits and pieces of wood lie all about the room, broken furniture,\n"+
     "desks, crates, kegs, and barrels scattered in a random fashion.\n"+
     "Someone was cleaning the tower and dragged all this refuse down\n"+
     "here. A strong and unpleasent smell enimates from somewhere\n"+
     "in the room.\n";

    items=({
     "furniture","All the furniture is broken and useless",
     "kegs","All the kegs are smashed and cannot hold a drop anymore",
     "barrels","All the barrels are smashes and useless",
     "desks","All the desks are empty, broken and useless",
     "room","There would seem to be a lot of firewood here",
     "wood","The broken pieces of wood come from all the items here",
     "refuse","The furniture and items are all broken and useless",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr3.c","north",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search(){
  if(a == 0) {
move_object(clone_object("/players/daranath/qualtor/mon/otyugh2.c"),this_object());
write("As you search the area, something explodes from the debris!!!\n");
say("As "+tp+" digs through the debris, something attacks!!!\n");
    a++;
 return 1;
}
  if(a == 1) {
  if(present("otyugh")) {
write("The otyugh prevents you from searching further.\n");
return 1; }
move_object(clone_object("/players/daranath/qualtor/obj/tigereye.c"),this_player());
write("You find something of value!\n");
say(tp +" finds something within the broken debris.\n");
  a++;
 return 1;
}
  if(a>1) {
write("You find nothing within the broken furniture and debris.\n");
say(tp +" searches the area.\n");
 return 1;
    }
}

