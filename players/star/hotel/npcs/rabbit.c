/*
 *      File:                 /players/star/npcs/rabbit.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/13/2006
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("rabbit");
  set_alias("hedge rabbit");
  set_short("A Hedge Rabbit");
  set_long("This is a neatly trimmed hedge in the shape of a rabbit.\n");
  set_level(12);
  set_hp(180);
  set_al(0);
  set_wc(16);
  set_ac(9);
  set_chat_chance(3);
    load_chat("The hedge rabbit rustles, though there is no wind.\n");
    load_chat("Did that hedge just move!?\n");
}
monster_died() {
  object corpse;
  int branches;
  branches = random(2) + 4;
  while (branches > 0) {
    move_object(clone_object("/players/star/hotel/objs/branch.c"), this_object());
    branches--; }
  corpse = present( "corpse", environment());
  destruct( corpse );
  tell_room(environment(this_object()),
    "The hedge rabbit finally falls apart, leaving nothing where it was but a pile\n"+
    "of branches.\n");
  return 1; }
