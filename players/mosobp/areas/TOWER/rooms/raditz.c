/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/raditz.c
 *  Function:  mob                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved          
 *                                       
 *                                       
 *  Source:  6/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "/obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("raditz");
  set_short(HIR+"Raditz"+NORM);
  set_race("saiyan");
  set_long(
  
  "Raditz was the first saiyan besides goku on the earth. He was sent\n"+
  "to earth to check on Goku's progress of conquering Earth.\n");
  
  set_level(15);
  set_hp(600);
  set_al(-1000);
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/sarmor.c"), this_object());
  init_command("wear armor");
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/sboots.c"), this_object());
  init_command("wear boots");
  set_wc(20);
  set_ac(9);
  
}
  