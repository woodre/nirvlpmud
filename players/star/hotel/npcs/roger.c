/*
 *      File:                 /players/star/hotel/npcs/roger.c
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
  set_name("roger");
  set_alias("ghost");
  set_race("human");
  set_gender("male");
  set_short("Ghost of Roger Macassi");
  set_long("This ghost is huge.  His muscles ripple with his every move.  He was\n"+
    "the kind of man people do not want to meet in a dark alley.  His\n"+
    "black hair is cut short and his face is pockmarked with old scars.\n");
  set_level(15);
  set_hp(250);
  set_al(-100);
  set_wc(20);
  set_ac(12);
  add_spell("cold_fear",
    "#MN# touches you and you feel a $HC$COLD FEAR$N$ pass straight through\n"+
    "you.  You shiver all over.\n",
    "#MN# touches #TN# and #TS# $HC$shivers all over$N$.\n",
    20,20,0,0);
  set_chat_chance(3);
    load_chat("Roger growls menacingly.\n");
    load_chat("Roger stares around the room suspiciously.\n");
    load_chat("Roger glares at you.\n");
}
monster_died() {
object gold, corpse;
tell_room(environment(this_object()),
  "The ghost turns into a wisp of smokey mist and floats away.  In its\n"+
  "place a golden sparkle appears as a pile of coins falls to the ground.\n"+
  "The gods have rewarded you for expunging some of the evil from this\n"+
  "place.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(150)+850);
  move_object(gold,environment(this_object()));
  corpse = present( "corpse", environment());
  destruct( corpse );
  return 1; }
