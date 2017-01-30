#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!present("samuel")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/mon/samuel.c"),this_object());
}
  if(!present("sign")) {
move_object(clone_object("/players/daranath/qualtor/obj/eshop.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
     "Shelves filled with various items for sale line the walls of this\n"+
     "small store. A curtain covers a small doorway leading into\n"+
     "a back room behind the counter. A sign on the wall lists the\n"+
     "various items for sale.\n";

    items=({
     "shelves","The shelves are mostly made of wood",
     "curtain","A black curtain covers the entrance to the back room",
     "doorway","The doorway leads somewhere you cannot go",
     "counter","The counter also displays items for sale",
    });

    dest_dir=({
      "/players/daranath/qualtor/east_road1.c","north",
      "/players/daranath/qualtor/nowhere.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_south","south");
    }

    search(){
    write("There are way too many items to search here. You could\n"+
          "spend days looking through everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_south(){
    write("I'm sure that the shop owners would not appreciate you in their\n"+
          "back room. Perhaps you should stay here.\n");
    say(tp +" peaks behind the curtain.\n");
    return 1;
    }
