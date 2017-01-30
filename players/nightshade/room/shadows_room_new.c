inherit "room/room";
#include <ansi.h>

/******************************************************************************
 * Program: shadows_room_new.c
 * Path: /players/nightshade/room
 * Type: Room
 * Created: October 2014 by Karash
 *
 * Purpose: A room object used to temporarily house the Thief when he hides
 *          in the shadows.
 * History:
 *          
 ******************************************************************************/


reset(arg) {
  
  if(arg) return;
  
  short_desc = GRY+"Shadows"+NORM;
  set_light(0);

  dest_dir=({});
  long_desc=
"The shadows.\n";
}

init() {
	::init();
}

