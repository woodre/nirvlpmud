#include "/players/quicksilver/666/include/std.h"

inherit ROOM;

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   set_short("The Grand Ballroom");
   set_long("You enter a gigantic ballroom bathed in light shed from thousands of\n"+
   "candles set about the room.  The ceiling is at least 20 feet above your\n"+
   "head but an elaborate fresco is visible even from this far below.\n"+
   "Tall, pewter-framed mirrors line the walls on all sides making the room\n"+
   "seem even bigger than it actually is.  There is a small raised platform\n"+
   "at one end of the room, where a group of minstrels are playing tunes.\n"+
   "There is a large oak banquet table at the other side of the room where\n"+
   "refreshments are being served.  The music of the minstrels fills the room\n"+
   "and you feel the urge to dance.");
   add_item("fresco", "Reminicent of the great fresco on the ceiling of the Cistine Chapel,\n"+
                      "scenes of epic proportions are given life 25 feet above the floor in this\n"+
                      "ballroom.  The images flow together to form a story of love and\n"+
                      "friendship throughout the ages.  It makes you want to be a part of it.");
   add_item("ceiling", "Reminicent of the great fresco on the ceiling of the Cistine Chapel,\n"+
                       "scenes of epic proportions are given life 25 feet above the floor in this\n"+
                       "ballroom.  The images flow together to form a story of love and\n"+
                       "friendship throughout the ages.  It makes you want to be a part of it.");
   add_item("village", "You see yourself reflected over and over in reflection after reflection,\n"+
                       "framed over and over in the same intricate pewter, with the same ballroom\n"+
                       "behind you over and over again.");
   add_item("platform", "The music is lovely and the minstrels even lovelier.  Rosencrantz is\n"+
                        "playing the lute, Guildenstern, the pipe, and Mopsa and Dorcas sing\n"+
                        "lyrics that float beautifully over the top of it all, piercing you to\n"+
                        "your soul.");
   add_item("band", "The music is lovely and the minstrels even lovelier.  Rosencrantz is\n"+
                    "playing the lute, Guildenstern, the pipe, and Mopsa and Dorcas sing\n"+
                    "lyrics that float beautifully over the top of it all, piercing you to\n"+
                    "your soul.");
   add_item("mirror", "You see yourself reflected over and over in reflection after reflection,\n"+
                      "framed over and over in the same intricate pewter, with the same ballroom\n"+
                      "behind you over and over again.");
   add_item("mirrors", "You see yourself reflected over and over in reflection after reflection,\n"+
                       "framed over and over in the same intricate pewter, with the same ballroom\n"+
                       "behind you over and over again.");
   add_item("walls", "You see yourself reflected over and over in reflection after reflection,\n"+
                     "framed over and over in the same intricate pewter, with the same ballroom\n"+
                     "behind you over and over again.");
   add_item("wall", "You see yourself reflected over and over in reflection after reflection,\n"+
                    "framed over and over in the same intricate pewter, with the same ballroom\n"+
                    "behind you over and over again.");
   add_exit("room/church", "church");
   add_exit("players/quicksilver/closed/wedding/r/cathedral",  "cathedral");
}

init() {
   ::init();
}

