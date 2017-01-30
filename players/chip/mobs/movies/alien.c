/*
 *    File: /players/chip/mobs/movies/alien.c
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
      set_name("An "+MAG+"A"+NORM+""+HIK+"lien Drone"+NORM+"");
      set_alias("alien");
      set_short("An "+MAG+"A"+NORM+""+HIK+"lien "+MAG+"D"+NORM+"rone"+NORM+"");
      set_race("alien");
      set_long(
         "A fairly large alien drone, about 8 ft tall, 15 ft from head to tail.\n"+
         "His entire body is black and almost insect-like. His tail is very long\n"+
         "and agile, and has a sharp spike at the end. His head is elongated and\n"+
         "thin, and inside his mouth seems to be an extendable inner mouth and\n"+
         "jaw. His terrifying face shows no emotion.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (10000) + 10000);
      move_object(gold, this_object());
      set_level(19);
      set_hp(7500);
      set_ac(25);
      set_wc(99);
      set_al(-1000);
      set_chance(23);
      set_spell_dam(random (70) + 35);
      set_spell_mess1(""+HIR+"Blood"+NORM+" sprays everywhere as the alien viciously claws at his enemy!\n");
      set_spell_mess2("Claws tear into your body, spraying "+HIR+"blood"+NORM+" everywhere.\n");
      set_aggressive(1);
      set_a_chat_chance(10);
      set_chat_chance(10);
      load_chat("The alien drone emits a high-pitched screech.\n");
      load_chat("The tail of the alien lashes about, sometimes barely missing you.\n");
      load_a_chat("A slimy substance oozes from the alien's mouth.\n");
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
    if(random(100) > 79) alien_poison();
    

  }
}

alien_poison()
{
  if(!present("alien_poison", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "\n\t"+GRN+"The alien drone plunges his tail into your stomach, you feel very sick."+NORM+"\n\n");
    ob = clone_object("/players/chip/items/movies/poison.c");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}

respawn()
{
  if(present("corpse", environment()))
  {
    move_object(present("corpse", environment()), this_object());
    destruct(present("corpse", this_object()));
    call_out("transform", 2);
  }
}

transform()
{
  string item;
  item = first_inventory(this_object());
  while(item)
  {
    object next, ob;
    string str;
    next = next_inventory(item);
    if(!living(item))
    {
      ob = item->short();
      if(ob)
      {
        write(ob+ "...\n");
        str = item->query_name();
        item->wield(str);
        if(item->armor_class() || item->is_armor())
          command("wear "+str);
        if(item->weapon_class())
          command("wield "+str);
      }
    }
    item = next;
  }
  return 1;
}
