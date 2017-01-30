/*****************************************************************************
 *      File:                   paralyze.c
 *      Function:               Paralyze Spell object for monks
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 04/24/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
inherit "obj/clean";


short() {
  return "";
}
long() {
  write("");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str=="paralyze"; }

void init() {
  call_out("wink_out", (1+random(4)));
  add_action("paralized");
  add_xverb("");
}

/* 
 * Function name: wink_out()
 * Description:   Causes the object to destruct
 * Arguments:     none
 * Returns:       void
 */
void 
wink_out(){
  tell_room(environment(environment(this_object())), 
  HIC+"The shadows have disappated.\n"+NORM);
  tell_object(environment(this_object()), HIC+"You are free of the binding!\n"+NORM);
  destruct(this_object());
  return;
}

/* 
 * Function name: paralized()
 * Description:   This function sends the paralization message to a player
 *                when they try to type a command
 * Arguments:     none
 * Returns:       int
 */
int
paralized()
{
  tell_object(environment(this_object()),
  HIR+"The shadows have completely engulfed you, you are unable to do that!\n"+NORM);
  return -1;
}