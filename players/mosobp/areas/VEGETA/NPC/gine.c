/*                                       
/players/mosobp/areas/VEGETA/NPC/gine.c
 *  Function:  mob                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved          
 *                                       
 *                                      
 *  Source:  6/23/2015                     
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
  set_name("gine");
  set_short(YEL+"Gine"+NORM);
  set_race("saiyan");
  set_long(
  "Gine is the mother of Goku and Raditz. She was formerly part of\n"+
  "Bardock's fighting force. She is looking to buy some scouters\n"+
  "from the guards and scouts on Planet Vegeta.\n");
  set_level(10);
  set_hp(150);
  set_al(0);
  set_chat_chance(20);
  load_chat("Gine says: I am looking to trade for some scouters.\n");
  set_chat_chance(10);
  load_chat("Gine says: Welcome to Planet "+HIY+"Vegeta"+NORM+"!\n");
  set_wc(14);
  set_ac(8);

}