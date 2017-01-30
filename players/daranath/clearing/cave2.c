#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(arg){

    if(!arg){

    set_light(-1);
    short_desc="Cave within the Darkenwood";
    long_desc=
 "The dark walls of the cave press down upon you just the the Darkenwood\n"+
 "does with a sense of forboding and anxiety. The dark grey stone is\n"+
 "barely visible, making for a heightened sense of danger. Little light\n"+
 "trickles in from the cave mouth, making the shadows deeper then they\n"+
 "should be. A large well sits on the floor, leading down into the\n"+
 "darkness below.\n";

items=({
 "walls", "The dark grey colored stone enhances the sense of danger here\n",
 "shadows", "The shadows shift and move with the swaying of the trees\n",
 "something", "Looks like something is on the floor just to the north\n"+
              "from here",
 "well", "The well is made of the same dark grey stone as the walls of\n"+
         "the cave. The bottom of the well is not visible, leading to\n"+
         "uncertainty as to where it goes.\n"+
         "Perhaps you could "+YEL+"<"+NORM+" climb "+YEL+">"+NORM+" down into it",
 });


dest_dir=({
 "/players/daranath/clearing/cave1.c","south",
           });
        }
        }
init(){
  ::init();
  add_action("climb","climb");
  add_action("search","search");
}

climb() {
write("You descend into the darkness of the well.\n");
this_player()->move_player("descends into the darkness of the well#/players/daranath/underdark/level1/well_bottom.c");
  return 1;
}

search() {
write("You find varied tracks about the well, many of which lead into it.\n");
say (tp +"searches the area.\n");
  return 1;
}

arate() { return "YES"; }
