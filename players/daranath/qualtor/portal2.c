#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
/* Killzone! - Feldegast 10-15-01
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
*/
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"*"+NORM+"unknown"+HIR+"*"+NORM+")");
    long_desc=
     "Swirling red mist fills the area, the mist being the same dark\n"+
     "shade of red as the portal on the tower. A rocky patch of ground\n"+
     "leads further into the mist, the rock seems to float through\n"+
"the surreal landscape. You can go "+HIR+"forward"+NORM+" or "+HIR+"back"+NORM+" within the\n"+
     "swirling mists.\n";

    items=({
     "rock","The rock is dark grey in color",
     "stone","The stone is dark grey in color",
     "mist","The dark red mist swirls about you in a threatening manner",
     "mists","The dark red mist swirls about you in a threatening manner",
    });

    dest_dir=({
/*
      "/players/daranath/qualtor/portal3.c","forward",
      "/players/daranath/qualtor/portal1.c","back",
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
    write("You cannot focus on anything within the swirling portal.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

    dar_forward() {
    if(present("coil")) {
    write("The Mourning Coil blocks your attempt to move further into the mist.\n");
    return 1; }
 this_player()->move_player("forward into the swirling mist#players/daranath/qualtor/portal3.c");
return 1;
    }

dar_back() {
write("\nYou leave back into the mist.\n\n");
 this_player()->move_player("back in the swirling mist#players/daranath/qualtor/portal1.c");
return 1;
}
