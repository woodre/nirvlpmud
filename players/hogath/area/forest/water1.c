/*
 *      File:                   water1.c
 *      Function:               
 *      Author(s):              Hogath@Nirvana
 *      Copyright:              Copyright (c) 2004 Hogath
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
#include "/players/hogath/tools/def.h"
inherit "/players/hogath/area/forest/waterroom.c";

reset(arg){
  if(arg) return;
  ::reset(arg);
  items += ({"sign","this is a sign, it's a pretty sign",});
  
  
dest_dir = ({
    "/players/hogath/area/forest/frooms/f12.c","out",
});
}

