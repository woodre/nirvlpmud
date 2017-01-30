/*
 *    File: /players/chip/mobs/apartment/vtnmvet1.c
 *    Function: NPC
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2008 Chip
 *               All Rights Reserved
 *    Source: 5/31/08
 *    Notes:
 *
 *
 *    Change History:
 */

#include "/sys/lib.h"

#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("veteran");
  set_race("human");
  set_alias("marine");
  set_short(""+HIG+"A Vietnam War Veteran"+NORM+"");
  set_long(
         "The Veteran is a United States Marine, who served our nation\n"+
         "in the war against Vietnam between 1959 and 1975. He seems\n"+
         "to twitch occasionally, indicating the possibility of him\n"+
         "having what they call shell shock.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(30 + random (12));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The Marine keeps a sharp eye out for anything suspicious.\n");
  load_chat("The Marine reaches down to remove someone's tooth from the tip of his boot.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The Marine parries your attack with his forearm, then chops you on the neck.\n");
  set_spell_mess1("The Marine parries his foe's attack with his forearm, then chops them on the neck.\n");
  move_object("/players/chip/items/apartment/purpleheart.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int shells;
      shells = random(5) + 2; 
      while (shells > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/ak47shell.c"), this_object());
         shells--;
      }
   }
