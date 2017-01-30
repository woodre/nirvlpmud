#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Triumph Circle"+NORM+" (east, south)\n"+
"The western edge of Triumph Circle was used by the various vendors and\n"+
"other marketeers selling their wares and foodstuff to the crowds on \n"+
"the days that contests were held in the arena. Nothing is left after\n"+
"the cities destruction, save for part of the dwarven constructed \n"+
"roadway.\n";

    items=({
"edge","This side of the circle is in better shape then most of them",
"vendors","The vendors and marketeers are long since gone",
"marketeers","The vendors and marketeers are long since gone",
"wares","No wares or foodstuffs are here for sale anymore",
"foodstuffs","No wares or foodstuffs are here for sale anymore",
"arena","The old arena that once sat to the northeast of here is currently in ruins",
"roadway","The tough old dwarven roadway still remains",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/triumph3.c","east",
  "/players/daranath/qualtor/newstuff/triumph5.c","south",
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

