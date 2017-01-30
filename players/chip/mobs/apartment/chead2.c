/*
 *    File: /players/chip/mobs/apartment/chead2.c
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
  set_short(""+HIY+"An angered crackhead"+NORM+"");
  set_long(
         "He breathes heavily, praying to find himself his next fix.\n"+
         "He seems to be searching the floor for something he thinks\n"+
         "he dropped.\n");
  set_level(20);
  set_hp(350 + random (250));
  set_ac(18 + random (6));
  set_wc(32 + random (10));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The crackhead shouts: \"Hey I need more rocks, hook me up before I kill you!\"\n");
  load_chat("You catch a glimpse of something shiny in the crackhead's hand.\n");
  set_chance(20);
  set_spell_dam(random (13) + 20);
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
