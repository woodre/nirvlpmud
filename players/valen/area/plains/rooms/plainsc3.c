/*                                                                    *
 *    File: Entrance  /players/valen/area/plains/rooms/plainsc3.c     *
 *    Function:         room                                          *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 Valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/25/09                                      *
 *    Notes:            plains entrance                               *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Grassy Plains of Elrath";
  long_desc =
  "These grassy fields belong the Griffin Empire.";
  
  items =
  ({
    "grass", 
    "The grass grows wild",
  });
  dest_dir =
  ({
    "/players/valen/area/plains/rooms/plainsc2.c",     "north",
    "/players/valen/area/catacombs/rooms/dungeona1.c",     "out",
  });
 
}
