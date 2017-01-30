inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("al"))  {
MOCO("/players/jenny/80s/mobs/al.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some litter on the ground."+NORM);
set_smell(BOLD+"The grass smells freshly cut."+NORM);
long_desc=
"This is a lovely city park.  The freshly cut grass, huge oak trees,\n"+
"and a few small rolling hills make this place feel very peaceful.\n"+
"There is a big crowd is gathered here for a free concert.  A small\n"+
"stage has been constructed at one end of the park.\n";
short_desc=(HIG+"A city park"+NORM);
items = ({
"grass","Green freshly cut grass",
"litter","Some bottles and cans are laying on the ground",
"trees","These huge oak trees are nearly 100 years old.  They provide lots of shade",
"hills","These small rolling hills give the park a lot of character",
"stage","This small wooden stage is only about a foot above the ground",
"baskets","Brown wicker picnic baskets, which many people have used to bring lunches in",
"crowd","A huge crowd of people are gathered here to listen to the free\n"+
             "performance and have a good time.  Many even brought picnic\n"+
             "baskets",
});
dest_dir = ({
 "/players/jenny/80s/rooms/17","south",
});
}
