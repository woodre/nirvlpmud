#include "std.h"


/*



*/


THREE_EXIT("players/rich/quest/hall1.c", "north",
           "players/rich/lower/atrans.c", "out",
   "players/rich/quest/sickbay1.c", "south",
     "a room",
           "This is the main room on the first level of\n" +
           "your quest.The object is to make it through\n" +
           "the two levels,find the Ultimate Trekkie\n" +

           "that is carrying the tape of the lost episodes\n" +
           "of star trek.Return this tape to the jeffries tube.\n" +
           "To get healed go south to sickbay.\n" +
           "If you are not an upper level player it would be wise to turn around.\n" +
           "Remember that this is a maze and all is not as it seems\n" ,
            1)
realm(){return "enterprise";}
