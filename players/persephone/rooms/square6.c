inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (!arg) {
 set_light(0);
  short_desc="Town Square";
  long_desc="Remarkably the square is still extremely dark and you can see no relief\n" +
            "in any direction it is almost as if you should have left Storhold when\n" +
            "you had the chance to.  It now feels as if the town is closing around\n"  +
            "you. There appears more rubbish than ever flying around here and there\n" +
            "is an extremely uninviting aroma coming from the store to the South.\n";
  items=({"store","The village store which is open. There is a lot of junk around the\n" +
                  "entrance. There is a sign just above the entrance",
          "sign","The sign looks freshly painted with black lettering on a black background",
          "rubbish","This is just rubbish and there is definately nothing of value in it",
          "square","The square is totally empty you can see no movement anywhere",
          "stormhold","You cannot see all of Stormhold from here but it feels evil.\n" +
                      "Perhaps you should explore the whole town",
          "sky","You got to be joking it is so dark you think you must be in a blackhole",
          "ground","The ground is covered with layers of rubbish and and bugs are\n" +
                   "all around",
          "aroma","You cannot see the aroma perhaps you should try smelling",
          "bugs","Oh nothing really just some of the biggest cockroaches\n" +
                 "you have ever seen",
        });
  dest_dir=({"players/persephone/rooms/mid_square","north",
             "players/persephone/rooms/square4","west",
             "players/persephone/rooms/shopa","south",
             "players/persephone/rooms/square8","east"
  });
 }
}
realm() { return "NT"; }
