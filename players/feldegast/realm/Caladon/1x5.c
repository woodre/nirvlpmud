/*
File: 1x5.c
Author: Feldegast
Date: 2/14/02
Description:
  Barony of Caladon.
*/

#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  x=1; y=5;
  short_desc=AREANAME;
  long_desc=
"  The Storncrag mountains to the west cast their shadow over the\n\
surrounding hills.  To the south of you is the River Xian.  A trail\n\
leads west into some sort of encampment.\n";
  items = ({
    "mountains", "The Storncrag mountains to the west cast their shadow over the surrounding hills",
    "hills", "reflexive",
    "river", "The River Xian is a wide river, several stone throws across, and uncrossable here",
    "xian", "The River Xian is a wide river, several stone throws across, and uncrossable here",

    "trail", "The dirt trail appears to have formed naturally due to people or\n"+
             "animals passing here frequently",
    "encampment", "The encampment consists of perhaps a dozen tents and several wooden buildings\n"+
                  "further up the side of the mountains is a temple of some sort",

  });

  dest_dir = ({
    PATH+"1x6.c", "north",
    PATH+"camp1.c", "west",
    PATH+"2x5.c", "east",
  });

}

