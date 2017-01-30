inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg) {;
  set_light(1);
  short_desc="Town Square";
  long_desc="You appear to have reached the Southwestern end of the square and you\n" +
            "are still feeling extremely uncomfortable. The rubbish blows around\n" +
            "your feet and there is a strong odor coming from the east. To the south\n" +
            "you think you can make out a dark alley and to the West you see a sign\n" +
            "on a building.\n";
  items=({"rubbish","Mainly paper is blowing around but you also see building\n" +
                    "materials and scraps of food",
          "paper","What do you think paper is, wood pulp",
          "tin","It is roofing iron actually and looks to be extremely rusted",
          "tiles","Red brick tiles that are broken",
          "wood","The wood is completely rotten",
          "alley","You definitely could not bring yourself to enter this alley\n" +
                  "the sensation of evil is just to much",
          "feet","You know what your feet look like they are sort of foot shaped",
          "sign","An old sign which you can barely make out",
          "shop","It seems to be a butchers shop but it appears to be closed.\n" +
                 "Wait a second you think you can see some movement in the shop\n" +
                 "you might have to investigate if you dare",
          "square","The square is dark an evil or at least it gives that feeling",
        });
  dest_dir=({"players/persephone/rooms/square2","north",
             "players/persephone/rooms/square6","east",
             "players/persephone/rooms/butshop","west",
             "players/persephone/rooms/mid_square","northeast"
  });
 }
}
realm() { return "NT"; }
