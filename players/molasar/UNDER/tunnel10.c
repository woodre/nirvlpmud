
#include "std.h"

int dugout;

reset(arg) {
     if(!arg)
       set_light(0);
     dugout = 0;
}

id(str) { return str == "rocks" || str == "rock"; }

init() {
     add_action("up","up");
     add_action("east","east");
     add_action("dig","dig");
}

up() {
     call_other(this_player(),"move_player",
                    "up#players/molasar/UNDER/tunnel3");
     return 1;
}

east() {
     if(dugout == 0) {
       write("You must dig out the rocks first.\n");
       return 1;
     }
     call_other(this_player(),"move_player",
                    "east#players/molasar/UNDER/tunnel11");
     return 1;
}

dig() {
     if(!present("stonecutter", this_player())) {
       write("You do not have the right instrument for digging.\n");
       return 1;
     } else
     write("After much effort you manage to clear a way through.\n");
     say(capitalize(this_player()->query_name())+" digs throught the rock.\n");
     dugout = 1;
     return 1;
}

short() { return "A cavein"; }

long(str) {
     if(str == "rock" || str == "rocks") {
       if(dugout == 0) {
         write("Numerous rocks piled in front the the passage east.\n");
         return 1;
       } else
       write("Numerous rocks thrown about the passage east.\n");
       return 1;
     }
     if(dugout == 0) {
       write("You have ventured upon part of the tunnel which appears to \n");
       write("have had a recent cavein.  The passage east is blocked by a\n");
       write("wall of rocks.\n");
       write("   There is one obvious exit:  up\n");
       return 1;
     } else
     write("You have ventured upon part of the tunnel which appears to \n");
     write("have had a recent cavein.  Fortunately for you someone has\n");
     write("been along this way and cleared the rocks out for you.\n");
     write("   There are two obvious exits:  east and up\n");
     return 1;
}

