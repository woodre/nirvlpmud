/*
 *      File:                 /players/star/hotel/npcs/corpse.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               03/16/2006
 *      Notes:
 *      Change History:
 */

#include </players/star/defs.h>

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("corpse");
  set_alias("lady");
  set_race("human");
  set_gender("female");
  set_short("A Corpse of a Lady");
  set_long("This corpse looks strangely animated for a dead woman.  She also looks\n"+
    "as if she has been in that tub for a very very long time.  She is\n"+
    "completely naked, and drips water all over as she keeps stepping\n"+
    "toward you.  Her skin is black and rotting, and the smell of decay\n"+
    "pours from what used to be a very nice body.\n");
  set_level(13);
  set_hp(195);
  set_al(-50);
  set_wc(17);
  set_ac(10);
  add_spell("strangle",
    "#MN# closes her hands around your neck and $HM$SQUEEZES$N$!\n",
    "#MN# closes her hands around #TN#'s neck and $HM$SQUEEZES$N$!\n",
    20,15,0,0);
  set_chat_chance(3);
    load_chat("The dead woman raises her arms and reaches for your neck.\n");
  add_money(random(100)+500);
}
