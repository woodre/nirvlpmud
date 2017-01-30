/*
 *      File:                 /players/star/npcs/boy_ghost.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               01/13/2006
 *      Notes:
 *      Change History:       [3-25-06] Added the life drain spell
 */

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("ghost");
  set_alias("boy");
  set_race("human");
  set_gender("male");
  set_short("The Ghost of a Small Boy");
  set_long("A wisp of smokey vapor that looks to have the form of a small boy.\n");
  set_level(10);
  set_hp(150);
  set_al(-45);
  set_wc(14);
  set_ac(8);
  add_spell("life_drain",
    "#MN# touches you and $HR$SUCKS$N$ the life right out of you.\n",
    "#MN# touches #TN# and #TS# looks weaker.\n",
    15,10,0,0);
  set_chat_chance(3);
    load_chat("You hear the leaves on the floor of the pipe rustle behind you.\n");
    load_chat("You feel cold.\n");
}

monster_died() {
object gold, corpse;
tell_room(environment(this_object()),
  "The ghost turns into a wisp of smokey mist and floats away.  In its\n"+
  "place a golden sparkle appears as a pile of coins falls to the ground.\n"+
  "The gods have rewarded you for expunging some of the evil from this\n"+
  "place.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(100)+350);
  move_object(gold,environment(this_object()));
  corpse = present( "corpse", environment());
  destruct( corpse );
  return 1; }
