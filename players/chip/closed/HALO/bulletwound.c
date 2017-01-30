/*                                                                    
 *    File: /players/chip/closed/other/HALO/bulletwound.c                
 *    Function: Wound Object
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2013 Chip      
 *               All Rights Reserved   
 *    Source: 1/5/13          
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 */

#define MAX_BEATS 20
#define DAMAGE    (20 + random(35))

int beats;

id(str) { return str=="bullet_wound"; }

drop() { return 1; }

start_it()
{
  set_heart_beat(2);
}

heart_beat()
{
  if(++beats == MAX_BEATS)
  {
    tell_object(environment(),
      "The searing wounds in your skin close.\n");
    return destruct(this_object());
  }
  
  tell_object(environment(), "\
The searing wounds in your skin grow ever more painful.\n");
  environment()->add_hp(-DAMAGE);
}