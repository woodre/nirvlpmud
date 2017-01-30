#include "room.h"
#include "/players/hippo/rvd.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
int closed;
extra_reset() {
  closed=0;
if(!present("machine")) {
  move_object(clone_object("/players/hippo/games/puzzle_room/puzzle_machine"),this_object());
  move_object(clone_object("/players/hippo/games/puzzle_room/p_board"),this_object());
}
}
init()
{ ::init();
  if(this_player()->query_real_name()!="hippo" &&
     this_player()->query_real_name()!="francesco" &&
     closed==1)
     { if(present("hippo") || present("francesco"))
    { move_object(this_player(),"/players/hippo/rooms/nose");
write("The puzzle room is closed right now. New puzzles are being\n"+
"added at the moment.\nSorry about this, it'll be opened in 10 min,\n");
return 1;
    }
  else { closed=0; return 1; }
  }
  else
  { if(this_player()->query_real_name()=="hippo" ||
       this_player()->query_real_name()=="francesco")
    { if(closed==1)
      { write("THE DOOR IS CLOSED, WATCH OUT! (maybe adding puzzles?)\n");}
    }
  }
add_action("close","close");
add_action("open","open");
}
close()
{ if(this_player()->query_real_name()=="hippo" ||
     this_player()->query_real_name()=="francesco" )
  { if(closed==1)
     { write("Door is already closed\n");
          return 1;}
     else {write("Door closed\n");
          closed=1;
          return 1;}
  }
  else {
  write("Stay of the door, bud.\nWho are you anyway?\n");
  return 1;
  }
}
open()
{ if(this_player()->query_real_name()=="hippo" ||
  this_player()->query_real_name()=="francesco")
  { if(closed==1)
    { write("Door opened\n");
      closed=0;
      return 1;}
    else { write("Door is already open\n");
      return 1;}
  }
else {
  write("Stay of the door, bud.\nWho are you anyway?\n");
return 1;
}
}
ONE_EXIT("/players/hippo/rooms/nose.c","leave","The Francippo Puzzle Room",
  "You are in the big Francippo Puzzle Room, also mentioned as the\n"+
  "FPR by puzzlers. In here you can have a nice time solving some\n"+
  "puzzles. I'm sure you like that, because it's a nice way to spend\n"+
  "time and besides it's a way to make money! I bet that sounds\n"+
  "great. And so it is. The best way to make up whether you wanna\n"+
  "puzzle is to look at the puzzle machine in the middle of this room\n"+
  "and follow the description on that machine.\n"+
  "Enjoy yourself, and let me know what you think about it (or about\n"+
  "other things on Nirvana) on the bulletin board. \n"+
  "\nGood Luck!!\n * * * * * * * * * Hippo * * * Francesco * * * * * * * * * \n\n",
         1)
