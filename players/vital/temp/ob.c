/******************************************************************************
 *  File:           ob.c
 *  Author(s):      Vital@Nirvana from source by Rich@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         9/24/05
 *  Notes:          
 *  Change History:
 *****************************************************************************/

#include <ansi.h>

inherit "/obj/newtreasure.c";

void
reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("tricorder");
  set_alias("handheld computer");
  set_short("A tricorder");
  set_long("\
  This is a basic model tricorder used all across Federation space\n\
to analyze various things and obtain information about the world\n\
around us. To activate the tricorder use tri_scan <object>.\n");
  set_value(5000);
  set_weight(2);
  add_id("computer");
  add_id("spocks tricorder");
  set_read("Spock\'s Tricorder\n");
  set_info("Nothing cool here.\n");
}

init()
{
  add_action("tri_scan", "tri_scan");
}

tri_scan(str)
{
  string objectname;
  int health, max_health;
  object ob;
  sscanf( str, "%s", objectname );
  if ( objectname == 0 )
  {
    notify_fail( "read tricorder on SOMETHING.\n" );
    return 0;
  }
  ob = find_living( objectname );
  if(!ob) { write("That is not in existance.\n"); return 1; }
  if ((ob->query_level())>30)
  {
    write("Sorry no definite readings can be obtained at this time.\n");
    return 1;
  }
  if (ob== 0)
  {
    write("Nothing by that name is functioning at this time.\n");
    return 1;
  }
  health = ob->query_hp();
  max_health = ob->query_mhp();
  write( call_other( ob, "query_name", 0 ) + "\n");
  write("Level:  " + call_other( ob, "query_level", 0) + "\n");
  write("Where:  " + environment(ob)->short() + "\n");
  if(health > (((max_health)*90)/100) )
    write("Status: Healthy\n"); 
  else if(health > (((max_health)*75)/100) )
    write("Status: Damaged\n"); 
  else if(health > (((max_health)*50)/100) )
    write("Status: Hurting\n"); 
  else if(health > (((max_health)*30)/100) )
    write("Status: Dying\n"); 
  else if(health > (((max_health)*50)/100) )
    write("Status: Damaged\n");
  else
    write("Status: Indeterminate\n");
  return 1;
}
