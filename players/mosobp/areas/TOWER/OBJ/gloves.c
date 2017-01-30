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
  set_name("gloves");
  set_alias("glove");
  set_short(HIK+"White Gloves"+NORM);
  set_long(
 "These are a pair of white gloves worn by Garlic jr.'s henchman.\n");
 
 set_ac(0);
 set_type("gloves");
 set_weight(1);
 set_value(2000);
 
}