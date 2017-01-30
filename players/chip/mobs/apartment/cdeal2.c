/*
 *    File: /players/chip/mobs/apartment/cdeal2.c
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
  set_name("dealer");
  set_race("human");
  set_alias("dealer");
  set_short(""+RED+"An ugly crack dealer"+NORM+"");
  set_long(
         "With a wad of cash in one pocket and a big bag of crack\n"+
         "in the other, he looks to sell it all. But he does not\n"+
         "look like someone you would want to try to rip off...\n");
  set_level(20);
  set_hp(400 + random (200));
  set_ac(16 + random (8));
  set_wc(28 + random (14));
  set_al(-1000);
  set_aggressive(1);
  set_heal(8,2);
  set_chat_chance(10);
  load_chat("The crack dealer asks: 'You need some rocks, son?'\n");
  load_chat("The crack dealer shows you a baggy and says 'Just 50 bucks, kid'.\n");
  set_chance(20);
  set_spell_dam(random (15) + 18);
  set_spell_mess2("The dealer draws his Ruger 9mm and blasts off a shot at you.\n");
  set_spell_mess1("The dealer pops a 9mm round at his enemy without thinking twice.\n");
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
