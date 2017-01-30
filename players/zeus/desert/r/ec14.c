inherit "room/room";

reset(arg){
 if(!arg){

  set_light(0);
  short_desc = "inculta creperum";  /* waste / desert darkness */
  long_desc=
"  This is a very dark, warm place.  Sand is blowing all around you,\n"+
"whipping through the air.  The ground is very dry and cracked,\n"+
"divided up into what look like large squares of brown rock.  To\n"+
"the north, east and south large piles of brown rock protrude from\n"+
"the ground, blocking passage.  A portal of dark blue swirls near\n"+
"the rocks.\n";
  items=({
  "sky",
"The sky seems to be made of many layers of dark gases which flow\n"+
"together as one.  The winds are blowing constantly, making the sky\n"+
"bend and twist.  There is no light coming from anywhere in the sky",
  "ground",
"The ground is hard, flat brown rock.  It is all very dry and scattered\n"+
"with sand that is constantly moving about.  Cracks decorate the ground\n"+
"in many places because of how dry it is",
  "squares",
"The ground almost appears to be divided up by the cracks into square\n"+
"shapes.  The sand makes it hard to descern them a moment later however",
  "cracks",
"Thin cracks run all throughout the ground, diving up the dry ground.\n"+
"They seem to be begging for any kind of moisture, but receive nothing",
  "piles",
"Large piles of brown rock protrude violently from the ground to the\n"+
"north, east and south.  They block passage in those directions",
  "rock",
"Large piles of brown rock protrude violently from the ground to the\n"+
"north, east and south.  They block passage in those directions",
  "rocks",
"Large piles of brown rock protrude violently from the ground to the\n"+
"north, east and south.  They block passage in those directions",
  "portal",
"The blue portal is swirling silently to the east.  There is no light\n"+
"coming from the portal, and it is easy to miss in the darkness",
  });
  dest_dir=({  "/players/zeus/realm/main.c", "portal",
               "/players/zeus/desert/r/ec13.c", "west",  });
 }
}

void init(){
  ::init();
  add_action("portal_dir", "portal");
  add_action("search_cmd", "search");
}

portal_dir(){
  write("\nYou step through the silent blue portal...\n"+
    "Darkness swirls around you...\n\n");
  say(this_player()->query_name()+" steps through the portal.\n");
}

/* For the Inculta Creperum quest */
#include "/players/zeus/desert/r/search.h"

