/*
File: camp7.c
Author: Feldegast
Date: 02/14/02
Description:
  A cave behind the waterfall near the orc camp.
Note to self: Put something interesting here.
*/

#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  short_desc=AREANAME;
  long_desc=
"  Water and time have eroded this cave from the rock.  It is damp\n\
and the air is filled with mist.  Nearby, you hear the roar of\n\
swiftly moving water.\n";
  items = ({
    "water", "The cave is damp and filled with mist",
    "cave", "reflexive",
    "mist", "The mist appears to be wet",
  });

  dest_dir = ({
    PATH+"camp6.c", "out",
  });

}

