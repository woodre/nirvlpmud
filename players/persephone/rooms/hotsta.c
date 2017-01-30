inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if (!arg) {
  set_light(0);
  short_desc="Second Floor Landing";
  long_desc="You have climbed up to the second floor of the Chelsea Hotel and you\n" +
            "are starting to feel quite puffed the stairs however continue both\n" +
            "up and down. To the south you see another corridor and there is a\n" +
            "sign just above the doorway to the south. The light appears to be much\n" +
            "better down than it is further up and you think that the lightbulb\n" +
             "hanging from the wall must have burnt out\n" +
            "\n";
  items=({"stairs","You know the things you are walking up. Actually they appear to\n" +
                   "made of beautiful white marble inlaid with intricate designs",
          "corridor","It looks like an ordinary hotel corridor to you except the carpet\n" +
                     "appears to be very fine quality",
          "sign","Just one of those signs that tells you the room numbers of the level\n" +
                 "perhaps if you wiped the sign you might be able to read it",
          "light","Yep you guessed it the light globe is blown",
          "marble","It appears to be the finest quality Italian White Marble",
          "designs","These are really stunning the design on the landing looks like\n" +
                    "an idyllic town perhaps it is an illustration of Stormhold in its\n" +
                    "glory days. All the inlays appear to be granite",
          "granite","Fine red Australian granite of the like you have never seen\n" +
                    "before",
          "carpet","Nothing but the finest Berber available made with beautiful\n" +
                   "Tasmanian wool.",
           "wool","Tasmanian wool and therefore you know it is good, perhaps even the\n" +
                 "best available wool",
  });
  dest_dir=({"players/persephone/rooms/hcorr2a","south",
             "players/persephone/rooms/hotstb","up",
             "players/persephone/rooms/hotst1","down",
  });
 }
}
realm() { return "NT"; }
