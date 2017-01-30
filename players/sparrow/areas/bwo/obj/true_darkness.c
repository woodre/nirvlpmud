/*****************************************************************************
 *      File:                   true_darkness.c
 *      Function:               True Darkness ability object
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 03/20/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
inherit "obj/clean";

short() {
  return HIK+"A Globe of True Darkness"+NORM;
}
long() {
  write("If you are reading this, I screwed up - Sparrow.\n");
}
get() { return; }
drop() { return 1; }
id(str) { return str=="true_darkness"; }

void init() {
  if (!this_object()) return;
  set_light(-50);
  call_out("wink_out", 30);
}

/* 
 * Function name: wink_out()
 * Description:   This function causes the globe of darkness to
 *                "wink out" (destruct)
 * Arguments:     none
 * Returns:       void
 */
void 
wink_out(){
  tell_room(environment(this_object()), 
    HIY+"The Globe of True Darkness winks out.\n"+NORM);
  destruct(this_object());
  return;
}

