/*                                       
 *  File:   /players/mosobp/areas/BATTLE/NPC/eki.c
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
  set_name("ki");
  set_alias("shield");
  set_short(HIY+"An Energy Ki"+NORM);
  set_long(
  "This is the Energy Ki of a Z fighter. When\n"+
  "a Z fighter powers up to fight a battle. This\n"+
  "forms around them. This particular ki only forms\n"+
  "around people of good intentions.\n");
  set_ac(2);
  set_type("shield");
  set_weight(3);
  set_value(2500);
}

do_special(owner)
{
  /*  Just because I'm evil */
  if(owner->query_alignment() < 0)
    {
      tell_object(owner,
        "Your ki pulsates as it increases in power!\n");
      tell_room(environment(owner),
        owner->query_name()+"'s ki surges upward.\n", ({ owner }));
          return -(1+random(5));
    }
  if((int)owner->query_attrib("cha") > random(100))
  {
    tell_object(owner,
      "Your ki surges around you.\n");
    tell_room(environment(owner),
      owner->query_name()+" screams as their ki arises.\n", ({ owner }
));
    owner->heal_self(random(4));
    return random(2);
  }
  return;
}

  wear(arg){
    if(arg=="ki"){
      if(this_player()->query_alignment() < 100) {
        write("The Ki refuses to ready for evil.\n");
          return 1;
      }
    if(::wear(arg));
      write("The Ki flashes as it readies for battle\n");
      say("The Ki hums as "+capitalize(this_player()->query_real_name())+" grasped the ki.\n");
        return 1;
   }
    if(arg != "ki"){
      return;
   }
}
