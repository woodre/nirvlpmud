inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(arg){
 if(!arg) {
set_light(1);
  short_desc="Town Square";
  long_desc="The light in this part of the square is extremely dim and you can\n" +
            "just make out the major features around you. Perhaps the most interesting\n" +
            "thing you notice is to do with the benches. It is also strange that\n" +
            "you feel as if you are being watched. Another abnormality that you\n" +
            "notice is that there is very little plant life around and only one\n" +
            "large dark tree. To the East you notice many boarded up windows while\n" +
            "the square continues on to the North, South and West. You feel however\n" +
            "North would be the prudent Direction to head in.\n";
  items=({"benches","They appear to be normal benches however, they are all at different\n" +
                    "levels from the ground and indeed none of them seem to be touching\n" +
                    "the ground",
          "windows","You cannot see much of the windows as they are all boarded up",
          "boards","You know wooden boards however you feel that you can remove some\n" +
                   "of them",
          "plants","There aren't any except for some weeds and the big dark tree",
          "tree","This is a very old and large but dead tree at one time you may have\n" +
          "been able to climb it but now it looks far to dangerous",
          "square","You know one of those thing with four equal sides. There used\n" +
                   "to be a market in the square",
          "ground","The ground looks extremely smooth however it is hard to tell if\n" +
                  "it really is because the ground is extremely dark and blends in\n" +
                   "with the light conditions",
          "wall","It is just a brick wall that is part of a large builiding",
          "brick","It looks like an ordinary brick to you",
          "buildings","The buildings are boarded up and seem to be decaying rapidly",
          "sky","Extremely dark, it almost looks as if there is a storm coming no\n" +
               "wonder, you think to yourself, they called the town Stormhold"});
  dest_dir=({"players/persephone/rooms/square5","north",
             "players/persephone/rooms/mid_square","west",
             "players/persephone/rooms/square8","south",
  });
 }
}
realm() { return "NT"; }
