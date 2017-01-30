/*
 *    File: /players/chip/mobs/movies/pirahna.c
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
      set_name("a school of "+RED+"pirahna"+NORM+"");
      set_alias("pirahna");
      set_short("a school of "+RED+"pirahna"+NORM+"");
      set_race("fish");
      set_long(
         "Jaws snapping, teeth gnashing, this is one bunch of fish it would be\n"+
         "safer to just stay they hell away from. Pirahna are known for being\n"+
         "ravenous flesh-eaters, and they love the taste of blood. Perhaps you\n"+
         "may wish to get away from them, before they eat you alive.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (10000) + 10000);
      move_object(gold, this_object());
      set_level(18);
      set_hp(7750);
      set_ac(52);
      set_wc(95);
      set_al(-1000);
      set_chance(35);
      set_spell_dam(random (70) + 35);
      set_spell_mess2("The "+RED+"pirahna"+NORM+" rip away at your flesh, revealing "+HIW+"bone"+NORM+".\n");
      set_spell_mess1("The "+RED+"pirahna"+NORM+" rip away at their victim's flesh, revealing "+HIW+"bone"+NORM+".\n");
      set_aggressive(1);
      set_chat_chance(10);
      load_chat("You can feel the "+RED+"pirahna"+NORM+" swimming around your legs and nibbling away.\n");
      load_chat("The "+RED+"pirahna"+NORM+" bite sharply into you!\n");
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
    if(random(100) > 49) pirahna_wound();
    

  }
}
pirahna_wound()
{
  if(!present("pirahna_wound", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "\n\t"+RED+"Pirahna"+NORM+" bite chunks out of your body, leaving wide-open holes."+NORM+"\n\n");
    ob = clone_object("/players/chip/items/movies/pirahna_wound.c");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}

