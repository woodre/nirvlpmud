#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"*"+NORM+"unknown"+HIR+"*"+NORM+")");
    long_desc=
     "Swirling red mist fills the area, the mist being the same dark\n"+
     "shade of red as the portal on the tower. A rocky patch of ground\n"+
     "leads further into the mist, the stone seems to float through\n"+
"the surreal landscape. You can go "+HIR+"forward"+NORM+" or "+HIR+"back"+NORM+" within the\n"+
     "swirling mists.\n";

    items=({
     "mist","The dark red mist swirls about you in a threatening manner",
     "ground","The rocky outcropping is not supported by anything visible,\n"+
             "it seems to float here within the mist",
     "stone","The stone is dark grey in color",
     "rock","The rock is dark grey in color",
     "mists","The dark red mist swirls about you in a threatening manner",
    });

    dest_dir=({
/*
      "/players/daranath/qualtor/portal2.c","forward",
      "/players/daranath/qualtor/redtowr_tp.c","back",
*/
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_forward","forward");
add_action("dar_back","back");
    }

    search(){
    write("You cannot focus on anything within the swirling mist.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_forward(){
write("\nYou move forward within the swirling mist.\n\n");
 this_player()->move_player("forward into the swirling mist#players/daranath/qualtor/portal2.c");
return 1;
}

dar_back() {
write("\nYou leave the swirling mists.\n\n");
 this_player()->move_player("back in the swirling mist#players/daranath/qualtor/redtowr_tp.c");
return 1;
}

