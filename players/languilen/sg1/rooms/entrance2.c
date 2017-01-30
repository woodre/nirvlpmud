/*
 *
 */
#include "../paths.h"
#include "/players/languilen/langdefs.h"
#include "/players/languilen/closed/ansi.h"
inherit "room/room";

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "A Hallway";
     long_desc =
"    An elevator with huge doors and a single button end a long hallway,\n\
institutional looking hallway.  A double row of flourescent white lights do nothing to brighten the look\n\
of the gunmetal walls.  The whole place seems to vibrate slightly and a\n\
faint, deep thrumming noise gives the impression of underground machinery.\n\
Here an elevator with huge doors and a single button stan
The hallway goes south to an intersection  and

     "    This is just inside the secret underground installation that\n\
is the home of 'Project Bluebook'.  Deep under chyanne mountain it is\n\
Just south are the closed doors that lead to the surface, they remain\n\
sealed shut most of the time.  A guard post, really a desk, can be seen\n\
at an intersection in the hall ahead to the north.\n";

     This short section of hallway runs from a hermeticly sealed door\n\
to the intersection just up the hall.
Portions of the celieng are luminus and bright enough to lite the hall.
The smooth gunmetal walls vibrate slightly

     One huge metal door that looks like it belongs on a vault dead\n\
ends this short section of hall.  Portions of the celieng are luminus\n\
and bright enough to lite the way.  The smooth gunmetal walls vibrate\n\
softly and one has some writing on it in big block letters.\n";


     items = ({
     "door","This solid piece of metal looks impenitrable.  There are no visible\n\
means of opening it.",
     "portions","Spaced perefectly equidistant the light shed is perfectly white.",
     "celing","Pocked with strange white light.",
     "wall","hmm"
     });

     dest_dir = ({
     ROOM + "hall1.c","south",
});

}
