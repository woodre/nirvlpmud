/******************************************************************************
 *  File:           coat.c
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  Source:			    Started 1/4/01.
 *  Notes:
 *  Change History: 3/3/01(added set_info());
 *****************************************************************************/
#pragma strict_types
#include <ansi.h>

inherit "obj/armor";

void
reset(status arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("coat");
  set_alias("tired coat");
  set_short("A tired " + BLU + "coat" + NORM);
  set_long("  A " + BOLD + BLK + "dark " + NORM + BLU + "blue " + NORM +
"coat that has seen better days. Some areas of the coat are getting \
thread-bare and thin.\n");
  set_info("The coat has long seen better days.\n");
  set_ac(1);
  set_type("misc");           /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(2);
  set_value(145 + random(70));
}

int
do_special(object owner)
{
  if (!random(35))
  {
    tell_object(owner, "The " + BOLD + BLK + "dark " + NORM + BLU +
      "blue " + NORM + "coat manages to get in the way of the battle.\n");
    return -1;
  }
  if (!random(100))
  {
    tell_object(owner, "The " + BOLD + BLK + "dark " + NORM + BLU +
      "blue " + NORM + "coat finally breathes its last.\n");
    this_object()->remove("coat");
    call_out("poof", 1);
    return 9999;
  }
}

void
poof()
{
  destruct(this_object());
}