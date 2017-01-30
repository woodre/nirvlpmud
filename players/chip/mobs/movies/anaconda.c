/*
 *    File: /players/chip/mobs/movies/anaconda.c
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
      set_name(""+HIG+"The anaconda"+NORM+"");
      set_alias("anaconda");
      set_short(""+HIG+"An enourmous "+GRN+"green"+HIG+" snake"+NORM+"");
      set_race("snake");
      set_long(
         "The infamous anaconda is the largest snake in the world today. It's\n"+
         "got an appetite and the deadliness to feed that appetite. This one\n"+
         "in particular is about 42 feet in length and about 2 feet wide at its\n"+
         "thickest point, and is bright green in coloration.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (10000) + 7500);
      move_object(gold, this_object());
      set_level(17);
      set_hp(7750);
      set_ac(34);
      set_wc(62);
      set_heal(5,1);
      set_al(-1000);
      set_chance(15);
      set_spell_dam(random (70) + 35);
      set_spell_mess2("The anaconda wraps its body around you and squeezes unmercifully.\n");
      set_spell_mess1("The anaconda wraps itself around its victim and squeezes them unmercifully.\n");
      set_aggressive(1);
      set_a_chat_chance(10);
      set_chat_chance(10);
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
heart_beat()
{
  ::heart_beat();
  if(attacker_ob)
  { 
    if(random(100) > 54) constrict();
    

  }
}
constrict()
{
  if(!present("constrict", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "\n\t"+GRN+"The anaconda wraps you up and constricts around your body very painfully.\n\n");
    ob = clone_object("/players/chip/items/movies/constrict.c");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}

