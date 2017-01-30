inherit "room/room";

#include <ansi.h>
#include "../defs.h"

status dismembered;

reset(arg) {
	 
  if( !present("paper") )
    move_object(clone_object("/players/dragnar/WalkingDead/obj/paper"), this_object());
	
  dismembered = -1;
    
  if(arg) return;
  
  short_desc = "Entrance to King County";
  set_light(1);
  items=({
    "road","The road continues north with the forest stretching out on either side\n\
of the road.  It seems to be the only passable way forward",
    "forest","Dark and foreboding, the trees are so dense there is no way to enter it",
    "pole","An 8 foot high metal pole with a flat platform on top of the pole that\n\
holds the solar panel array",
    "solar panels",HIBLK+"Black "+NORM+" and square, the solar panels use sunlight to power the monitor",
    "ferns","The ferns are a "+GRN+"forest green"+NORM+" and are 10 inches tall",
    "monitor","On the top of the monitor is a power cable that runs to a small set of\n\
solar panels. It is attached to a metal pole that displays the monitor at\n\
eye level. The monitor is covered by weatherproofed Plexiglas to keep out\n\
the rain.  It looks like you could "+GRY+"view display"+NORM+" to see the information\n\
on the monitor",
    "corpse","The corpse is in bad shape. The meat on the bottom half is gone, and the\n\
leg bones stick from the corpse like two "+GRY+"white sticks"+NORM+". The stomach has\n\
been "+RED+"ripped"+NORM+" open and part of the entrails are displayed next to the corpse.\n\
The head has a "+BRED+"massive"+NORM+" wound and there seem to be chunks of flesh missing\n\
from all over the corpse. It is obvious this fellow was brutally\n\
killed. Perhaps this is not the safest corner of the world. You have\n\
a sick sense that you could dismember or mutilate the corpse",
  });
  dest_dir=({
    "/players/dragnar/WalkingDead/rooms/r1","north",
    "/room/sunalley2","leave",
  });
  long_desc=
"This is the entrance to King County Georgia. To the north you can see a\n\
country road that continues north. The ground here is clear, with only\n\
a few ferns growing on it.  To the south a dense, impassable forest\n\
looms up from the clearing.  At the edge of the clearing on the border\n\
of the forest is a partially decomposed "+YEL+"corpse"+NORM+". Even more out of place\n\
than the corpse, there is a large digital monitor that has been erected\n\
in the clearing on a large pole.\n";
}

init() {
	::init();
  add_action("View","view");
  add_action("Dismember","dismember");
  add_action("Dismember","mutilate");
}

Dismember(string str) {
  object guts;
  if (!str || !id(str) || present("walker_guts", this_player()) )
    return 0;
  
  if( dismembered++ < 1 ) {
    guts = clone_object("/players/dragnar/WalkingDead/obj/walker_guts");
    guts->set_time_len( 250 );
    move_object( guts, this_player() );

    write("You dismember the corpse and gag as you pick up the foul smelling "+HBRED+HIY+"innards"+NORM+".\n");
    say(capitalize(this_player()->query_name())+" dismembers the corpse and gags as "+this_player()->query_pronoun()+" picks up the "+HBRED+HIY+"innards"+NORM+".\n");
  }
  else 
    write("This corpse has already been dismembered.\n");
  
  return 1;
}

View( string str ) {
  if( str == "display" ) {
    DEADDM->display(); 
    return 1;
  }
  else
    return 0;
}