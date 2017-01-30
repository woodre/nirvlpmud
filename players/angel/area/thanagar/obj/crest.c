/*                                                                    *
 *    File:             /players/angel/area/thanagar/room/glovers.c   *
 *    Function:         obj                                           *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2008 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/08/08                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/treasure";

id(str) { return str == "crest"; }

reset(arg) {
	
   if(arg) return;
   ::reset(arg);
   set_name("crest");
   set_short("Hawkman's Crest");
   set_long("\The crest is a red circle with a black hawk's head in the center.\n");
   set_weight(1);
   set_value(10000);
}