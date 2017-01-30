#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("halfling")) {
move_object(clone_object(ROOT+"mon/half_bers.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Triumph Circle"+NORM+" (north, south)\n"+
"Once known for its tribute to the heroes of Qual'tors former arena,\n"+
"Triumph Circle was a popular attraction to anyone visiting the city.\n"+
"The roadway itself has only recently been cleared free of debris\n"+
"enough to travel once again.\n";

    items=({
"arena","The former arena is a skeleton of its former self",
"city","The city of Qual'tor is currently being rebuilt by its remaining populace",
"roadway","This part of the roadway has just started to see some work. Currently there\n"+
     "are too many threats to the citizens to continue work",
"citizens","The populace is not currenly in Arena Ward",
"debris","The debris about the roadway has been somewhat cleared",
    });

    dest_dir=({
      "/players/daranath/qualtor/newstuff/triumph2.c","north",
      "/players/daranath/qualtor/nor_road5.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("A quick search of Triumph Circle reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

