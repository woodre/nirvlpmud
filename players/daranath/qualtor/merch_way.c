#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Tiger Lane"+NORM+" (east, west)\n"+
     "Being the former heart of Qual'tors red light district, the\n"+
     "street here was once the wildest street within Qual'Tor.\n"+
     "Now, rubble and debris have considerably narrowed the grand avenue,\n"+
     "leaving only a narrow walkway running east and west here.\n";

    items=({
     "tower","The red tower just to the north of here is still in\n"+
             "decent shape, save its upper couple of levels that have\n"+
             "collapsed upon itself.",
     "rubble","The rubble is from the damaged buildings",
     "debris","The debris all about is from the destruction of Qual'tor",
     "street","The street runs east and west here",
     "walkway","The narrow walkway snakes its way through all the\n"+
               "rubble and debris about the area",
     "avenue","The avenue runs east and west here",
    });

    dest_dir=({
/*
      "/players/daranath/qualtor/mansion/cen21a.c","north",
      "/players/daranath/qualtor/mansion/depository.c","south",
*/
      "/players/daranath/qualtor/newstuff/new_entry.c","east",
      "/players/daranath/qualtor/child_path1.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_south","south");
    }

    search(){
    write("You find nothing about the rubble and debris.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_south(){
    write("The ruins of the Depository just smell like a bad idea.\n");
    return 1;
    }
