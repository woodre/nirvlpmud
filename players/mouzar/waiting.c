 
/*from the persephone*/
inherit "room/room";
#include "/players/mouzar/misc/roomt.h"   
reset(arg){
 if(!arg){
  short_desc="Waiting room";
  long_desc="This is where you come if you want to talk to Mouzar.  He is a busy person\n"+
             "and doesn't like for people to just walk in when he is busy.  So he sent\n"+
             "you here till he has time to see you or he might have just forgot to turn\n"+
             "off his shields again.  This is a plain room with a couple of chairs.  He\n"+
             "hasn't found a way for the mail man to get up here so he doesn't have \n"+
             "magizines for you to read while you wait.\n";
  items=({"window","You have a great view of nirvana from here.Everyone looks like little\n"+
                   "ants from this view.  You realize that you are high on a mountain range\n"+ 
                   "as you look out the window.",
          "portal","This portal will bring you to the church if entered",
          "chair","A nice but plain chair.",
        });
  dest_dir=({"players/mouzar/workroom","up",
             "room/church","portal",});
 }
}
