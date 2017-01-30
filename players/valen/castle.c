/*                                                                    *
 *    File:        /room/south/sislnd1.c                              *
 *    Function:         castle                                        *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           09/06/09                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */


#include <ansi.h>
#define NAME "Valen"
#define DEST "room/south/sislnd1"


id(str) { return str == "catacomb"; }

short()
{
  return HIBLK+"Catacomb entrance"+NORM;
}

long()
{
  write("This is the " + short() + ".\n");
  write("The catacomb entrance is small and the only structure on the shore.\n");
  write("The catacomb was once used by the Magi of this Isle. No one really\n");
  write("knows what the catacomb were used for. Anyone could "+HIBLK+"enter catacomb."+NORM+"\n");
}

init()
{
  add_action("enter","enter");
}


enter(str)
{
  if(str == "catacomb")
  {
    say(capitalize(this_player()->query_name())+
    " walks into the catacomb entrance.\n");
    this_player()->move_player(
    " walks into the catacomb entrance#/players/valen/area/catacombs/rooms/entrance.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
  }
  else write("Enter what?\n");
  return 1;
}

reset(arg)
{
  if (arg)
  return;
  move_object(this_object(), DEST);
}

is_castle(){return 1;}
