/*                                                                        *
 *      File:             /players/angel/area/lowthar/obj/sign.c          *
 *      Function:         sign                                            *
 *      Author(s):        Angel@Nirvana                                   *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)        *
 *                                All Rights Reserved.                    *
 *      Source:           11/15/06                                        *
 *      Notes:                                                            *
 *                                                                        *
 *                                                                        *
 *      Change History:                                                   *
 */

#include <ansi.h>

id(str) {
  return str=="new sign" || str== "sign";
}


long()
 {
  write("\n\
    Welcome to the Land of Lowthar\n\
Seach out Kenric, he needs help to find his father!\n\n");
}

short() {
  return ""+HIY+"An old wooden sign"+NORM+"";
}

init() {
  add_action("cmd_read","read");
}

int cmd_read(string str) {
  if(str != "sign") return 0;
  long();
  return 1;
}