/******************************************************************************
 *  File:           messages.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.01.04
 *  Notes:          simple weapon for boring npcs
 *  Change History: 2001.02.28 (Updated message_hit)
 *                  2005.10.23 [strict_type'd and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "obj/weapon.c";

void
reset(status arg)
{
  ::reset(arg);
  if (arg) return;
  set_name("pda");
  set_alias("organizer");
  set_short("A hi-tech PDA");
  set_long("This Personal Digital Assistant is the ultimate travel-warrior's\n\
weapon. The tiny screen doesn't give much information.\n");
  set_type("knife");
  set_class(16);
  set_weight(1);
  set_value(100 + random(150));
  message_hit=(
  {
    HIY + "EleCtrOcuteD" + NORM," with the limited battery power",
    "shocked"," with your hi-tech prowess",
    "repeatedly " + HIR + "berated" + NORM,
      " with messages from the portable thesaurus",
    "gouged"," with the corner of the PDA",
    "confused"," with appointments from the last fiscal quarter",
    "jabbed"," with the stylus",
    "poked"," in the chest",
  });
}
