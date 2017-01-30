/******************************************************************************
 *  File:           _sheep.c
 *  Function:       haunt people with sheep
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         25/1/04
 *  Notes:          
 *  Change History:
 *****************************************************************************/

#pragma strong_types
#pragma combine_strings

#include "/players/vital/closed/headers/vital.h"

int
main(string target)
{
  object sheep, goober;
  if ( !(goober = find_living(target)) )
  {
    notify_fail("Unable to aquire target " + target + ".\n");
    return 0;
  }
  sheep = clone_object("/players/vital/misc/esheep.c");
  sheep->set_on(target);
  sheep->get_owner();
  tell_object(goober,
    "It's raining sheep, Hallelujah! It's raining sheep.\n");
   return 1;
}


string
get_help()
{
  string help;
  help = "Give a player a cute sheep to annoy";
  return help;
}
