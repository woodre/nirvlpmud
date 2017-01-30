inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("mr t"))  {
MOCO("/players/jenny/80s/mobs/t.c"),this_object()); }
    if(arg) return;
    set_light(0);
set_smell(BOLD+"It smells like rotting garbage."+NORM);
set_search(BOLD+"You search through the dumpsters, but find nothing worthwhile."+NORM);
long_desc=
"This is a narrow alley which runs between two buildings.  It is\n"+
"made of gravel and dirt, and used mostly for garbage pickup.\n"+
"There are a few dumpsters, and plenty of garbage cans on the\n"+
"sides of the alley.  The walls of the buildings are spray painted\n"+
"with graffiti.\n";
short_desc=(BOLD+"A narrow alley"+NORM);
items = ({
"buildings","This alley is between two brick buildings.  Their walls are\n"+
                   "spray painted with graffiti",
"graffiti","Words spray painted on the wall.  The usual garbage",
"walls","The brick walls of the buildings lining the alley.  They are defiled\n"+
              "with graffiti",
"dumpsters","Big blue dumpsters.  God they smell awful",
"cans","Silver metal garbage cans",
});
dest_dir = ({
 "/players/jenny/80s/rooms/10","out",
});
}
