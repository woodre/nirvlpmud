/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/vinegar.c
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
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("vinegar");
  set_short(YEL+"Vinegar"+NORM);
  set_race("mako");
  set_long(
  "This is one of Garlic Jr. henchman, probably one of the weakest\n"+ 
  "of his henchman but still a foe not to underestimate.\n");
  
  set_level(23);
  set_hp(600+random(300));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(1000)+7000);
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/gloves.c"), this_object());
  init_command("wear gloves"); 
  move_object(gold,this_object());
  set_wc(30+random(15));
  set_ac(15+random (5));
  set_aggressive(1);
  set_multi_cast(1);
  add_spell("kiblast",
  " "+RED+"A Red beam of light flys forward and hits your "+NORM+" L E G \n",
  " "+RED+"#MN# shoots a Red BEAM of light HITTTING #TN# in the "+NORM+" L E G \n",
  30,"30-60","other|laser");
  add_spell("kiblast2",
  " "+RED+"A Red beam of light flys forward and hits your "+NORM+" C H E S T \n",
  " "+RED+"#MN# shoots a Red BEAM of light HITTTING #TN# in the "+NORM+" C H E S T \n",
  20,"50-70","other|laser");
  add_spell("kiblast3",
  " "+RED+"A Red beam of light flys forward and hits your "+NORM+" A R M \n",
  " "+RED+"#MN# shoots a Red BEAM of light HITTTING #TN# in the "+NORM+" A R M \n",
  45,"20-30","other|laser");
  add_spell("kiblast4",
  " "+RED+"A Red beam of light flys forward and hits your "+NORM+" H E A D \n",
  " "+RED+"#MN# shoots a Red BEAM of light HITTTING #TN# in the "+NORM+" H E A D \n",
  30,"30-40","other|laser");

}