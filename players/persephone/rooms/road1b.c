inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg) {
  set_light(1);
  short_desc="Dark Road";
  long_desc="This road appears to get darker as you get closer to the center of the\n" +
            "town. In the the far distance to the North you see the harbour while\n" +
            "to the south you see what used to be the town square. On either side\n" +
            "of the road you see buildings. On the building to the west is a sign\n" +
            "while next while against wall of the east building is a bench.  \n";
  items=({"town","The town appears almost desolate",
          "road","You see no movement on this road it is almost as if the\n" +
                 "is deserted",
          "buildings","The buildings are constructed out of sandstone.\n" +
                      "the building to the east has a big steel security door\n" +
                      "while the building to the east has no apparent entrance.\n" +
                      "Both buildings however are boarded up. There is a sign\n" +
                      "building to the west",
          "sign","It is an old and rusted steel sign you will have to clean it\n" +
                 "before you can read it",
          "bench","The bench is broken all of the wooden slats on the seat\n" +
                  "are cracked",
          "slats","On closer inspection it looks that someone has chopped\n" +
                  "them with something like an axe",
          "sky","Clouds are starting to block out the sunlight",
          "sunlight","The sunlight is extremely faint and seems to disappear\n" +
                     "to the south",
          "harbour","You really are to far away to get a good view of the harbour",
          "square","Well it is sort of square shaped",
        });
  dest_dir=({"players/persephone/rooms/road1a","north",
             "players/persephone/rooms/square1","south"
  });
 }
}
realm() { return "NT"; }
