/*                                       
 *  File:   /players/mosobp/areas/TOWER/NPC/garlicjr.c
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
  set_name("garlic jr.");
  set_alias("garlic");
  set_short(MAG+"Garlic Jr."+NORM);
  set_race("mako");
  set_long(
  "After escaping from the dead zone. Garlic jr. vows to\n"+
  "get revenge on Gohan and Goku for imprisoning him there.\n"+
  "He devises a way to overpower them by using the Mako Star.\n");
  
  set_level(25);
  set_hp(1000+random(400));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(3000)+11000);
  move_object(gold,this_object());
  move_object(clone_object("/players/mosobp/areas/TOWER/OBJ/daura.c"), this_object());
  init_command("wear aura");
  set_wc(44);
  set_ac(23);
  set_heal(45,5);
  set_multi_cast(1);
  add_spell("kipunch",
  "#MN# focuses energy into his fist and "+HIB+"PUNCHES"+NORM+" you in the stomach!\n",
  "#MN# rushes forward and "+HIB+"PUNCHES"+NORM+" #TN# in the stomach!\n",
  45,90,"other|physical");
  
  add_spell("kiblast",
  "#MN# hurls a "+MAG+"B E A M"+NORM+" of energy at you!\n",
  "#MN$ hurls a "+MAG+"B E A M"+NORM+" of energy.\n",
  20,"100-150","other|energy");

}

  heart_beat()
{
  ::heart_beat();
  heal();
}

int heal()
{
  int x;  
  object *stuff;
  
  if(this_object()->query_hp()<=500) 
  {
  
   this_object()->add_hp(400);
   stuff = all_inventory(environment(this_object()));
   for(x = 0; x < sizeof(stuff); x++)
  {
   if(stuff[x]->is_player())
   {
     stuff[x]->hit_player(100,"energy");
     tell_object(stuff[x]," "+MAG+"Garlic Jr."+NORM+"screams as he sends out an "+MAG+"Energy Burst"+NORM+"!\n");
   
  }}}
  
   return 1;
}
