#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/"
#include <ansi.h>
inherit "room/room";
int a;

reset(int arg){
a = random(4);
if(a == 0) {
  if(!present("drifter")) {
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
  }
}
if(a == 1) {
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
}
if(a == 2) {
move_object(clone_object(ROOT+"newstuff/mon/doomdrifter.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/drifter.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+WHT+"Crystalline Tower"+NORM+")");
    long_desc=
     "A weakened ceiling from the vast destruction in the city doomed\n"+
     "this hallway, causing it to cave in upon itself, barring\n"+
     "further passage south.\n";

    items=({
     "ceiling","The ceiling has fallen into a pile of stone and rock",
     "stone","The stone is dark grey in color",
     "rock","The rock is dark grey in color",
     "hallway","The stone hallway has collasped, who knows where it\n"+
               "might have gone in its time",
    });

    dest_dir=({
      "/players/daranath/qualtor/cryst2.c","north",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Nothing of value is found amongst the collasped stone and rock.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


