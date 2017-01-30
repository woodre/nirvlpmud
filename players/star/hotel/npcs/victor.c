/*
 *      File:                 /players/star/hotel/npcs/victor.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/23/2006
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
  set_name("victor");
  set_alias("ghost");
  set_race("human");
  set_gender("male");
  set_short("Ghost of Victor T. Boorman");
  set_long("This ghost is huge.  His muscles ripple with his every move.  He was\n"+
    "the kind of man people do not want to meet in a dark alley.  His\n"+
    "blonde crew cut and the scar over his eye make him look menacing\n"+
    "indeed.\n");
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
    load_chat("Victor cracks his knuckes.\n");
    load_chat("Victor pounds his fist into his hand.\n");
    load_chat("Victor says, \"No one gets in to see da boss.\"\n");
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
