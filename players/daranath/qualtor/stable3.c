#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
int a;  a = random(2);
if(a == 0) {
move_object(clone_object(ROOT+"mon/stable_boy.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Stables)");
    long_desc=
     "The North Road Stables were the finest anywhere within the city\n"+
     "of Qual'tor. Stableboys would go out into the courtyard and\n"+
     "get the mounts of visitors to the city and house them within\n"+
     "one of the many stalls that line the stables. The stalls sit\n"+
     "to the east and west, while the stables themselves run north\n"+
     "and south from here.\n";

    items=({
     "statue","The large statue shows a gruesome scene of a group of gaurdsmen from\n"+
              "the city fought against many orcs, goblins, and ogres\n"+
              "while defending the city. It is quite impressive",
     "walkway","The walkway is made of stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/stable_end.c","north",
      "/players/daranath/qualtor/stable2.c","south",
      "/players/daranath/qualtor/stable7.c","east",
      "/players/daranath/qualtor/stable6.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Hay and straw is tracked from the stables by horses that leave.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

