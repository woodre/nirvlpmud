inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("agent"))  {
MOCO("/players/jenny/80s/mobs/agent2.c"),this_object()); }
if(!present("nancy reagan"))  {
MOCO("/players/jenny/80s/mobs/nancy.c"),this_object()); }
if(!present("ronald reagan"))  {
MOCO("/players/jenny/80s/mobs/reagan.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_smell(BOLD+"You can smell the delicious food being prepared in the kitchen."+NORM);
long_desc=
"This luxurious home belongs to a wealthy contributor to the Republican\n"+
"party.  The dining room is very large and impressive.  The hardwood\n"+
"floor is a thing of beauty, and the walls are decorated with tasteful\n"+
"works of art.  The dining room table is very long, and there are about\n"+
"100 places set for the $10,000 per plate fund-raiser that will be starting\n"+
"soon.  A large crystal chandelier hangs overheard, illuminating the\n"+
"room with just the right amount of light.\n";
short_desc=(HIW+BOLD+"Dining Room"+NORM);
items = ({
"table","This solid oak dining room table is extremely long.  It has about\n"+
              "100 places set on it",
"art","Beautiful paintings decorate the wall.  All of them are works\n"+
"of famous artists",
"floor","The floor is made of hardwood.  It has a dark finish",
"walls","The walls are painted an off-white color, and are trimmed with\n"+
              "oak paneling.  They are decorated with tasteful works of art",
"balcony","A balcony which overlooks the entrance hallway",
"chandelier","A beautiful crystal chandelier which hangs from the ceiling",
});
dest_dir = ({
 "/players/jenny/80s/rooms/5","east",
 "/players/jenny/80s/rooms/3","out",
});
}
