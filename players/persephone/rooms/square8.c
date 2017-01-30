inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
  set_light(0);
 short_desc="Southeast Square";
  long_desc="As you entered this area of the square you could not help but notice\n" +
            "the amount of rubbish that seems to be flying around. The buildings to\n" +
            "the south and the east again appear to be quite run down while to the\n" +
            "North the square appears to get brighter while to the West and Northwest\n" +
            "everything appears to be darker. The building to the east however\n" +
            "does have large flashing sign on it\n\n";
  items=({"rubbish","It is mainly paper and foodscraps",
          "paper","Just scraps of old papers none of the scraps seem to be of\n" +
                  "any interest or value to you",
          "buildings","There is nothing remarkable about their buildings except\n" +
                      "their state of disrepair",
          "square","It is an old town square",
          "ground","The ground is covered in glass perhaps you should be careful",
          "sky","A Storm is definately descending on this once fair town",
          "town","The town seems deserted perhaps the citizens are frightened\n" +
                 "of strangers",
          "storm","There is no storm yet but perhaps you should seek shelter\n" +
                  "far away from the town",
          "citizens","There are definately no citizens around here, not even\n" +
                     "any people",
          "people","What people perhaps tragedy has struck town like maybe\n" +
                   "pirates",
          "pirates","There are no pirates here in fact you see no life at all",
          "sign","Norman's Purveyors of fine elixers of health",
        });
  dest_dir=({"players/persephone/rooms/square7","north",
             "players/persephone/rooms/mid_square","northwest",
             "players/persephone/rooms/square6","west",
             "players/persephone/rooms/normans","east",
  });
 }
}
realm() { return "NT"; }
