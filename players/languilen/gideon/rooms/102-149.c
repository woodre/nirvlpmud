#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Visitors Center";
     long_desc =
"    In the center of this quaint and colorfull room a circular distribution\n\
stand holds some brochures advertizing the great sights and attractions of the\n\
city.  The egress to the building lies to the southeast\n";

     items = ({
  "stand","a sturdy device firmly affixed in the center of the room",
  "brochures","There are a few different ones to choose from.  Read\n\
the 'mall' or the world renown 'bazzar' brochure",
});

     dest_dir = ({
	AREA+"101-150.c","southeast",
});

}

init(){
     ::init();
     add_action("read","read");
}

read(str){
     if(!str){
        notify_fail("What brochure would you like to read?\n");
        return 0;
     }
     if(str=="funhouse"){
        write("You read the one about the funhouse.\n\n");
        funhouse();
        return 1;
     }
     if(str=="stadium"){
        write("You read about the stadium.\n\n");
        stadium();
        return 1;
     }
     notify_fail("There's not a brochure about that.\n");
     return 0;
}

funhouse(){
     write("\n\
    Be the first through the mirror maze and you can dunk your friends\n\
in the Funhouse Dunk Tank!  Take on all challengers to become KING OF THE\n\
HILL!  Sharpen your skills at the shooting gallery or win great prizes\n\
from the crane.  Whatever you do, you're bound to work up a thirst so\n\
be sure to visit the snackbar for great food and drinks.\n\
    Many of the cities children come here to play during thier free\n\
hours and, if you're a newbie, you can too!  The Funhouse offers hours\n\
of enjoyment for those still young enough to enter.\n");
}
stadium(){
     write("\n\
    The Stadium is a huge open theatre with seating all around.  Built by\n\
the wizards of the Good Ol' Days, it provides top notch entertainment for\n\
the populace.  The game of baseball is played there by the greatest players\n\
that ever lived and they are sure to provide a show.  These players are not\n\
simulacrum but are the real players brought here by the G.O.D. through time,\n\
space and dimention just for you.  So don't miss the all-time all-star game!\n");
}
