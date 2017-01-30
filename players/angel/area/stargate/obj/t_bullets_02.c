/*                                                                    *
 *    File:             /players/angel/area/stargate/npc/t_bullet.c   *
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

inherit "obj/weapon.c";

int bullets;
int price;

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("tracer rounds");
  set_alias("trounds");
  bullets=25;
  price = bullets * 50;
  set_short("A small clip of tracer bullets [" + bullets + "]");
  set_long("You hold a short metal clip filled with Tracer rounds\n"+
           "that appear to fit a P90 machine gun.\n"+
           "There are [" + bullets + "] bullets left.\n");
  set_hit_func(this_object());
  set_params("other|fire",1,"fire_hit");
}
lose_ammo(i)
{
  if(i) bullets = bullets - i;
  else bullets = bullets - 1;
  return bullets;
}
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

cmd_barter(str) {
  if(id(str)) {
    if(present("private",environment(this_player()))) {
      write("Private says, nice doing bussiness with you!\n"+
      "Tell your friends I can hook them up too!\n");
      this_player()->add_money(500);
      destruct(this_object());
      this_player()->recalc_carry();
      return 1;
    }
  }
  notify_fail("barter what?\n");
}

fire_hit(attacker){
  if (random(20)>5) {
    say(""+HIR+"The P90 throws out flames of fire! I N C I N E R A T I O N !!!"+NORM+"\n");
    write(""+HIR+"The P90 throws out flames of fire! I N C I N E R A T I O N !!!"+NORM+"\n");
    return 5;
  }
}