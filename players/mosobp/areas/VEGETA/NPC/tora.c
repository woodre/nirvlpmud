/*                                       
 *  File:   /players/mosobp/areas/VEGETA/NPC/tora.c
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
  set_name("tora");
  set_short(YEL+"Tora"+NORM);
  set_race("saiyan");
  set_long(
  "Tora is the second in command of Bardock's Elite Force. He has helped\n"+
  "Bardock attack numerous planets, increasing his power as he fights,\n"+
  "thus he has earned the second in command title.\n");
  set_level(25);
  set_hp(1400+random(550));
  set_al(1000);
  gold=clone_object("obj/money");
  gold->set_money(random(2000));
  move_object(gold, this_object());
  move_object(clone_object("/players/mosobp/areas/VEGETA/OBJ/scouter2.c"), this_object());
  init_command("wear helmet");
  set_wc(50);
  set_ac(20);
  set_heal(30,7);
  set_multi_cast(1);
  add_spell("mouthwave",
    "#MN# opens his mouth as a "+HIK+"B E A M"+NORM+" screams toward you hitting your chest!\n",
    "#MN# opens his mouth as a "+HIK+"B E A M"+NORM+" slams into #TP#!.\n",
    15,"100-120","other|energy");
  add_spell("kiblast",
    "A bright "+HIB+"BEAM "+NORM+"of light fly's toward you hitting your arms!\n",
    "A giant "+HIB+"Ki Blast"+NORM+" hits #TP# squarely in the face.\n",
    20,"90-120","other|energy");
}