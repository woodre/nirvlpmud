/*
 *    File: /players/chip/mobs/apartment/bum3.c
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
  set_short(""+CYN+"A young, yet aged bum"+NORM+"");
  set_long(
         "This is just one of the many homeless who live in the old apartment\n"+
         "building. He wears old blue jeans and a dirty flanel shirt. He looks\n"+
         "like the streets have made him a fairly tough individual.\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(0);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The bum says: \"Get out of my house!\".\n");
  load_chat("The bum looks at you as if to say you are trespassing.\n");
  load_chat("The bum brushes some dirt away from his shirt.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The bum breaks a 40 oz beer bottle over your head!\n");
  set_spell_mess1("The bum breaks a 40 oz beer bottle over his enemy's head!\n");
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
