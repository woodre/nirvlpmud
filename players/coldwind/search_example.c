#define tp this_player()->query_name()
#define ROOT "/players/areas/xianjin/"
#include "/obj/ansi.h"
inherit "room/room";
int c;

reset(int arg){
if(!present("man")) {
 c = random(5);
if(c == 0) {move_object(clone_object(ROOT+"peop/man4.c"),this_object());}
if(c == 1) {move_object(clone_object(ROOT+"peop/xguard2.c"),this_object()); }
if(c == 2) {move_object(clone_object(ROOT+"peop/xguard3.c"),this_object()); }
if(c == 3) {move_object(clone_object(ROOT+"peop/man1.c"),this_object());}
if(c == 4) {move_object(clone_object(ROOT+"peop/woman1.c"),this_object()); }
}
move_object(clone_object(ROOT+"peop/man2.c"),this_object());
  if(!arg){
    set_light(1);
    short_desc= (BOLD+BLU+"Road in Xian jin"+NORM+"(east,west)");
    long_desc=
     "The road east from the center of Xian jin has more new construction\n"+
     "than other areas of the city. On the north side of the road\n"+
     "an older shop from the before time has survived the destruction\n"+
     "when the majority of the city did not. Another small commericial\n"+
     "building sits on the south side of the road. The road runs east\n"+
     "and west from here.\n";

    items=({
     "road","The road is made of a blackish gravel that used to be solid pavement.",
     "building","The building is made from new, dark red brick.",
     "shop","The shop is to the north, built of weathered tan brick.",
    });

    dest_dir=({
      "/players/areas/xianjin/pawn1.c","south",
      "/players/areas/xianjin/eroad2.c","east",
      "/players/areas/xianjin/entry.c","west",
      "/players/areas/xianjin/eshop.c","north",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing more than worthless black gravel.\n");
    say(tp +" searches the surrounding area.\n");
     return 1;
    }


