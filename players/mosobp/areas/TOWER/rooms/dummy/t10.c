/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t10.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  7/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */
#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
     
  if(arg) return;
  set_light(1);
  short_desc = BLU+"Kame's Tower"+NORM;
  long_desc = 
  "  "+HIB+"This is the platform of Kame's Lookout. From here\n"+
  "Kame keeps a watch on the whole earth looking around there\n"+
  "are trees all around as well as a house nearby."+NORM+"\n";
 
  items=
  ({
    "platform",
    "You are standing on the lookout",
    "trees",
    "The trees are scattered all about the lookout",
    "house",
    "It looks like someone is inside perhaps you can enter it",
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t13.c",  "north",
    "/players/mosobp/areas/TOWER/rooms/t17.c",  "west",
    "/players/mosobp/areas/TOWER/rooms/t18.c",  "east",
    "/players/mosobp/areas/TOWER/rooms/t22.c",  "south",
    "/players/mosobp/areas/TOWER/rooms/t9.c",   "down",
    "/players/mosobp/areas/TOWER/rooms/t25.c",  "enter",
  });
  return 1;
}

init()
{
  ::init();
  doStuff();
}

int doStuff()
{
  int sp_damage, hp_damage;

  if(this_player() && environment(this_player()) == this_object());
  {
    sp_damage = 75;
    hp_damage = 100;
    write(" "+HIK+"You have to sit down from the exhausting climb."+NORM+"\n");
        
    if(this_player()->query_hp() <= hp_damage) hp_damage = (int)this_player()->query_hp() - 1;
    if(this_player()->query_sp() <= sp_damage) sp_damage = (int)this_player()->query_sp() - 1;
    
    this_player()->hit_player(hp_damage,"physical");
    this_player()->add_sp(-sp_damage);
    "/bin/play/_monitor"->cmd_monitor();
  }
  
  return 1;
}
  