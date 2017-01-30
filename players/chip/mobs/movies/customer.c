/*
 *    File: /players/chip/mobs/movies/customer.c
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

inherit "obj/monster";

static object Remembered;

object gold;
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("a "+HIC+"Nirvana Cinemas"+NORM+" customer");
      set_alias("customer");
      set_short("a "+HIC+"Nirvana Cinemas"+NORM+" customer");
      set_race("human");
      set_long(
         "This person looks extremely frightened. They have blood spattered on\n"+
         "them, indicating they were witness to the carnage that previously\n"+
         "ensued. They seem to sway around, in a daze, almost as if driven mad.\n"+
         "Go to a movie theater and have this happen to you....what a night.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (5000) + 5000);
      move_object(gold, this_object());
      set_level(18);
      set_hp(1000);
      set_ac(30);
      set_wc(25);
      set_heal(5,1);
      set_al(0);
      set_chance(15);
      set_spell_dam(random (10) + 15);
      set_spell_mess2("The customer swings on you, and makes contact with your nose!\n");
      set_spell_mess1("The customer swings on his opponent, and makes contact with their nose!\n");
      set_aggressive(0);
      set_chat_chance(10);
      load_chat("The customer runs around in hysterics.\n");
      load_chat("The customer's face turns pale, as if they saw a ghost.\n");
      load_chat("The customer says: There's dead bodies....EVERYWHERE...\n");
      load_chat("The customer mumbles: Jason.....and Freddy....they just....oh dear god...\n");
	  }
}