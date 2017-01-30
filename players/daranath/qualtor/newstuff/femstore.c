#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!present("chandra")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/mon/chandra.c"),this_object());
  }
  if(!present("sign")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/femshop.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Market Square)");
    long_desc=
     "Shelves filled with various items for sale line the walls of this\n"+
     "small store. A curtain covers a small doorway leading into\n"+
     "a back room behind the counter.\n"+
  "A sign on the far wall lists the various items for sale.\n";

    items=({
     "shelves","The shelves are mostly made of wood",
     "curtain","A black curtain covers the entrance to the back room",
     "doorway","The doorway leads somewhere you cannot go",
     "counter","The counter also displays items for sale",
    });

    dest_dir=({
      "/players/daranath/qualtor/newstuff/marketsq.c","north",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("ask_chandra","ask");
    }

    search(){
    write("There are way too many items to search here. You could\n"+
          "spend days looking through everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

ask_chandra() {
if(this_player()->query_money() < 100) {
write("Chandra says: I'm sorry, but you don't have enough money to shop here.\n"+
      "     Maybe you can come back later and I'll help you out, ok?\n");
return 1; }
write("Chandra says: You want to learn about my wares? Lets see...\n\n"+

      "The silk rose sash is a favorite amongst the ladies of the city\n"+
      "A crushed velvet dress is simply stunning\n"+
      "Spiked heeled boots complement any outfit\n"+
      "A lavender Vest or Skirt is high style these days\n"+
      "A box of chocolates can heal the mind and body at the same time\n"+
      "Skintight leather is the only way to make a catsuit\n"+
      "The mace is a favored weapon of mine, so I sell them here\n"+
      "Mithril chainmail is both light and strong, perfect for a lady\n\n"+
      "You tip Chandra "+YEL+"100"+NORM+" coins and she thanks you.\n");
  this_player()->add_money(-100);
return 1; 
}

