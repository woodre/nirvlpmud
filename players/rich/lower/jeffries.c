#include "std.h"
#undef EXTRA_INIT
         
#define EXTRA_INIT extra_init();
extra_init(){
  add_action("toss","toss");
}
 toss(str){
   if (str=="videotape" || str=="video tape"){
      if (!present("trekkie",this_player())){
         write("Nice try bonehead!!!no solvee the questee!!\n");
         return 1;
      }
   write("You fling the tape HARD!!!\n");
   write("You hear the theme from star trek building up in the background\n");
   write("Congratulations you are now a mighty trekkie you have solved your quest!!\n");
   call_other(this_player(),"set_quest","trekkie");
   destruct(present("trekkie",this_player()));
}
   return 1;
}


/*



*/


TWO_EXIT("players/rich/lower/hall5d.c", "east",
   "players/rich/lower/turbo2d.c", "west",
   "a jeffries tube",
           "This is a jeffries tube. to the east is a room, " +
           "to the west \n" +
           "a turbolift. \n",
           1)
realm(){return "enterprise";}
