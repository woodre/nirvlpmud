inherit "room/room";
#include "definitions.h"


reset(arg)
{
  if (!arg)
  {
    short_desc="Swamp Entrance";
    long_desc=
"     The ancient stone bridge crosses the narrow river and takes you\n"+
"to what looks like a darkening in the woods. A swamp suddenly presents\n"+
"itself to you as you face south. As you look inside the swamp opening,\n"+
"you gaze into what seems like an entirely different environment. You can\n"+
"only wonder what lies in there.\n"+
"     The vegetation here creeps up on the well-kept path. Large ferns\n"+
"border the trail. Pools of bubbling ooze can be seen every once in\n"+
"a while along the path edges.\n"+
"     In the soft ground, you can make out faint tracks.\n";

    dest_dir=({
CASTLEROOM+"/many_tracks.c","south"  ,
CASTLEROOM+"/green3.c","bridge"  ,
    });

    items=({
"path", "     The path is of light brown dirt",
"pools","     The pools contain ooze",
"trees","     The pine trees stand tall and thin",
"swamp","     The swamp is darker than here",
"ferns","     The ferns have bark at their bases, and 10 feet higher at their\n"+
        "tips, their leaves swirl down like vines",
"ooze", "     The swamp ooze is simply a mixture of decomposed vegetation and\n"+
        "water. Nevertheless, you cringe at the possibility of walking in it",
"tracks","    They are of 4-toed feet, slightly larger than those of humans.\n"+
         "The tracks here lie on hard ground, so they are not easily seen.\n"+
         "Perhaps deeper into the swamp, the mud will present more clues.\n"+
         "They lead off south, into the dark bogs of the swamp",
    });
  }
}
