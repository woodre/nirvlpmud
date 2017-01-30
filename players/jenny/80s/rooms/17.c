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
"town is clearly the place to be.  A beautiful park is to the north, and\n"+
"the huge arena to the south is impossible to ignore.\n";
short_desc=(WHT+"Hair-spray drive"+NORM);
items = ({
"trees","Large oak trees",
"street","A lively city street.  The pavement looks pretty worn",
"potholes","Holes worn into the pavement after years of errosion",
"pavement","Grey concrete pavement.  It has a few potholes",
"sidewalks","There are cement sidewalks on each side of the street.  They\n"+
            "are bustling with pedestrian activity",
"sidewalk","There are cement sidewalks on each side of the street.  They\n"+
            "are bustling with pedestrian activity",
"people","A large crowd of people appeared to be gathered for something",
"pedestrians","There are lots of pedestrians.  Some are just standing around,\n"+
                     "others are coming and going.  Everyone seems to be having a\n"+
                     "good time though",
"park","This is a big park filled with grass and trees.  A lot of people are currently\n"+
                      "gathered in it",
"arena","A huge arena can be seen to the south.  It is used for sporting events\n"+
              "and concerts",
});
dest_dir = ({
 "/players/jenny/80s/rooms/9","north",
 "/players/jenny/80s/rooms/21","south",
 "/players/jenny/80s/rooms/16","west",
});
}
