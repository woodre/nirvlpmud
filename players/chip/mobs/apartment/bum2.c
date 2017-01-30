/*
 *    File: /players/chip/mobs/apartment/bum2.c
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
  set_name("the bum");
  set_race("human");
  set_alias("bum");
  set_short(""+WHT+"A bum is here, talking to himself"+NORM+"");
  set_long(
         "This old, scraggley man stands here holding a full-blown, vulgar\n"+
         "conversation with himself. His eyes stare off seemingly into a\n"+
         "blank daze as he babbles on and on about random nonsense.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The bum points at himself and begins shouting random vulgarities.\n");
  load_chat("You become confused as the bum answers his own strange questions.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The bum punches you in the face, then slaps himself for being an asshole.\n");
  set_spell_mess1("The bum punches his enemy in the face, then slaps himself. What a whacko.\n");
  move_object("/players/chip/items/apartment/cheeseburger.c");
  set_dead_ob(this_object());
  }
monster_died()
   {
      int frenchfries;
      frenchfries = random(5) + 2; 
      while (frenchfries > 0)
      {
         move_object(clone_object("/players/chip/items/apartment/frenchfries.c"), this_object());
         frenchfries--;
      }
   }
