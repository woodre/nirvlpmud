/*                                                                            *
 *      File:             /players/angel/area/town/obj/red_rose.c             *
 *      Function:         flower                                              *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:                                                                *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/obj/treasure";

reset(arg) {
   if(arg) return;
   ::reset(arg);
   set_name("Red rose");
   set_alias("rose");
   set_short(HIR+"Red Roses"+NORM);
   set_long("Beautiful Red Roses   -`-{"+HIR+"@  @"+NORM+"}-'-\n");
   set_weight(1);
   set_value(50);
}