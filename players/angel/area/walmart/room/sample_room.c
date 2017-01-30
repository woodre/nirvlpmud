/******************************************************************************
 *  File:           sample_room.c
 *  Function:       
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004, 2005 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         05/01/2004
 *  Notes:          
 *  Change History: 02/09/2005 updated
 *****************************************************************************/

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Short Room Name";
  long_desc =
"  This is just some text to give the sample room some fill so that \n\
it doesn't look empty when Katya looks at it for an example of \n\
something roomy and spacious in a good neighborhood\n";

  items =
  ({
    "item",
    "description",
    "another",
    "It looks like this",
  });
  dest_dir =
  ({
    "/room/vill_green.c",           "green",
    "/players/vital/workroom.c",    "home",
  });
}
