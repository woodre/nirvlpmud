inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("tammy baker"))  {
MOCO("/players/jenny/80s/mobs/tbaker.c"),this_object()); }
if(!present("jim baker"))  {
MOCO("/players/jenny/80s/mobs/jbaker.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear gospel music."+NORM);
long_desc=
"This luxurious home belongs to Jim and Tammy Baker.  The living\n"+
"room is immaculately decorated.  The plush white carpet is so soft,\n"+
"it feels like walking on clouds.  All of the pieces of furniture\n"+
"in the room are expensive antiques.  While looking at the big\n"+
"screen television, an oil painting above it catches your eye.  One\n"+
"wonders how a simple minister can afford to live like this.\n";
short_desc=(HIY+BOLD+"The Baker's House"+NORM);
items = ({
"furniture","This dark furniture is made in the early American style.  It\n"+
                   "made of ebony, and has many hand carved decorations",
"carpet","Thick white carpet, which covers the entire living room floor.  It is very soft",
"television","This is a big screen RCA television",
"painting","A portrait of Jesus",
});
dest_dir = ({
 "/players/jenny/80s/rooms/2","out",
});
}
