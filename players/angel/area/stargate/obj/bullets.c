/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/bullets.c    *
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

inherit "obj/treasure";

int bullets;
int price;

id(str) { return str == "bullets" || str == "clip"; }

reset(arg)
{
  if(arg) return;
  bullets=50;
  price = bullets * 10;
}

short() { return "A clip of bullets [" + bullets + "]"; }
long()
{
  write("You hold a long metal clip that can be filled with\n"+
        "bullets that appear to fit a P90 machine gun.\n");
  write("There are [" + bullets + "] bullets left.\n");
}
/* Function name: lose_ammo ()
 * Description: subtracts ammo
 *            
 * Arguments: 
 * Returns: 
 */
lose_ammo(i)
{
  if(i) bullets = bullets - i;
  else bullets = bullets - 1;
  return bullets;
}
/* Function name: query_ammo ()
 * Description:   tells players number of bullets left
 *            
 * Arguments: 
 * Returns: 
 */
query_ammo()
{
  return bullets;
}
query_save_flag() {return 1;}
query_value() { return price; }

get() { return 1; }

query_weight() { return 1; }

init()
{
  ::init();
  add_action("cmd_barter","barter");
}


/* Function name: cmd_barter ()
 * Description:   allows players to sell ammo to private
 *            
 * Arguments: 
 * Returns: 
 */
cmd_barter(str) {
  if(id(str)) {
    if(present("private",environment(this_player()))) {
      write("Private says, nice doing business with you!\n"+
      "Tell your friends I can hook them up too!\n");
      this_player()->add_money(500);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("barter what?\n");
}