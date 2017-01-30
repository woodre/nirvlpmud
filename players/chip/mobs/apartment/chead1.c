/*
 *    File: /players/chip/mobs/apartment/chead1.c
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
  set_name("crackhead");
  set_race("human");
  set_alias("addict");
  set_short(""+HIW+"A crack addict"+NORM+"");
  set_long(
         "He twitches and tweaks spaztically, muttering something\n"+
         "about needing another rock. His teeth are rotten through\n"+
         "and his eyes are yellowed.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The crackhead shouts: \"Hey I need more rocks, hook me up before I kill you!\"\n");
  load_chat("You catch a glimpse of something shiny in the crackhead's hand.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("You feel a sharp pain as the crackhead sticks his stem in your eye.\n");
  set_spell_mess1("You wince as you see the crackhead's stem poke his opponent in the eye.\n");
  move_object("/players/chip/items/apartment/crackpipe.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int crackrocks;
      crackrocks = random(5) + 2; 
      while (crackrocks > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/crackrock.c"), this_object());
         crackrocks--;
      }
   }
