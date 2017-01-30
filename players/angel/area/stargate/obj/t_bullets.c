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

#define USER environment(this_object())

int bullets;
int price;

id(str) { return str == "bullets" || str == "tracer rounds"; }

reset(arg)
{
  if(arg) return;
  bullets=25;
  price = bullets * 50;
}

short() { return "A small clip of tracer bullets [" + bullets + "]"; }
long()
{
  write("You hold a short metal clip filled with Tracer rounds\n"+
        "that appear to fit a P90 machine gun.\n");
  write("There are [" + bullets + "] bullets left.\n");
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


do_special(owner)
{
   if(!random(20)){
     tell_room(environment(USER),
BOLD+HIR+USER->query_name()+" P90 throws out flames of fire! I N C I N E R A T I O N !!!"+NORM+".\n");
owner->add_spell_point(random(6));
return 0;}
return 0;}


