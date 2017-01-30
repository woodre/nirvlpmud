/*                                       
 *  File:   /players/mosobp/areas/BATTLE/NPC/android.c
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
  set_name("korrin");
  set_short(YEL+"Korrin"+NORM);
  set_race("cat");
  set_long(
  "This is the cat that has taken up residence below Kame's lookout\n"+
  "he supplies the z fighters with sensu beans to replenish their lost\n"+
  "health. He might be up here to sell sensu beans to weary travelers.\n");
  set_level(10);
  set_hp(150);
  set_al(1000);
  set_wc(14);
  set_ac(8);

}
