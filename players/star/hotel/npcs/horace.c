/*
 *      File:                 /players/star/hotel/npcs/horace.c
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
  set_name("horace");
  set_alias("ghost");
  set_race("human");
  set_gender("male");
  set_short("Ghost of Horace Derwent");
  set_long("This is the ghost of Horace Derwent.  He was a short, balding man, and\n"+
    "from the looks of his ghostly form he was very rich.  It looks like\n"+
    "his clothes used to be high end merchandise, though certainly not from\n"+
    "this decade, and there is a glint of a ghostly watch chain that was\n"+
    "likely gold in its day.\n");
  set_level(16);
  set_hp(300);
  set_al(-100);
  set_wc(22);
  set_ac(13);
  add_spell("cold_fear",
    "#MN# touches you and you feel a $HC$COLD FEAR$N$ pass straight through\n"+
    "you.  You shiver all over.\n",
    "#MN# touches #TN# and #TS# $HC$shivers all over$N$.\n",
    20,20,0,0);
  set_chat_chance(3);
    load_chat("Horace says, \"I was very rich you know.\"\n");
    load_chat("Horace brags, \"I used to own most of the stock for this place.\"\n");
}
monster_died() {
object gold, corpse;
tell_room(environment(this_object()),
  "The ghost turns into a wisp of smokey mist and floats away.  In its\n"+
  "place a golden sparkle appears as a pile of coins falls to the ground.\n"+
  "The gods have rewarded you for expunging some of the evil from this\n"+
  "place.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(200)+1300);
  move_object(gold,environment(this_object()));
  corpse = present( "corpse", environment());
  destruct( corpse );
  return 1; }
