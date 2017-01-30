#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("wolf")) 
  move_object(clone_object("players/softly/winter/wwolf"),this_object());

  if(arg) return;
set_light(1);

short_desc = "Outside of a Cottage";
long_desc ="  The blindingly bright light makes it hard to see.  A cottage\n"+
           "otherwise normal in every way, appears to be completely made of\n"+
           "ice.  A picket fence surrounds it and a small porch seems to invite\n"+
           "visitors.  Although smoke rises from a chimney, no melting can be\n"+
           "seen.  The front door stands slightly ajar.  To the west is a vast\n"+
           "frozen lake.\n";

items = ({
  "light", "A sudden emergence into blindingly bright light assails\n"+
           "the senses",
  "cottage", "This might be a cottage from a fairy tale were it not\n"+
           "made from ice.  It has a front porch, two small windows,\n"+
           "and an inviting door that is slightly ajar",
  "fence","A small picket fence surrounds the cottage.  Frozen flowers\n"+
          "rigid with cold dot the yard",
  "porch","A small covered porch surrounded by a tiny railing would look\n"+
          "ordinary were it not made from ice.  A very shiny spot near\n"+
          "the door looks as though an animal had slept there often",
  "door", "Although made from ice, the door seems ordinary in every other\n"+
          "way.  It stands slightly ajar, as if to allow easy entry",

  });

dest_dir = ({
  "/players/softly/winter/rooms/pond17.c","northeast",
  "/players/softly/winter/rooms/pond8.c","west",
  "/players/softly/winter/rooms/pond19.c","enter",
  });
}
