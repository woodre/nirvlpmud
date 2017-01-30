inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("dancer")) {
MOCO("/players/jenny/80s/mobs/dancer.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/dancer.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/dancer.c"),this_object()); }

if(!present("dancer 3") && !present("dancer 2") && present("dancer"))  {
MOCO("/players/jenny/80s/mobs/dancer.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/dancer.c"),this_object()); }

if(!present("dancer 3") && present("dancer 2"))  {
MOCO("/players/jenny/80s/mobs/dancer.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear lots of different music all blurred together."+NORM);
long_desc=
"This is a lively city street.  The pavement looks pretty old.  There are\n"+
"a few potholes which could stand to be fixed.  The sidewalks on each\n"+
"side of the street are bustling with pedestrian activity.  This part of\n"+
"town is clearly the place to be.  There are nightclubs on both sides\n"+
"of the street.\n";
short_desc=(WHT+"Hair-spray drive"+NORM);
items = ({
"street","A lively city street.  The pavement looks pretty worn",
"potholes","Holes worn into the pavement after years of errosion",
"pavement","Grey concrete pavement.  It has a few potholes",
"sidewalks","There are cement sidewalks on each side of the street.  They\n"+
            "are bustling with pedestrian activity",
"sidewalk","There are cement sidewalks on each side of the street.  They\n"+
            "are bustling with pedestrian activity",
"pedestrians","There are lots of pedestrians.  Some are just standing around,\n"+
                     "others are coming and going.  Everyone seems to be having a\n"+
                     "good time though",
"nightclubs","Crowded nightclubs are on each side of the street.  These brick\n"+
                      "buildings have no windows facing the street",
});
dest_dir = ({
 "/players/jenny/80s/rooms/8","north",
 "/players/jenny/80s/rooms/20","south",
 "/players/jenny/80s/rooms/15","west",
 "/players/jenny/80s/rooms/17","east",
});
}
