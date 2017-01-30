/*                                                                    
 *    File: /players/chip/closed/other/SATAN/satanmob.c                
 *    Function: NPC
 *    Author(s): Chip@Nirvana       
 *    Copyright: Copyright (c) 2008 Chip      
 *               All Rights Reserved   
 *    Source: 7/30/09           
 *    Notes:                                                          
 *                                                                    
 *                                                                    
 *    Change History:                                                 
 *    12-MAR-2015 - Gnar
 *      Updated checks for attacker_ob in wound and hellfire specials
 */

#include <ansi.h>

inherit "obj/monster";

static object Remembered;

object gold;
reset(arg) {
	set_dead_ob(this_object()); 
   ::reset(arg);
   if(!arg) {
      set_name(""+HIR+"S"+HIK+"a"+HIR+"t"+HIK+"a"+HIR+"n"+NORM+"");
      set_alias("satan");
      set_short(""+HIR+"S"+HIK+"a"+HIR+"t"+HIK+"a"+HIR+"n"+NORM+"");
      set_race("demon");
      set_long(
         "The Overlord of the Underworld. The Dark Lord. Lucifer. Hades. The Dark\n"+
         "Prince. The Devil. Diablo. He's that bad son of a bitch who occupies the\n"+
         "throne in the depths of "+HIR+"hell"+NORM+" itself. He collects souls, and yours is\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (25000) + 20000);
      move_object(gold, this_object());
      set_level(20);
      set_hp(16000);
      set_ac(60);
      /** Adding wc bonus for wound and hellfire - Gnar **/
      set_wc_bonus(42);
      set_wc(140);
      set_heal(10,1);
      set_al(-1000);
      set_chance(25);
      set_spell_dam(225);
      set_spell_mess2("Satan "+HIR+"gashes"+NORM+" his opponent with his claws!\n");
      set_spell_mess1("Satan "+HIW+"slices"+NORM+" through his opponent's stomach, spilling their innards!\n");
      set_aggressive(1);
      set_a_chat_chance(10);
      set_chat_chance(10);
      load_chat(""+HIR+"Satan"+NORM+" "+HIK+"commands"+NORM+": Your soul belongs to me now.\n");
      load_chat(""+HIR+"Satan"+NORM+" "+HIK+"commands"+NORM+": You are nothing, feel Hell's wrath!\n");
      load_chat(""+HIR+"Satan"+NORM+" "+HIK+"commands"+NORM+": Weak mortals like yourself stand no chance.\n");
      load_chat(""+HIR+"Satan"+NORM+" "+HIK+"commands"+NORM+": Prepare to spend eternity here!\n");
      load_a_chat("The heat here is overwhelming\n");
      /* Immune to Fire */
      set_armor_params("other|fire",0,100,0);
      /* Vulnerable to Cold */
      set_armor_params("other|ice",0,-50,0);
      /* Resistance to Evil */
      set_armor_params("other|evil",0,100,0);
      /* Vulnerable to Good */
      set_armor_params("other|good",0,-50,0);

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

hellfire_special()
{
  if( !attacker_ob )
    return 1;

  if( !present(attacker_ob, environment(this_object())) ) 
    return 1;

  tell_object(attacker_ob,
    "\n\tSatan calls pillars of hellfire to rise against you!\n\n");
  tell_room(environment(),
    "Satan calls pillars of hellfire to rise against "+attacker_ob->query_name()
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
    hellfire_special();
  }
  if(random(100) > 75)
  {
    wound();
  }
}

wound()
{
  if( !attacker_ob )
    return 1;

  if( !present(attacker_ob, environment(this_object()) ) ) 
    return 1;

  if(!present("satan_wound", attacker_ob))
  {
    object ob;
    tell_object(attacker_ob,
      "Satans burning claws sear right through your weak flesh.\n");
    ob = clone_object("/players/chip/closed/other/SATAN/satanwound.c");
    move_object(ob, attacker_ob);
    ob->start_it();
    return 1;
  }
  return 1;
}

monster_died()
{
	if(!present("satan_reward", attacker_ob))
	{
		object ob;
		tell_object(attacker_ob,
		  "As Satan falls, you hear him scream in agony and see his hand rise towards\n"+
		  "you in a threatening manner. The back of your head becomes unbearably hot.\n"+
		  "As you watch, Satan finally smiles then vanishes in a burst of flame.\n");
		ob = clone_object("/players/chip/closed/other/SATAN/satan_reward.c");
		move_object(ob, attacker_ob);
     }
}
