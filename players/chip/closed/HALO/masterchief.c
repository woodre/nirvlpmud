/*                                                                    
 *    File: /players/chip/closed/other/HALO/masterchief.c                
 *    Function: NPC
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2013 Chip      
 *               All Rights Reserved   
 *    Source: 1/5/13           
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
	set_dead_ob(this_object()); 
   ::reset(arg);
   if(!arg) {
      set_name(""+GRN+"Master Chief"+NORM+"");
      set_alias("chief");
      set_short(""+GRN+"Master Chief"+NORM+"");
      set_race("spartan");
      set_long(
         ""+GRN+"Master Chief"+NORM+" Petty Officer John-117. In his armor he stands approximately \n"+
         "7 feet tall, and weighs around half a ton. Without the armor he's 6 feet, 7 inches tall\n"+
         "and weighs 287 pounds. He's an absolute master with all sorts of firearms, and even likes\n"+
         "his energy sword, and assorted grenades from time to time. His dark green armor suit and\n"+
         "overshield make him that much tougher of an opponent. As a Spartan, his training with all\n"+
         "available weaponry is far beyond that of any average soldier. Keep that in mind if you were\n"+
         "thinking of attacking him.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (25000) + 20000);
      move_object(gold, this_object());
      set_level(20);
      set_hp(20000);
      set_ac(45);
      set_wc(130);
      set_heal(6,1);
      set_al(1000);
      set_chance(25);
      set_spell_dam(225);
      set_spell_mess2(""+GRN+"Master Chief"+NORM+" draws his "+HIC+"energy sword"+NORM+" and drives it into his foe with unmatched skill.\n");
      set_spell_mess1("Assault rifle blazing, "+GRN+"Master Chief"+NORM+" circles his opponent, ventilating them from all sides!\n");
      set_aggressive(1);
      set_a_chat_chance(10);
      set_chat_chance(10);
      load_chat(""+GRN+"Master Chief"+NORM+": The covenant are everywhere. Watch your back out here.\n");
      load_chat(""+GRN+"Master Chief"+NORM+": Did the UNSC send you here to assist in the mission?\n");
      load_chat(""+GRN+"Master Chief"+NORM+": Spartans are tough as nails. The best soldiers I have ever worked with.\n");
      load_chat(""+GRN+"Master Chief"+NORM+": Cortana, where is our next objective?\n"+
	        ""+CYN+"Cortana"+NORM+": We need to hold this position until help arrives, "+GRN+"Master Chief"+NORM+".\n");
      load_a_chat("You hear the sounds of Covenant warcries in the distance.\n");
      }
}

grab_exit()
{
  string *exits, *rand;
  int    x, y;
  exits = environment()->query_dest_dir();
  y     = sizeof(exits);
  rand = ({ });
  for(x = 1; x < y; x += 2)
  {
    rand += exits[x];
  }
  return rand[random(sizeof(rand))];
}

sword_special()
{
  if(attacker_ob && !present(attacker_ob, environment(this_object()))) return 1;
  tell_object(attacker_ob,
    "\n\t"+GRN+"Master Chief"+NORM+" disappears behind you. His "+HIC+"energy sword"+NORM+" impales your spine!\n\n");
  tell_room(environment(),
    ""+GRN+"Master Chief"+NORM+" draws his "+CYN+"energy sword"+NORM+" and impales "+attacker_ob->query_name()
    +"!\n", ({ attacker_ob }));
  attacker_ob->hit_player(100+random(50));
  return 1;
  }

heart_beat()
{
  ::heart_beat();
  if(attacker_ob && !present(attacker_ob, environment(this_object()))) return 0;
  if(attacker_ob)
  {
    Remembered = attacker_ob;
  }
  if(random(100) > 75) /* 25 % chance */
  {
    sword_special();
  }
  if(random(100) > 75)
  {
    wound();
  }
}

wound()
{
  if(attacker_ob && !present(attacker_ob, environment(this_object()))) return 1;
  if(!present("bullet_wound", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      ""+GRN+"Master Chief"+NORM+"'s assault rifle spray penetrates deep into your weak flesh.\n");
    ob = clone_object("/players/chip/closed/other/HALO/bulletwound.c");
    move_object(ob, attacker_ob);
    ob->start_it();
    return 1;
  }
  return 1;
}

monster_died()
{
	if(!present("chief_reward", attacker_ob))
	{
		object ob;
		tell_object(attacker_ob,
		  "As "+GRN+"Master Chief"+NORM+" collapses in final defeat, he hands you a microchip and\n"+
		  "his helmet. "I need you to take my place in the battle against the\n"+
		  "Covenant. You're an incredibly strong warrior. I only hope you can\n"+
                  "give them hell the way I have..." He then bleeds out. Welcome to\n"+
                  "the Spartans!\n");
		ob = clone_object("/players/chip/closed/other/HALO/chief_reward.c");
		move_object(ob, attacker_ob);
     }
}
