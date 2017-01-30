/*
 *      File:                 /players/star/toys/ny_hat.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               12/31/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("hat");
  set_alias("party hat");
  set_short(HIM+"A NEW YEAR'S PARTY HAT!!"+NORM);
  set_long("A "+HIC+"brightly colored "+NORM+" pointy hat with an elastic string.  It has the year\n"+
    HIY+"2006 "+NORM+"printed on it in "+HIG+"shiny "+NORM+"letters.\n");
  set_ac(0);
  set_type("helmet");
  set_weight(1);
  set_value(0);
}
