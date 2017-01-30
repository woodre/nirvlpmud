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
     "A small courtyard seperates the stables from the north road,\n"+
     "visitors used to bring thier mounts here and stableboys would\n"+
     "usher them into thier stalls. The stables themselves sits just\n"+
     "to the north, while the roadway opens to the south.\n";

    items=({
     "statue","The large statue shows a gruesome scene of a group of gaurdsmen from\n"+
              "the city fought against many orcs, goblins, and ogres\n"+
              "while defending the city. It is quite impressive",
     "walkway","The walkway is made of stone and gravel",
    });

    dest_dir=({
      "/players/daranath/qualtor/stable2.c","north",
  "/players/daranath/qualtor/newstuff/market_path1.c","south",
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

