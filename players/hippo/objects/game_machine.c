#include "/players/hippo/rvd.h"
id(str)
{ return (str=="machine"); }
short() { return ("game machine"); }
long() { write("This is Hippo's game machine.\n"+
    "Beware: from now on, games cost 50 coins each!\n"+
    "You can get a game by pushing a button. Available games are:\n"+
    "\t1. BlackJack.\n"+
    "\t2. Twentyone.\n"+
    "\t3. Oware.\n"+
    "");
   return 1;
   }
drop() { return 0; }
get() { return 0; }

init()
{  add_action("push","push"); 
}
push(str)
{
int amount;
   if(str=="1")
   {  write("You receive BlackJack cards\n");
  move_object(clone_object("/players/hippo/games/blackjack.c"),this_player());
if(QMON>50){amount=-50;AMON;}
   }
else { if(str=="2")
      { write("You receive Twentyone cards.\n");
        move_object(clone_object("/players/hippo/games/twentyone.c"),this_player());
if(QMON>50){amount=-50;AMON;}
      }
   else 
  { if(str=="3")
    { write("You receive Oware.\n");
      move_object(clone_object("/players/hippo/games/oware.c"),this_player());
if(QMON>50){amount=-50;AMON;}
    }
else {if(str=="99" && CTP=="Francesco")
  { write("You receive the flyer-note.\n");
move_object(clone_object("/players/hippo/games/puzzle_note.c"),this_player());
}
else
   { write("Push a button number.\n");
   }
  }
}
  }
   return 1;
}
