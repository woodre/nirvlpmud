inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset (arg){
 if (arg) return;
  set_light(1);
  short_desc="Broadway Ave";
  long_desc="You are on the once famed and now deserted street of Broadway all the\n" +
            "lights that used to shine so brightly are now just a dim memory of the\n" +
            "past. Also you notice that in at least this part the road is in need\n" +
            "of repair as there are many potholes. On each side of Broadway you see\n" +
            "many old theatres and Nightclubs but they all appear to be boarded up\n" +
            "now however some of the signs still seem to be be functioning.\n";
  items=({"theatres","To the west you see Carnegie Hall and the east Shapiro's Theatre\n" +
                     "just to name two of them many of these theatres were once the \n" +
                     "talk of all of Igor. Unfortunately the are all boarded up and\n" +
                     "impenetrable",
          "nightclubs","To the east is the old Cotton Club and on the west is the\n" +
                       "old Wolfman Club unfortunately they are long closed down",
          "lights","They are, or should I say were, neon lights but many of\n" +
                   "them now appear to be smashed and those that are not do\n" +
                   "not seem to work except for one set on the sign over the\n" +
                   "Carnegegie Hall",
          "signs","You cannot make out any of the signs except for the one over the\n" +
                  "Carnegie Hall",
          "potholes","They are just holes in the road",
          "road","It is in a bad state of disrepair at this point you only hope\n" +
                 "that is is better condition further on",
          "broadway","This once famous street provided igor with most of its\n" +
                     "artistic entertainment",
          "sky","The sky is glorious especially in this specific shade of green",
          "street","The street is empty",
        }); 

  dest_dir=({"players/persephone/rooms/harbc","north",
             "players/persephone/rooms/road3b","south"
  });
}
realm() { return "NT"; }
