/*                                                                    *
 *    File:             /players/angel/area/town/obj/cash.c           *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2007 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           6/15/07                                       *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("creditcard");
  set_alias("card");
  set_short("A Prepaid Creditcard");
  set_long(
"This is a Prepaid creditcard with a sizeable balance.\n\
It can be used to purchase items in Angel's world or\n\
'cash'ed in with Bob.\n"
  );
  set_weight(1);
  set_value(50);
}

init() {
  add_action("cmd_barter","cash");
}

cmd_barter(str) {
  if(id(str)) {
    if(present("bob",environment(this_player()))) {
      write("Bob says, congratulations on the kill!\n");
      this_player()->add_money(500 + random (400));
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("exchange what?\n");
}