inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("billy idol"))  {
MOCO("/players/jenny/80s/mobs/idol.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_smell(BOLD+"The smell is an intoxicating mix of beer and cheap perfume."+NORM);
set_listen(BOLD+"Billy Idol is performing."+NORM);
long_desc=
"This is one of the more risque nightclubs in town.  It is overflowing\n"+
"with people, none of whom you'd want to take home to meet mother.\n"+
"The lighting is dim, but you can clearly see a stage near the back of\n"+    
"the room, and a bar over to the side.  Suspended from the ceiling are\n"+
"two large steel cages, with a girl dancing in each one.\n";
short_desc=(BOLD+BLK+"A niteclub"+NORM);
items = ({
"stage","This is a modest wooden stage used by the performers",
"ceiling","The ceiling is about 40 feet high. Two steel cages, with girls in them,\n"+
              "are suspended from it",
"people","Most of these people look kind of punkish.  Many of the women have\n"+
               "purple or blue streaks in their hair, and many of the men are dressed\n"+
                "in leather and have spiked mohawks",
"bar","A long wooden bar with lots of people crowded around it",
"cages","Two large steel cages that are suspended from the ceiling.  Each one\n"+
              "has a girl, wearing a tight leather miniskirt, dancing in it",
});
dest_dir = ({
 "/players/jenny/80s/rooms/16","exit",
});
}
