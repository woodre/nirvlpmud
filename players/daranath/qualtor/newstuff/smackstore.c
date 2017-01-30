#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!present("chandra")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/mon/dominatrix.c"),this_object());
  }
  if(!present("sign")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/smackshop.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"*"+NORM+"unknown"+HIR+"*"+NORM+")");
    long_desc=
  "This darkened shop lies beneath the market square itself, the only entrance\n"+
  "a hidden trapdoor that not many players know about. Its wares are of an \n"+
  "unusual nature, both exciting and disgusting at the same time. There is both a\n"+
  "small plaque on the wall and a wooden sign listing items for sale.\n"+
  "A small iron ladder leads back up to the City Ward.\n";

    items=({
     "shelves","The shelves are mostly made of wood",
     "curtain","A black curtain covers the entrance to the back room",
     "doorway","The doorway leads somewhere you cannot go",
     "counter","The counter also displays items for sale",
  "plaque","The small metal plaque reads:\n\n"+
     "If you don't have a sense of humor regarding items of a sexual nature\n"+
     "then do NOT purchase anything from this store",
  "ladder","A small iron rung ladder leads back to the City Ward.\n"+
      "You can "+HIY+"climb"+NORM+" back up",
    });

    dest_dir=({
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("climb_up","climb");
    }

    search(){
    write("There are way too many items to search here. You could\n"+
          "spend days looking through everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

climb_up(){
write("You climb the iron ladder back to the City Ward of Qual'tor.\n");
this_player()->move_player("up the iron ladder#players/daranath/qualtor/newstuff/marketsq.c");
return 1;
}
