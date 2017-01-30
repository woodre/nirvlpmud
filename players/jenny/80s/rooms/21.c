inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("michael jackson"))  {
MOCO("/players/jenny/80s/mobs/jackson.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_listen(BOLD+"The crowd is chanting: "+RED+"THRILLER THRILLER."+NORM);
long_desc=
"This is a large arena used for sporting events and concerts.  It\n"+
"seats around 15,000 people.  Every seat appears to be filled for\n"+
"a Michael Jackson concert.  You happen to be standing on a\n"+
"huge stage in the middle of the arena.  It is constructed of wood,\n"+
"and is about seventy feet long, and forty feet wide.  Pyrotechnics\n"+
"are set up in several different places.\n";
short_desc=(HIB+"An arena"+NORM);
items = ({
"pyrotechnics","These are machines which shoot fire up into the air.  They are\n"+
                         "used to enhance the show.  It would not be a good idea to be\n"+
                        "near them when they go off",
"arena","You look up at the rest of the arena.  Fifteen thousand eyes are\n"+
              "staring down at you",
"stage","This huge wooden stage is about seventy feet long and forty\n"+
              "feet wide",
});
dest_dir = ({
 "/players/jenny/80s/rooms/17","out",
});
}
