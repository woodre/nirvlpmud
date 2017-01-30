/*
File: park.c
Author: Feldegast
Date: 09/25/99
Revised: 03/23/02
Description:
  A park.  In the day, philosophers, at night, the hedges
turn into monsters.
*/

#include "defs.h"

#define HOUR (time() % 86400 / 3600 - 4)

inherit ROOM;

void reset(int arg)
{
  if(HOUR > 6)
  {
    while(present("hedge")) destruct(present("hedge"));
    while(random(3))
      move_object(clone_object(MON_PATH+"philosopher.c"),this_object());
  }
  else
  {
    while(present("philosopher")) destruct(present("philosopher"));
    while(random(4))
      move_object(clone_object(MON_PATH+"hedge_monster.c"),this_object());
  }
  if(arg) return;
  set_light(1);
  short_desc="Philosopher's Park";
  long_desc=
"  This is a neat little park amidst the hustle and bustle of Calador.\n\
Well kept paths meander around manicured lawns and large bushes trimmed\n\
to look like mythological creatures such as dragons and griffins.  Marble\n\
benches and tables, about which old men gather to pontificate during the\n\
day, are scattered around the park.  To the east is an iron gate that leads\n\
in and out of the park.\n";
  items=({
    "paths","The paths meander around the manicured lawns and large bushes",
    "creatures","They appear almost real...If it weren't for the fact that were all\n"+
                "green and made out of leaves",
    "benches","The benches are constructed of white marble with blue streaks",
    "tables","The tables are constructed of white marble with blue streaks",
    "gate","A formal looking gate constructed of black iron",
  });
  dest_dir=({
    PATH+"unknown","east",
  });
}
