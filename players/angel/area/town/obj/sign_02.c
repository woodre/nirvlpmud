/*                                                                            *
 *      File:             /players/angel/area/town/obj/sign_02.c              *
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
  return str=="new sign" || str== "sign";
}


long()
 {
  write("\n\
                Welcome to Gas City\n\
\n\
   Welcome to our community where the sunrises and\n\
    sunsets are a little more spectacular and the \n\
        moon and stars are a lot brighter.\n\n");
}

short() {
  return "A Welcome "+HIM+"Sign"+NORM+"";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "sign") return 0;
  long();
  return 1;
}