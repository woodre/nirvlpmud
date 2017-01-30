/******************************************************************************
 *  File:           example_room.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2005 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         10/27/05
 *  Notes:          
 *  Change History: 
 *****************************************************************************/

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  set_short("An Example Room");
  set_long(format("\
  This is an example of a room that can be set up to present some of the \
basics of coding and what not. There isn't really anything to look at, but \
it is something to look at."));
  add_item("anything","It isn\'t really here");
  add_exit("/room/green.c","green");
}
