/*                                       
 *  File:   /players/mosobp/areas/BATTLE/NPC/eaura.c
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
  set_name("aura");
  set_alias("misc");
  set_short(HIY+"An Energy Aura"+NORM);
  set_long(
  "This is the energy aura of a trained Z fighter. When\n"+
  "a Z fighter is powered up This forms around their ki.\n"+
  "This particular aura only forms around someone of good\n"+
  "intenions.\n");
  set_ac(2);
  set_type("misc");
  set_weight(1);
  set_value(5000);
}

do_special(owner)
{
  if(owner->query_alignment() < 0)
    {
      tell_object(owner,
        "Your aura intensifies in power for a moment.\n");
      tell_room(environment(owner),
        owner->query_name()+"'s aura pulsates intensifying for a moment!\n", ({ owner
 }));
      return -(1+random(5));
    }
  if((int)owner->query_attrib("cha") > random(100))
  {
    tell_object(owner,
      "Your aura intensifies and surges upward.\n");
    tell_room(environment(owner),
    owner->query_name()+"'s aura intensifies and surges upward.\n", ({ owner }));
    owner->heal_self(random(10));
    return random(2);
  }
  return;
}

  wear(arg){
    if(arg=="aura"){
      if(this_player()->query_alignment() < 100) {
        write("The Aura refuses to power up for evil.\n");
          return 1;
      }
    if(::wear(arg));
      write("There is a flash of light as the aura surrounds you\n");
      say("The Aura hums as "+capitalize(this_player()->query_real_name())+" grasped the aura.\n");
        return 1;
   }
   if(arg != "aura"){
     return;
   }
}