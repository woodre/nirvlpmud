      /*                                                                    
       *    File: /players/chip/mobs/apartment/lndlrdsprt.c                
       *    Function: NPC
       *    Author(s): Chip@Nirvana       
       *    Copyright: Copyright (c) 2009 Chip      
       *               All Rights Reserved   
       *    Source: 5/13/09           
       *    Notes:  Added to expand on f3lndlrd.c in my                                                        
       *            my apartment area                                                        
       *                                                                    
       *    Change History:                                                 
       */
#include <ansi.h>

inherit "obj/monster";


reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name(""+HIK+"a dark spirit"+NORM+"");
      set_alias("spirit");
      set_short(""+HIK+"A dark spirit"+NORM+"");
      set_race("ghost");
      set_long(
         "This is the long deceased spirit of the landlord who once oversaw the\n"+
         "caretaking of this run-down apartment building. He was locked in this\n"+
         "very closet by a couple of criminals during a routine robbery, unconcsious\n"+
         "and left for dead. His spirit is now hungry for revenge on the human race\n"+
         "For being such terrible, heartless creatures.\n");
      add_money(12500 + random(12500));
      set_level(20);
      set_hp(5000);
      set_ac(32);
      set_wc(90);
      set_wc_bonus(9);
      set_heal(3,2);
      set_al(-1000);
      set_chance(15);
      set_spell_dam(random (60) + 35);
      set_spell_mess2("The "+HIK+"spirit"+NORM+" shoves you roughly into the back wall of the closet!\n");
      set_spell_mess1("The "+HIK+"spirit"+NORM+" shoves his victim roughly into the back wall of the closet!\n");
      set_aggressive(1);
      set_chat_chance(10);
      load_chat("The "+HIK+"spirit"+NORM+" wails angrily.\n");
      load_chat("The air becomes freezing cold, numbing your senses.\n");
      load_chat("With a ferocious sound, the "+HIK+"spirit"+NORM+" screams for vengeance.\n");
      load_chat("Your level of comfort just went down four notches.\n");
      set_dead_ob(this_object());
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
  if(!present("soulfreeze", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "\n\t"+CYN+"Your soul has become frozen, making it more difficult to resist damage."+NORM+"\n\n");
    ob = clone_object("/players/chip/items/apartment/soulfreeze.c");
    move_object(ob, attacker_ob);
    ob->start_it();
  }
}
monster_died()
   {
      int chips_key;
      chips_key = 1; 
      while (chips_key > 0)
      {
         move_object(clone_object("/players/chip/closed/other/SATAN/satankey.c"), this_object());
         chips_key--;
      }
   }

