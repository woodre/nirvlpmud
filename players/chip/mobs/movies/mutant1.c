/*
 *    File: /players/chip/mobs/movies/mutant1.c
 *    Function: NPC
 *    Author(s): Chip@Nirvana
 *    Copyright: Copyright (c) 2009 Chip
 *               All Rights Reserved
 *    Source: 5/31/09
 *    Notes:
 *
 *
 *    Change History:
 */
#include <ansi.h>
#define CO clone_object


inherit "obj/monster";

static object Remembered;

object gold;
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("A crazed, mutated humanoid");
      set_alias("mutant");
      set_short("A crazed, mutated humanoid");
      set_race("humanoid");
      set_long(
         "A medium sized mutant, his skin is extremely ragged and dirty, and he\n"+
         "has a cleft lip. He carries a spiked chain around his body, and has a\n"+
         ".357 caliber revolver in the holster on his side, fully loaded. He has\n"+
         "no decency or real feelings, just a love for killing and other sinful\n"+
         "things, most ending up bloody.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (8000) + 7000);
      move_object(gold, this_object());
      set_level(17);
      set_hp(2500);
      set_ac(100);
      set_wc(80);
      set_al(-1000);
      set_chance(8);
      set_spell_dam(random (80) + 35);
      set_spell_mess1(""+HIR+"Blood"+NORM+" sprays everywhere as the mutant shoots his victim in the head!\n");
      set_spell_mess2("The mutant plants a .357 shell in your face, spraying "+HIR+"blood"+NORM+" everywhere.\n");
      set_aggressive(1);
      set_chat_chance(10);
      load_chat("The mutant reaches for his gun.\n");
      load_chat("The mutant swings his spiked chain around, barely missing you.\n");
      if(!root()) call_out("aggro", 2);
      }
}

aggro()
{
  object *inv;
  int    x;
  int found;
  inv = all_inventory(environment());
  x = sizeof(inv);
  while(x-- && !found)
  {
    if(inv[x]->is_player())
    {
      attack_object(inv[x]);
      found = 1;
    }
  }
  call_out("aggro", 2);
}

