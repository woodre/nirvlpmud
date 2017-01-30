inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
 reset(arg){
 if(!arg){
 set_light(2);
  short_desc="Police Station";
  long_desc="This is what appears to be the old police station of Stormhold. The\n" +
            "station still probably looks much the same as when this was a law abiding\n" +
            "town. On the desk over in the corner you see what must have been the\n" +
            "police diary. What surprises you most is that there appears to be very\n" +
            "little dust in this room. To your north is a hall way and you cannot\n" +
            "help but wonder lies down the corridor.\n";
  items=({"station","The station is quite peaceful and quiet to quiet really.\n" +
                    "The furniture in here while not elegant is functional and\n" +
                    "includes the sargeant's desk, a counter and some chairs",
          "desk","This is the old sargeant's desk on it is some paperwork\n" +
                 "and the station diary",
          "chairs","The wooden chairs look functional if nothing else,\n" +
                   "and you get the strongest urge to sit on one of them",
          "counter","A wooden counter with a tray sitting on it",
          "tray","The reports tray it is one of those wire trays\n" +
                 "but unfortunately empty",
          "diary","The station diary none of the arrests seem recent\n" +
                  "wait here is one that seems interesting perhaps\n" +
                  "you should read the diary",
          "paperwork","You guessed it the paperwork is in triplicate",
          "wall","The wall is totally white and is covered with wanted\n" +
                 "posters from all over igor",
          "posters","These are just ordinary posters wait a second\n" +
                    "poster might be of interest perhaps you should read it",
          "corridor","The corridor is beckoning you to follow it",
          "ceiling","The cieling is white with one of those big fans hanging\n" +
                    "from it",
          "fan","Crumb's the fan is not working and you cannot see a switch\n" +
                "to activate it",
          "floor","The floor appears to be concrete. Sensible for a prison\n" +
                  "or police station ain't it",
        });
  dest_dir=({"players/persephone/rooms/pol_stat2","north",
             "players/persephone/rooms/square5","out",
  });
 }
}
realm() { return "NT"; }
