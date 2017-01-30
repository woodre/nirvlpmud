/*                                                             *
 *  File:             /players/angel/area/walmart/obj/bh.c     *
 *  Function:         obj                                      *
 *  Author(s):        Angel@Nirvana                            *
 *  Copyright:        Copyright (c) 2006 Angel                 *
 *                            All Rights Reserved.             *
 *  Source:           11/15/05                                 *
 *  Notes:                                                     *
 *                                                             *
 *                                                             *
 *  Change History:                                            *
 */

/*                                                           
 *  File:             /players/angel/area/walmart/obj/bh.c   
 *  Function:         obj                                    
 *  Author(s):        Angel@Nirvana                          
 *  Copyright:        Copyright (c) 2006 Angel                
 *                            All Rights Reserved.           
 *  Source:           11/15/05                               
 *  Notes:                                                   
 *                                                           
 *                                                          
 *  Change History:
 */
 
#include <ansi.h>;

inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("heal");
  add_alias("heal");
  set_short("little heal");
  set_long("This is a basic heal");
  set_type("heal");
  set_type_single("heal");
  set_msg("you can eat the heal\n");
  set_msg2("  its a tasty heal\n");
  add_cmd("eat");
  set_heal(20,20);
  set_charges(2);
  set_soak(3);
  set_stuff(3);
  set_value(100);
}

query_save_flag(){
  return 1;
  }