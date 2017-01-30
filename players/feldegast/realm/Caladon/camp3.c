/*
File: camp3.c
Author: Feldegast/ Dave Sampson
Date: 10/25/01
Description:
  An orc camp.  I apologize for the crappy description... I was
trying something different and blew it.
*/

#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(!random(2) && !present("orc"))
    move_object(clone_object(MON_PATH+(random(2)?"orc1.c":"orc2.c")), this_object());
  if(!random(3) && !present("orc 2"))
    move_object(clone_object(MON_PATH+(random(2)?"orc1.c":"orc2.c")), this_object());
  if(arg) return;
  set_light(1);
  short_desc=AREANAME;
  long_desc=
"  This is an example of the grand architects of the Goremonger clan\n\
at their finest.  Note the thatched roof, which occasionally keeps\n\
rain out, the wooden walls patched by the finest Allandrian clay, and\n\
the indoor privy in the corner.  Yep, it doesn't get much better than\n\
this -- if you're an orc.\n";
  items = ({
    "roof", "You 'oooooo' and 'aaaaah' in an impressed manner",
    "walls", "You 'oooooo' and 'aaaaah' in an impressed manner",        
    "clay",  "You 'oooooo' and 'aaaaah' in an impressed manner",
    "privy", "You don't look TOO closely",
  });

  dest_dir = ({
    PATH+"camp2.c", "south",
  });

}

