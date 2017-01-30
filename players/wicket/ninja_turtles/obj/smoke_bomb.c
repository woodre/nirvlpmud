/*****************************************************************************
 *      File:                   true_darkness.c
 *      Function:               True Darkness ability object
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 03/20/2006
 *      Notes:                  
 *      Change History:         Edited By Wicket with permission from Sparrow 9/1/2015
 ****************************************************************************/
#include <ansi.h>
inherit "obj/clean";

short() {
  return HIK+"A cloud of blinding smoke"+NORM;
}
long() {
  write("You Should not be seeing this.\n");
}
get() { return; }
drop() { return 1; }
id(str) { return str=="smoke_bomb"; }

void init() {
  if (!this_object()) return;
  set_light(-50);
  call_out("wink_out", 30);
}

/* 
 * Function name: wink_out()
 * Description:   This function causes the cloud of smoke
 *                "wink out" (destruct)
 * Arguments:     none
 * Returns:       void
 */
void 
wink_out(){
  tell_room(environment(this_object()), 
    HIK+"The smoke clears the room and your vision as restored.\n"+NORM);
  destruct(this_object());
  return;
}

