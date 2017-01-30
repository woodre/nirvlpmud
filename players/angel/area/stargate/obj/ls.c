/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/laser.c      *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
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

  set_id("lasersight");
  set_alias("laser");
  set_short(HIR+"Laser Sight"+NORM+"");
  set_long(
  "    This is the new rail mounted "+HIR+"Laser Sight"+NORM+". It is smaller\n"+
  "than a match box and as lightweight as a single "+CYN+"P90"+NORM+" round,\n"+
  "this advanced targeting system features a patent pending\n"+
  "integral rail that allows the user to add other rail mounted\n"+
  "accessories, such as a tactical light. It also allows for\n"+
  "additional accessories to be stacked onto the unit. It is\n"+
  "designed and manufactured in the "+HIR+"U."+HIW+"S."+HIB+"A."+NORM+"!\n");
  set_value(1000);
  set_weight(1);
}

query_save_flag() {return 1;}

init()
{
  ::init();
  add_action("cmd_barter","barter");
}

/* Function name: cmd_barter ()
 * Description:   allows players to sell laser sight to private
 *            
 * Arguments: 
 * Returns: 
 */
cmd_barter(str) {
  if(id(str)) {
    if(present("private",environment(this_player()))) {
      write("Private says, nice doing business with you!\n"+
      "Tell your friends I can hook them up too!\n");
      this_player()->add_money(2000);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("barter what?\n");
}