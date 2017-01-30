/*
 *    File: /players/chip/mobs/movies/mutant2.c
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
      set_name("A hulking, mutated humanoid");
      set_alias("mutant");
      set_short("A hulking, mutated humanoid");
      set_race("humanoid");
      set_long(
         "A very large, bald, twisted looking mutant. He stands probably 7 feet\n"+
         "tall, and has to weight at least 300 pounds, all solid. He really does\n"+
         "not seem to be the talkative type, or very forgiving either. Just hope\n"+
         "he's not as fast as he is strong.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (8000) + 7000);
      move_object(gold, this_object());
      set_level(17);
      set_hp(3500);
      set_ac(100);
      set_wc(90);
      set_al(-1000);
      set_chance(8);
      set_spell_dam(random (80) + 35);
      set_spell_mess1("The mutant bludgeons his opponent's face with his fist. They spit out some "+HIW+"teeth"+NORM+".\n");
      set_spell_mess2("The mutant bludgeons your face with his fist. You spit out some "+HIW+"teeth"+NORM+".\n");
      set_aggressive(1);
      set_chat_chance(10);
      load_chat("You feel the wind of the mutant's fist as it barely misses your head.\n");
      load_chat("The mutant swings at your face, barely missing you.\n");
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

