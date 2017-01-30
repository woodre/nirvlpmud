/*****************************************************************************
 *      File:                   silence.c
 *      Function:               Silence Spell object for Nyte
 *      Author(s):              Sparrow@Nirvana
 *      Copyright:              Copyright (c) 2006 Sparrow All Rights Reserved.
 *      Source:                 04/21/2006
 *      Notes:                  
 *      Change History:         
 ****************************************************************************/
#include <ansi.h>
inherit "obj/clean";

/* GLOBALS */
object Room; 


short() {
  return HIM+"A Sphere of Silence"+NORM;
}
long() {
  write("You can see the faint outline of a magical sphere surrounding you.\n");
}
get() { return 1; }
drop() { return 1; }
id(str) { return str=="silence"; }

void init() {
  call_out("wink_out", 20);
  Room = environment(this_object());
}

/* 
 * Function name: wink_out()
 * Description:   This function causes the sphere of silence to
 *                "wink out" (destruct)
 * Arguments:     none
 * Returns:       void
 */
void 
wink_out(){
  tell_room(environment(this_object()), 
  HIC+"You can hear again.\n"+NORM);
  if(Room)
  {
    Room->remove_property("no_magic");
    Room->remove_property("no_magic");
    Room->remove_property("no_magic");
    Room->remove_property("no_magic");
    destruct(this_object());
  }
  return;
}