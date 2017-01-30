/*
 *    File: /players/chip/mobs/movies/spider_one.c
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
      set_name("a "+HIK+"spider"+NORM+"");
      set_alias("spider");
      set_short("a "+HIK+"spider"+NORM+"");
      set_race("spider");
      set_long(
         "Hundreds of doorknob-sized black spiders make up this terrifying, large\n"+
         "patch of small movement. They swarm all over you, biting away at you.\n"+
         "They make a loud click noice when they prepare to bite, and look like\n"+
         "demonic little creatures. This would be a pure nightmare to anyone with\n"+
         "arachnaphobia.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (10000) + 7500);
      move_object(gold, this_object());
      set_level(18);
      set_hp(7500);
      set_ac(37);
      set_wc(90);
      set_heal(5,1);
      set_al(-1000);
      set_chance(15);
      set_spell_dam(random (70) + 35);
      set_spell_mess2(""+HIK+"Spiders"+NORM+" crawl all over your body, causing you to freak out and smack yourself.\n");
      set_spell_mess1(""+HIK+"Spiders"+NORM+" crawl all over their aggressor, causing them to smack themselves.\n");
      set_aggressive(1);
      set_chat_chance(10);
      load_chat("The "+HIK+"spiders"+NORM+" make a clicking sound.\n");
      load_chat("The "+HIK+"spiders"+NORM+" bite down on you all at once!\n");
      load_chat("Your skin crawls...\n");
      load_chat(""+RED+"Blood"+NORM+"pours from the fang holes, caused by the spiders biting you.\n");
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
    if(random(100) > 59) spider_venom();
    

  }
}
spider_venom()
{
  if(!present("spider_venom", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "\n\t"+HIK+"Spiders"+NORM+" click in unison, and all bite you at once, leaving you poisoned."+NORM+"\n\n");
    ob = clone_object("/players/chip/items/movies/spider_venom.c");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}

