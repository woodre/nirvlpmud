#include "defs.h"

inherit MNDROOM;

int peeps;

void reset(int arg) 
{
  if(arg) return;
  short_desc=RED+"The Myrmidar Mound"+NORM;
  long_desc=
"  The pit becomes smaller as you descend deeper into its depths,\n\
like a seashell or an upside down dunce cap.  At the bottom, an\n\
archway leads into a wide tunnel that descends even further at\n\
an angle.\n";
  items=({
    "pit", "The pit is like an upside down cone, getting tighter as it\n"+
           "descends",
    "archway", "The archway leads to the south",
    "tunnel", "It leads into a cave to the south",
  });
  dest_dir=({
    PATH+"mound16.c","up",
    PATH+"mound20.c","south",
  });
}

void init() 
{
  ::init();
  if(this_player()->is_player()) peeps++;
  if(peeps) call_out("breathing",5);
}

void exit() 
{
  peeps--;
  if(!peeps) while(remove_call_out("breathing")!=-1) ;
}

void breathing()
{
  while(remove_call_out("breathing")!=-1) ;
  if(find_object(PATH+"mound20.c"))
  if(present("queen",find_object(PATH+"mound20.c")))
    tell_room(this_object(),
      "You hear a raspy breathing sound as a gust of air rises up\n"+
      "out of the pit.\n");
  call_out("breathing",10+random(30));
}
