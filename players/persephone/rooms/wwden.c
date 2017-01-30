inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!present("werewolf")) {
  move_object(clone_object("players/persephone/monster/wwolf"), TOB);
 }
 if(!arg){
  set_light(0);
  short_desc="Werewolf's Den";
  long_desc="You just made an extremely bad error you walked into the lair of the\n" +
            "most evil and cruel werewolf in all of Nirvana. Lying scattered around\n" +
            "the floor are the bones of his unfurtunate victims perhaps you\n" +
            "make a tactical retreat either west or north if you can.\n" +
            "\n";
  items=({"floor","You know what a floor is however this one has lots of bones on it which\n" +
                 "appears to be covering some sort of geometric design",
         "bones","They appear to be bones of a bipedal creature and some look very\n" +
                 "fresh",
         "walls","These walls are very smooth and judging from the angle of these walls you\n" +
                 "could not climb them",
         "ceiling","Has evil and archaic patterns on it that you fear to examine",
         "design","Nothing special really just a pentagram",
         "patterns","The patterns are actually illustrations of werewolves killing\n" +
                    "villagers",
        });
  dest_dir=({"players/persephone/rooms/junpatd","north",
             "players/persephone/rooms/junpat5","west",
           });
 }
}
