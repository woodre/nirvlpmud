#include <ansi.h>
#define ROOT "/players/daranath/qualtor/newstuff/"
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("constable")) {
move_object(clone_object(ROOT+"mon/constable.c"),this_object());
}
  if(!arg){

    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Market Square)");
    long_desc=
"               "+BOLD+"Market Pathway"+NORM+" (west)\n"+
  "Located alongside the eastern ruins of Qual'tor, a large marketplace has\n"+
  "been cleared out. New shops line the market square, and more are being\n"+
  "built.\n";
  "A large signpost sticks from the ground here.\n";

    items=({
  "road","The roadway is worn smooth by travellers",
  "roadway","The roadway is worn smooth by travellers",
  "square","The market square is a popular destination for fashions of all types",
  "market","The market square is a popular destination for fashions of all types",
  "wares","A variety of different styles are displayed in the windows of the shops",
  "shop","Several new shops line both sides of the square, with more being built",
  "shops","Several new shops line both sides of the square, with more being built",
  "sign","The signpost reads: Tugnutt's warrior outfits to the North\n"+
         "                    Chandra's fine clothing to the South\n"+
         "                    Randal's Apothecary Shop to the East",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/knightstore.c","north",
  "/players/daranath/qualtor/newstuff/femstore.c","south",
  "/players/daranath/qualtor/newstuff/potionstore.c","east",
  "/players/daranath/qualtor/newstuff/market_path2.c","west",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("enter_shop","lift");
    }

    search(){
     write("You find a small trapdoor that seems to have been forgotten. Perhaps\n"+
           "you could "+HIR+"<"+NORM+" lift "+HIR+">"+NORM+" the trapdoor.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

enter_shop() {
write("Pulling with all your strength, you manage to lift the old trapdoor and\n"+
      "slip inside.\n\n");
this_player()->move_player("through a hidden trapdoor#/players/daranath/qualtor/newstuff/smackstore.c");
return 1;
}

