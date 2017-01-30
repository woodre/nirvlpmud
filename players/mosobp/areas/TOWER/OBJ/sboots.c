/*                                       
 *  File:   /players/mosobp/areas/TOWER/OBJ/sboots.c
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
  set_name("boots");
  set_alias("boots");
  set_short(BLU+"Saiyan's Boots"+NORM);
  set_long(
 "These are a pair of blue boots worn by saiyan elite.\n");
 
 set_ac(1);
 set_type("boots");
 set_weight(1);
 set_value(1000);
 
}