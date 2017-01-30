/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Realm:        Flame Forest
 *  Function:     Sellable item on mob
 *  Create Date:  2002.04.30
 *  Last Edit:    2004.06.03 -Forbin
 *  Notes:        Can be used by Servants of Shardak guild to create
 *                special equipment
 *  Notable Changes:
 */

#include "/players/forbin/define.h"
inherit "obj/treasure" ;

id(str) { return (str == "shard" || str == "bone" ||  
                  str == "shard of bone" || str == "bone shard" || 
                  str == "shardak_bone_shard"); }

reset(arg) {
  if(arg) return;
  set_short(HIR+"A shard of bone"+NORM);
  set_long("  This is a large piece of bone from a thermal wraith.  It seems very\n"+
           "heavy for a bone shard - and has a bright, blood-red look to it.  It\n"+
           "could be sold, although you may find other uses for it.\n");
  set_weight(2);
  set_value(400+random(201));
}
