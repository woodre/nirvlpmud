/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/mobs/vermin.c        *
 *    Function:         mob                                           *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/09/09                                      *
 *    Notes:            basic mob or mid lvl mob                      *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name(GRN+"Vermin"+NORM);
  set_alt_name("vermin");
  set_race("vermin");
  set_alias("rat");
  set_short(GRN+"Vermin"+NORM);
  set_long("The vermin is sniffing around in the room.\n"+
  "The vermin's eye dart from place to place looking for\n"+
  "food. The vermin's fur is matted and caked with mud.\n"+
  "Its appears to be a enlarged rat with huge whiskers.\n"+
  "The tail is so big that it leaves a very distinctive\n"+
  "large trail. It is foaming at the mouth and squeals\n"+
  "with delight as it sees toes to nibble on.\n");
  set_level(11);
  set_hp(180 + random (10));
  set_ac(9 + random (4));
  set_wc(16 + random (4));
  set_al(-50);
  add_money(random(250)+500);
  set_chat_chance(15);
  load_chat("You hear a"+HIBLK+" vermin"+RED+" SQUEAL!!"+NORM+"\n");
  load_chat("The"+HIBLK+" vermin"+NORM+" scurries around on the floor.\n");
  load_chat("The"+HIBLK+" vermin"+NORM+" starts foaming at the mouth!\n");
  add_spell("bite", "#MN# $HR$BITES$N$ you on the toe!\n",
                   "#MN# $HR$BITES$N$ #TN# on the toe!\n",
                   10,10,"other|physical");
  add_spell("scratch", "#MN# $HR$SCRATCHES$N$ you!\n",
                      "#MN# $HR$SCRATCHES$N$ #TN#!\n",
                      10,10,"other|physical");
}