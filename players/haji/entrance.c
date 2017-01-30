#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
  extra_init() {
   add_action("look","look");
   add_action("look","exa");
   add_action("look","look at");
   add_action("look","l");
   }
FOUR_EXIT("players/haji/e1", "north",
          "players/haji/king/ent.c", "west",
          "players/haji/harem/ent.c", "east",
          "players/haji/town/ent.c" ,"south",
 "Main Entrance to Haji`s Land of Wonder.",
    "This is the main entrance to Haji's Land of Wonder.\n" +
    "There are currently three levels to the land.\n" +
    "They are town, castle, and harem.\n" +
    "The town is to the south, the king's castle is to\n" +
    "the west, and the harem is to the east.\n" +
    "For healing you can either go to the pub or magic shop.\n" +
    "To buy weapons and other misc items go to the various shops\n" +
    "in the town, or you can go visit the girls in the harem.\n" +
    "Finally, if you would like\n"+
    "to find out stats on a monster/player go see the seer\n" +
    "that is found in the castle.\n",1)
realm() {return "harem";}
look(str) {
   if (str=="south"||str=="town"||str=="s") {
      write("You see a forest to the south,and off\n");
      write("in the distance you see a town.\n");
      return 1;
    }
    if (str=="north"||str=="n") {
       write("You see the entrance to the Haji's Land of Wonder to the north.\n");
       return 1;
      }
    if (str=="east"||str=="harem"||str=="e") {
       write("To the east you hear the tinkling of bells.\n");
       write("And you see the entrance to the harem.\n");
       return 1;
      }
    if(str=="west"||str=="castle"||str=="w") {
       write("To the west you see a castle,the castle\n");
       write("is surrounded by a moat.\n");
       return 1;
     }
     if(str==0) {
       call_other(this_player(),"move_player","#players/haji/entrance.c");
       return 1;
  }
  return 1;
  }
