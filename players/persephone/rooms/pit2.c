inherit "/players/persephone/closed/thingys.c";
#include "/players/persephone/rooms.h"
reset(int arg){
 if (arg) return;
  set_light(1);
  short_desc="Wet Tunnel";
  long_desc="You are in an extremely damp tunnel in fact that water\n" +
            "is up to your knees and very cold. The tunnel continues\n" +
            "both east and west while there is a small crack in the north\n" +
            "wall.\n" +
            "\n";
  items=({"tunnel","You presume it is a service tunnel to the old drainage\n" +
                   "system of Stormhold",
          "stormhold","You cannot see stormhold from in the tunnle",
          "water","The water has a Purplish tinge to it and smells\n" +
                  "extremely stale with scum floating on it",
          "crack","You think that you could just about enter the crack\n" +
                  "but there is an evil aura coming from that direction",
          "scum","This stuff is revolting but you cannot really identify\n" +
                 "what the scum is",
        });
  dest_dir=({"players/persephone/rooms/pit1","west",
             "players/persephone/rooms/pit3","east",
           });
}
init(){
 ::init();
 add_action("enter1","enter");
 add_action("enter1","squeeze");
 add_action("enter1","in");
}
enter1(str){
 if(str=="crack"){
  write("You just manage to squeeze through a tight crack and you\n" +
        "hope it is your only tight squeeze.\n");
  TPL->move_player("entering through a small crack in the wall north#"+"players/persephone/rooms/ppelai");
  return 1;
 }
 write("You try enter the 100 meters freestyle competition\n");
 say(CAPTPLNM + " gets ready to swim the hundred meters.\n");
 return 1;
}
