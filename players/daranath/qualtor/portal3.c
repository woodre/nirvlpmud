#include <ansi.h>
#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/qualtor/mon/torment.c"),this_object());
/* Added random check. -Feldegast 10-15-01 */
if(!random(2))
move_object(clone_object("/players/daranath/qualtor/mon/mourn_coil2.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"("+HIR+"*"+NORM+"unknown"+HIR+"*"+NORM+")");
    long_desc=
     "Swirling red mist fills the area, the mist being the same dark\n"+
     "shade of red as the portal you left far behind. The small path\n"+
     "of rock ends here, narrowing dangerously to less then ten\n"+
"feet across. You may travel "+HIR+"back"+NORM+" into the mist.\n";

    items=({
     "mist","The dark red mist swirls about you in a threatening manner",
     "mists","The dark red mist swirls about you in a threatening manner",
     "path","The rocky pathway ends suddenly, still nothing evident to hold\n"+
            "it aloft within the swirling mists",
    });

    dest_dir=({
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_back","back");
    }

    search(){
    write("You cannot focus on anything within the swirling mist.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_back() {
write("\nYou leave back into the mist.\n\n");
 this_player()->move_player("back in the swirling mist#players/daranath/qualtor/portal2.c");
return 1;
}

