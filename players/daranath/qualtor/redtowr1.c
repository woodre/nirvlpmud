#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor "+NORM+"("+RED+"RedTower"+NORM+")");
    long_desc=
     "A tight, spiraling staircase ascends to the very top of the\n"+
     "Red Tower and descends into the darkness below. An iron handrail\n"+
"is your only support if you chose to brave the small stair.\n"+
"The glowing field of force can be seen through the exit.\n";

    items=({
     "wall","The red stone walls are the same as elsewhere in the tower",
"field","The field of force protects the tower from the falling ash",
"exit","The exit is through a small stone archway",
     "stair","The small stair leads up and down",
     "rail","The handrail is made of a dark iron metal",
     "handrail","The handrail is made of a dark iron metal",
     "staircase","The staircase leads to the top of the tower, while\n"+
                 "it also plummets into the darkness below",
     "darkness","Who knows what horros lurk within the darkness",
    });

    dest_dir=({
      "/players/daranath/qualtor/redtowr7.c","up",
      "/players/daranath/qualtor/redtowr2.c","down",
      "/players/daranath/qualtor/redtowr_ct.c","out",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_out","out");
    }

    search(){
    write("You find nothing within the area of interest.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_out(){
write("\nAs you leave the tower, you are no longer protected by the force field.\n\n");
return 0;
}

