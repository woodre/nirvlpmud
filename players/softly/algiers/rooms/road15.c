#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/room";

reset(arg){
  if(!present("stfolk")){ 
    move_object(clone_object("players/softly/algiers/mobs/folks.c"),this_object());
  }

  if(arg) return;
  set_light(1);

  short_desc = "Algiers";
  long_desc ="\n\
  A broad dirt road which runs through the center of town\n\
stretches far north from its end in the south of Algiers.\n\
A smaller road intersects from the east.  North a number\n\
of small structures clutter the sides of the road making up\n\
the commercial center of town.  To the west a wooden building\n\
with a largish glass window looks onto the road.  The dirty\n\
white building stands in contrast to a large golden sign that\n\
has been painted on the glass.\n";

  items = ({
    "road",
    "The brown earthen road is very dusty",
    "town",
    "Small buildings dot the sides of the road.  A few are\n\
visible in the distance, one with a tall steeple.",
    "structures",
    "Small buildings of many colors make up the town center",
    "building",
    "The white clapboard building has not been painted in\n\
a very very long time.",
    "window",
    "Next to a creaking and open door is a large picture\n\
window with a sign painted on in curved gold letters",
    "glass",
    "The window is made of glass",
    "sign",
    "A golden sign has been painted on the window in large\n\
letters.  It reads:\n\n"+YEL+
"          Nicholas Earl Boudreaux\n"+
"             Private Detective\n"+NORM+"",
});

  dest_dir = ({
    "/players/softly/algiers/rooms/nicks.c","west",
    "/players/softly/algiers/rooms/road16.c","east",
    "/players/softly/algiers/rooms/road14.c","north",
  });
}
