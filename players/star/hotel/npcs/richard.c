/*
 *      File:                 /players/star/hotel/npcs/richard.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/24/2006
 *      Notes:
 *      Change History:
 */

#include </players/star/defs.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  set_dead_ob(this_object());
  if(arg) return;
  set_name("richard");
  set_alias("ghost");
  set_race("human");
  set_gender("male");
  set_short("Ghost of Richard Scarne");
  set_long("Richard Scarne was a well-dressed businessman in his day.  His shirt\n"+
    "bears the logo of Fun Time Amusements.  His dark hair is slicked back\n"+
    "and he smiles at you like he is still hopeful of a sale, even after\n"+
    "his death.\n");
  set_level(14);
  set_hp(220);
  set_al(-100);
  set_wc(18);
  set_ac(11);
  add_spell("life_drain",
    "#MN# touches you and $HR$SUCKS$N$ the life right out of you.\n",
    "#MN# touches #TN# and #TS# looks weaker.\n",
    15,10,0,0);
  set_chat_chance(3);
    load_chat("Richard says, \"The feds think I was involved with the mob.\"\n");
    load_chat("Richard winks and says, \"They never could prove a thing.\"\n");
}
monster_died() {
object gold, corpse;
tell_room(environment(this_object()),
  "The ghost turns into a wisp of smokey mist and floats away.  In its\n"+
  "place a golden sparkle appears as a pile of coins falls to the ground.\n"+
  "The gods have rewarded you for expunging some of the evil from this\n"+
  "place.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(100)+650);
  move_object(gold,environment(this_object()));
  corpse = present( "corpse", environment());
  destruct( corpse );
  return 1; }
