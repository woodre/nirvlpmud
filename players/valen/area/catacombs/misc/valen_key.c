/*                                                                    *
 *    File: valen  /players/valen/area/catacombs/misc/valen_key.c     *
 *    Function:         key                                           *
 *    Author(s):        valen@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 valen                      *
 *                              All Rights Reserved.                  *
 *    Source:           08/23/09                                      *
 *    Notes:            key object                                    *
 *                                                                    *
 *                                                                    *
 *    Change History: 08/23/09 version 1.2                            *
 */

#include "/sys/lib.h"
inherit "/obj/treasure.c";
#include <ansi.h>

id(str)
{
  return str == "valen_key" || str == "bronze key" || str == "key";
}

short()
{
  return "A bronze key";
}

long() 
{
  write("A bronze key with a emblem on the top.  \n"+
  "The emblem is a "+BLUE+"Sword"+NORM+" crossed with a "+HIW+"Feather"+NORM+".\n");
}

get() { return 1; }
query_weight() { return 1; }
query_value(){ return 100; }