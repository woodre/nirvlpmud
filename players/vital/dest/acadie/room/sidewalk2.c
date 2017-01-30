/************************************/
/*    Owner:      Vital@Nirvana     */
/*    Created:    12/18/00          */
/*    Modified:   2/10/01           */
/*    Realm:      Acadie            */
/************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"                    /*color header*/
#include "/players/vital/dest/include/dest.h"

inherit "room/room";

reset(arg) {
  if(!arg) {

set_light(1);

short_desc = "Sidewalk";
long_desc =
  "  The Sidewalk\n\
The sidewalk continues north toward the spaceport and south \n\
on into town. The vegetation is sparse and the sky above is a \n\
pale blue with the slightest trace of ribbon shaped clouds. To \n\
the west is a small sign.\n ";

items = ({
    "sidewalk",
    "The extravagant people movers of the more affluent systems \n\
has been replaced by the simplicity of concrete",
    "concrete",
    "This simple substance has formed the basis for civilization \n\
for the last 2000 years",
    "spaceport",
    "The spaceport is a small, austere building without adornment \n\
or even a sign",
    "town",
    "The town is composed of many smaller buildings, all surrounding \n\
a larger structure",
    "structure",
    "The structure is a wide, tall cylinder with a spherical dome on top",
    "vegetation",
    "The vegetation is well suited to the arctic, tundra-like \n\
conditions that exist all over Acadie. The leaves are small, \n\
the branches are wiry, and the roots are deep",
    "sky",
    "The pale blue sky is virtually cloudless, except for a few small, \n\
wispy ribbons of clouds",
    "clouds",
    "The clouds are sparse, long and thin, like silvery ribbons dancing \n\
high in the sky",
    "sign",
    "The is written in a language that is easily \'read\'"
});

dest_dir = ({
    ACADIE+"room/sidewalk1.c","north",
    ACADIE+"room/sidewalk3.c","south"
  });

  }
}

init() {
    ::init();
    add_action("search_me","search");
    add_action("read_me","read");
}

search_me(str) {
  if(!str) {
    notify_fail("What are trying to search?\n");
    return 0;
  }
  else write("You furiously search the "+str+" but find nothing.\n");
}

read_me(str) {
    if(!str) {
        notify_fail("You have to \'read sign'\ to see what is on it.\n");
        return 0;
    }
    else if(str == "sign"); {
        write("\n");
        write("+------------------------------+\n");
        write("|                              |\n");
        write("| EdmonTown     --> South      |\n");
        write("|                              |\n");
        write("| Spaceport     <-- North      |\n");
        write("|                              |\n");
        write("| CalGar        --^ Southeast  |\n");
        write("|                              |\n");
        write("| Vancou        --v Southwest  |\n");
        write("|                              |\n");
        write("+------------------------------+\n");
    }
    return 1;
}
