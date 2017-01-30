/*                                                                            *
 *      File:             /players/angel/area/town/obj/sign_03.c              *
 *      Function:         sign                                                *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include <ansi.h>

id(str) {
  return str=="land marker" || str== "marker";
}


long()
 {
  write("\n\
  Welcome to "+HIM+"Gas City."+NORM+" Under the guidance of Mayor Bob Ray this\n\
has become a very prosperous town. It was built along the Scenic\n\
Mississinewa River, which foster growth and security. It is a quaint,\n\
quiet, safe, secure and friendly town to over 8000 people. This town\n\
is strategically located along the I-69 corridor. It appears you are\n\
on I-69 and need to head west towards Gas City.\n\n");
}

short() {
  return ""+HIB+"Land Marker"+NORM+"";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "marker") return 0;
  long();
  return 1;
}