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
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("android");
  set_short(HIR+"An Android"+NORM);
  set_race("android");
  set_long(
  "This is the earliest attempt from Dr. Gero at making an android. He's\n"+
  "not very stable but he can defeat a saibaman easily.\n");
  set_level(20);
  set_hp(600+random(300));
  set_al(-1000);
  gold=clone_object("/obj/money");
  gold->set_money(random(1000)+5000);
  move_object(gold,this_object());
  set_wc(30+random(15));
  set_ac(15+random (5));
  add_spell("kiblast",
    "Three "+HIC+"BEAMS"+NORM+" of "+HIR+"ENERGY"+NORM+" strike your chest!\n",
    HIR+"#MN#"+NORM+" releases "+HIR+"ENERGY"+NORM+"from his index finger.\n",
    45,60,"other|laser");
  add_spell("dragonpunch",
    "A "+HIB+"FIST"+NORM+" strikes your jaw knocking your head back!\n",
    "#MN# screams loudly as he moves forward in a swift motion driving his "+HIB+"FIST"+NORM+" upward!\n",
    45,45-50,"other|ice");
}