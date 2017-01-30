/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Function:     Base room inheritable for ~realms/flame_forest
 *  Create Date:  2004.06.07
 *  Last Edit:    2004.06.07 -Forbin
 *  Notes:        Inherits /players/vertebraker/closed/std/room"
 *                  Original Copyright (c) 2000 Vertebraker@Nirvana
 *  Notable Changes: 
 *    2004.06.07 - Modified lots are functions to return BOLD+BLACK text           
 */ 

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";

long(str) {
  write(HIK);
  this_player()->remote_say(HIK);
  ::long(str);
  write(NORM);
  this_player()->remote_say(NORM);
    return;
}

room_msg() {
  tell_room(this_object(),HIK);
  ::room_msg();
  tell_room(this_object(),NORM);
    return;
}

/*
cmd_search(str) { 
  int retVal;
  tell_room(this_object(),HIK);
  retVal = ::cmd_search(str);
  tell_room(this_object(),NORM);
  return retVal;
}

cmd_taste(str)
{
  int retVal;
  tell_room(this_object(),HIK);
  retVal = ::cmd_taste(str);
  tell_room(this_object(),NORM);
  return retVal;
}
cmd_listen(str) { 
  int retVal;
  tell_room(this_object(),HIK);
  retVal = ::cmd_listen(str);
  tell_room(this_object(),NORM);
  return retVal;
}

cmd_smell(str) { 
  int retVal;
  tell_room(this_object(),HIK);
  retVal = ::cmd_smell(str);
  tell_room(this_object(),NORM);
  return retVal;
}

cmd_touch(str) { 
  int retVal;
  tell_room(this_object(),HIK);
  retVal = ::cmd_touch(str);
  tell_room(this_object(),NORM);
  return retVal;
}
*/
