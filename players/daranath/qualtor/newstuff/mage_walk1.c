#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>

inherit "room/room";

reset(int arg){
if(!present("child")) {
move_object(clone_object("/players/daranath/qualtor/folk/chld_flame.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Wizard's Walkway"+NORM+" (east, west)\n"+
"A short roadway runs east and west through this area, just south of a\n"+
"small pond teaming with small fish. The tranquil nature of the roadway, \n"+
"combined with the pond, makes this a rather relaxing area within the\n"+
"chaos of the city itself.\n";

    items=({
"roadway","Dark stone makes up the short roadway leading east and west",
"pond","A newly built pond is on the northern edge of the roadway",
"fish","The pond itself has been filled with all kinds of white, orange\n"+
     "and black goldfish, giving a rather chaotic look to the \n"+
     "serene pond",
"city","The main parts of the city of Qual'tor are back east from here,\n"+
     "while a new tower is being constructed just to the west",
    });

    dest_dir=({
"/players/daranath/qualtor/child_path1.c","east",
ROOT+"mage_walk2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

search() {
write("The fish draw your attention to them whenever you try to search for\n"+
      "something, almost as if they were put there for that purpose.\n");
  say(tp +" searches the area.\n");
return 1;
}

