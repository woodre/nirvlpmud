/*
 *      File:                  .c
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

inherit "/obj/generic_heal.c";
void reset(int arg){
  ::reset(arg);
  if(arg) return;
  set_name("Dagda Root");
  add_alias("plant");
  set_short(HIY+"Dagda"+NORM+YEL+" Root"+NORM);
  set_long("A Yellowish root known for it's healing powers.\n");
  set_type("root");
  set_msg("You knaw on the root.\n");
  set_msg2(" knaws on a root.\n");
  add_cmd("eat");
  set_heal(50,0);
  set_charges(3);
  set_soak(3);
  set_stuff(3);
  set_value(600);
}

id(str) { return str == "root" || str == "dagda" || str == "dagda root" || str == "dagda_root" || str == "Dagda Root" || str == "Dagda_Root";} 
  
