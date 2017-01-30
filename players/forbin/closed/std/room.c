/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Function:     Base room inheritable 
 *  Create Date:  2004.06.07
 *  Last Edit:    2004.06.07 -Forbin
 *  Notes:        Inherits /players/vertebraker/closed/std/room"
 *                  Original Copyright (c) 2000 Vertebraker@Nirvana
 *  Notable Changes: 
 *    2004.06.07 - Created so I can add to this in future.           
 */

#include "/players/forbin/define.h"
#include "/players/forbin/logging.h"
inherit "/players/vertebraker/closed/std/room";

init()
{
    ::init();
    add_action("cmd_submit","fbug");
    add_action("cmd_submit","ftypo");
    add_action("cmd_submit","fidea");
    add_action("cmd_submit","fopinion");
    add_action("cmd_help","fhelp");
}

cmd_submit(string mess) {
  string who;
  string lev, xlev;
  string log;
  log = query_verb();
  log = log[1..strlen(log) - 1]+"s";
  who = this_player()->query_real_name();
  lev = this_player()->query_level(); xlev = this_player()->query_extra_level();
  log_it(LOGDIR+log+".log", 
    capitalize(who)+" ("+lev+"+"+xlev+") :: "+mess);
  write("Thank you.  Your "+log+" has been logged for Forbin to address.\n");
  return 1;
}

cmd_help() {
  write(
    HIC+"\n     fbug "+HIW+"'"+NORM+"what"+HIW+"'"+HIC+":"+NORM+"     use to submit bugs with my code\n"+
    HIC+"     ftypo "+HIW+"'"+NORM+"what"+HIW+"'"+HIC+":"+NORM+"    use to submit typos and grammatical errors\n"+
    HIC+"     fidea "+HIW+"'"+NORM+"what"+HIW+"'"+HIC+":"+NORM+"    use to submit new ideas for my area(s)\n"+
    HIC+"     fopinion "+HIW+"'"+NORM+"what"+HIW+"'"+HIC+":"+NORM+" use to submit opinions of my creations\n");
  return 1;
}