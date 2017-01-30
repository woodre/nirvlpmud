/* pchelp - Help file for the Player Channel */

#include <ansi.h>

int pchelp(){
   write(HIW+"\n"+
      "     ______________________________________________________________   \n"+
      "   / `                                                             `  \n"+
      "   |  )               --==  Player Channel  ==--                   |  \n"+
      "   |\/_____________________________________________________________/  \n"+
      "   |                                                              |   \n"+
      "   |                                                              |   \n"+
      "   |  pc <message>       Talk on the player channel               |   \n"+
      "   |  pe <message>       Emote on the player channel              |   \n"+
      "   |                     (Suggested by Tristan)                   |   \n"+
      "   |  pchelp             Prints out this help file                |   \n"+
      "   |  pcwho              Shows who's on the player channel        |   \n"+
      "   |  pcdrop             Drops (leaves) then channel              |   \n"+
      "   |                     (Rumplemintz will have to reinstate you) |   \n"+
      "   |  pcrenew            Renew your status (get new copy)         |   \n"+
      "   |  pcshush            Tells the Player Channel to shut up!     |   \n"+
      "   |                     (suggested by Stiletto)                  |   \n"+
      "   |  pcnews             News on the Player Channel (updates)     |   \n"+
      "   |   *  * * *  *   *   *  * * *  *   *   *  * * *  *   *   *  * |   \n"+
      "   |  If you have any questions, or suggestions on what you'd     |   \n"+
      "   |  like to see added to the Player Channel, simply mail me.    |   \n"+
      "   |                     --Rumplemintz                            |   \n"+
      " /`|                                                              |   \n"+
      "|  |                                                              |   \n"+
      " `/_______________________________________________________________/   \n"+
      "\n"+NORM);
   return 1;
}
