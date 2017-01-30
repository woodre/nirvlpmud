/*                                       
 *  File:   /players/mosobp/areas/TOWER/OBJ/pants.c
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
  set_name("pants");
  set_alias("pants");
  set_short(MAG+"Purple Pants"+NORM);
  set_long(
 "These are a pair of purple pants worn by Piccolo.\n");
 
 set_ac(0);
 set_type("pants");
 set_weight(1);
 set_value(2000);
 
}
