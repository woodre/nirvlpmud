#include "/obj/clean.c"
#include "ex.h"
reset(arg) {
   if(arg) return;
   set_light(1);
}
   short() { return "Welch Avenue [n,s]"; }
   long() {
      write("  The noises of beer drinking and rough-housing increase\n"+
            "as you enter this part of Welch Avenue.  To the west is a\n"+
            "stairway that leads up to a small shop.  Hanging from above\n"+
            "the stairway is a fancy sign.  East of Welch is a small bar.\n"+
            "That is where the noises are coming from.\n");
      if(present("crowd")){
         write("A large crowd has gathered outside the bar and is very\n"+
               "noisy and rude to passerbys.\n");}
      write("     There are four obvious exits: up, east, south, north\n");
   }
init() {
   add_action("Bar","east");
   add_action("Gameden","up");
   add_action("Nwelch","north");
   add_action("Welch","south");
   add_action("Sign","look");
   add_action("Sign","l");
}
up() {
   tp->move_player("up#players/dersharp/joint/quest/gameden");
   return 1;
}
east() {
   tp->move_player("east#players/dersharp/joint/quest/roost");
   return 1;
}
Nwelch() {
   tp->move_player("north#players/dersharp/joint/quest/nwelch");
   return 1;
}
Welch() {
   tp->move_player("south#players/dersharp/joint/quest/welch");
   return 1;
}
Sign(arg) {
   if(arg=="at sign" || arg=="sign") {
      write("------------------------\n"+
            "| Come on up and enjoy |\n"+
            "| the latest in games! |\n"+
            "------------------------\n");
      return 1;
   }
   return 1;
}
