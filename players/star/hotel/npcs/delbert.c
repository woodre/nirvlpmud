/*
 *      File:                 /players/star/hotel/npcs/delbert.c
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
  set_name("delbert");
  set_alias("ghost");
  set_race("human");
  set_gender("male");
  set_short("Ghost of Delbert Grady");
  set_long("This is the ghost of Delbert Grady.  He is wearing plain and\n"+
    "unimpressive clothing.  His ghostly hands are calloused as if he spent\n"+
    "most of his lifetime doing manual labor.  He somehow doesn't seem to\n"+
    "fit with the rich ghosts of former guests.\n");
  set_level(12);
  set_hp(180);
  set_al(-100);
  set_wc(16);
  set_ac(9);
  add_spell("life_drain",
    "#MN# touches you and $HR$SUCKS$N$ the life right out of you.\n",
    "#MN# touches #TN# and #TS# looks weaker.\n",
    15,10,0,0);
  set_chat_chance(3);
    load_chat("Delbert says, \"I used to be caretaker here.\"\n");
    load_chat("Delbert says, \"The hotel wants that little boy.\"\n");
    load_chat("Delbert says, \"The management is very interested in Danny.\"\n");
}

monster_died() {
object gold, corpse;
tell_room(environment(this_object()),
  "The ghost turns into a wisp of smokey mist and floats away.  In its\n"+
  "place a golden sparkle appears as a pile of coins falls to the ground.\n"+
  "The gods have rewarded you for expunging some of the evil from this\n"+
  "place.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(50)+500);
  move_object(gold,environment(this_object()));
  corpse = present( "corpse", environment());
  destruct( corpse );
  return 1; }
