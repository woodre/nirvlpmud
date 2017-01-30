/*                                                                    *
 *    File:             /players/angel/area/elvandar/room/cave.c      *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
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
  short_desc = " Elven Forest Cave";
  long_desc =
" The rough surface walls of the Cave appear to have been\n\
more man-made quality rather than a natural one, in fact\n\
this cave and the extending tunnels are all that are left\n\
of what once used to be prosperous Dwarven silver, gold,\n\
and iron ore mines.  You laugh to yourself as you ponder\n\
the ironic subtleties of the mine, namely the fact that\n\
you have to crouch to stand, after all the Dwarven folk\n\
are not as tall as the average Elf, therefore why would\n\
they make the mine taller than necessary.  The other tunnels\n\
which extend from the main Cave are too small for you to\n\
navigate freely and the support beams have weakened with\n\
age and rot, therefore you return to the Forest to the East.\n";

  items =
  ({
    " ",
    " ",
  });
  dest_dir =
  ({
    "/players/angel/area/elvandar/room/f_08",      "east",
  });
}