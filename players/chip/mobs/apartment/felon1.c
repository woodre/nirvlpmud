/*
 *    File: /players/chip/mobs/apartment/felon1.c
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
  set_name("felon");
  set_race("human");
  set_alias("felon");
  set_short(""+HIR+"A felon, hiding from the law"+NORM+"");
  set_long(
         "Freshly broken out of jail, this criminal is hiding here in\n"+
         "hopes that the law will not discover his where-abouts. He\n"+
         "looks like a hardened murderer.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The felon shouts: 'I won't go back, I'll kill you all first!'\n");
  load_chat("You catch a glimpse of something shiny in the criminal's hand.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("You feel a sharp pain as the felon shanks you between your ribs.\n");
  set_spell_mess1("You wince as you see the felon's shank slip between his enemy's ribs.\n");
  move_object("/players/chip/items/apartment/brokenshank.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int cigarettes;
      cigarettes = random(5) + 2; 
      while (cigarettes > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/cigarette.c"), this_object());
         cigarettes--;
      }
   }
