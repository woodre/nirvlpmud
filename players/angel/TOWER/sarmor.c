/*                                       
 *  File:   /players/mosobp/areas/TOWER/OBJ/sarmor.c
 *  Function:  object                    
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

#include "/obj/ansi.h"

inherit "obj/armor";


reset(arg)
{
	
  if(arg) return;
  set_name("armor");
  set_alias("body");
  set_short(BLU+"Saiyan's Armor"+NORM);
  set_long(
 "This is the battle armor worn by saiyan elite.\n");
 
 set_ac(3);
 set_type("body");
 set_weight(2);
 set_value(3000);
 
}
