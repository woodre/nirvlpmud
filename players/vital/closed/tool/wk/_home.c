/******************************************************************************
 *  File:           _home.c
 *  Function:       overide the /bin/wiz/home.c functionality for me
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
main()
{
    string home;
    home = (string)TP->query_home();
    TP->move_player("to the " + home->query_short() + "#" + home );
    return 1;
}


string
get_help()
{
  string help;
  help = "Return to where ever is set as home";
  return help;
}
