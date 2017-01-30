/******************************************************************************
 *  File:           chit.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:         Started 2001.04.01
 *  Notes:
 *  Change History: 2001.03.03 (added set_info()); 2005.10.22 [strict_types
 *                  and fixed ids]
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "/obj/newtreasure.c";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("chit");
  set_alias("plass chit");
  set_short("A plass chit");
  set_long(format("This is a small plass credit chit that is used to \
store value. There is a display you can read."));
  set_weight(0);
  set_value(75 + random(76));
  set_read("The current value of this chit is " + HIC + query_value() + NORM +
    " coins.\n");
  set_info(format("The old credit chits could be charged to provide access \
to money on the go."));
}
