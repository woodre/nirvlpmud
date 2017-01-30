/*
 *    File: /players/chip/mobs/movies/cujo.c
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
      set_name(""+RED+"Cujo"+NORM+"");
      set_alias("cujo");
      set_short(""+RED+"Cujo"+NORM+"");
      set_race("dog");
      set_long(
         "This is a very large saint bernard. His fur is dusty and matted from a\n"+
         "a lack of being taken care of. His eyes are bloodshot and show no sign\n"+
         "of emotion. There is a foamy substance around his mouth and he growls\n"+
         "at everything, alive or not. Perhaps it would be best to try and avoid\n"+
         "confrontation with this backyard beast.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (10000) + 10000);
      move_object(gold, this_object());
      set_level(18);
      set_hp(7500);
      set_ac(37);
      set_wc(90);
      set_heal(5,1);
      set_al(-1000);
      set_chance(15);
      set_spell_dam(random (70) + 35);
      set_spell_mess2(""+RED+"Cujo"+NORM+" latches his jaws onto your right leg and begins to shake violently, ripping meat off the bone!\n");
      set_spell_mess1(""+RED+"Cujo"+NORM+" latches to his victim's right leg and attempts to shred it.\n");
      set_aggressive(1);
      set_a_chat_chance(10);
      set_chat_chance(10);
      load_chat(""+RED+"Cujo"+NORM+" growls at nothing.\n");
      load_chat(""+RED+"Cujo"+NORM+" lashes out, snapping at thin air!\n");
      load_chat("With a ferocious sound, "+RED+"Cujo"+NORM+" starts barking hysterically at you.\n");
      load_chat(""+RED+"Cujo"+NORM+" snaps at you, missing by only a hair or two.\n");
      load_a_chat("The smell of the blood on "+RED+"Cujo"+NORM+"'s breath makes you feel ill.\n");
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
    if(random(100) > 59) rabies();
    

  }
}
rabies()
{
  if(!present("rabies", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "\n\t"+GRN+""+RED+"Cujo"+NORM+" bites deeply into your leg, allowing the rabies to enter your bloodstream."+NORM+"\n\n");
    ob = clone_object("/players/chip/items/movies/rabies.c");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}

