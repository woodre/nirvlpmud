inherit "/obj/monster";

#include <ansi.h>

/******************************************************************************
 * Program: aj.c
 * Path: /players/dragnar/WalkingDead/mons
 * Type: Mob
 * Created: July 3rd, 2013 by Dragnar
 *
 * Purpose: A high level monster in the WalkingDead area.  Has a much higher
 *          than normal AC/WC, insane heal rate, strong spell attack. Average 
 *          coins are 7.5k, which is less than the allowed 8k. Max coins
 *          are only given if gear is sold in area's shop, which is a hazardous 
 *          area.
  * History:
 *          07/03/2013 - Dragnar
 *            Created
 ******************************************************************************/
reset(arg) {
  object sack;
  object obj;
  
  ::reset(arg);
  if(arg) return;
  SetMultipleIds( ({ "aj", "tony" }) );
  set_name("anthony");
  set_race("human");
  set_short("Anthony"+HIBLK+" - Walker Slayer"+NORM);
set_long(
"A man around thirty years old with dark hair, brown eyes, and golden\n\
bronze skin. He has a few weeks growth of beard on his face and looks\n\
like he has been through a war. He has blood splatters on his clothes\n\
and he is armored better than most soldiers. Looks like he has killed\n\
more than a few Walkers recently.\n");

  set_gender("male");
  set_level(23);
  
  set_hp(1000);
  set_wc(60);
  set_ac(75);
  set_heal(40,1);
  
  set_aggressive(0);
  set_al(-50);
  
  set_chat_chance(5);
  load_chat("Anthony grimaces as he wipes the blood from his boots.\n");
  load_chat("Anthony peers at you from his shroud of long hair.\n");
  load_chat("Anthony says: 'If you kill a walker make sure you search the corpse, you\n\
                might find something useful.'\n");
  load_chat("Anthony says: 'Watch out for a Walker's groan, it is like ringing a\n\
                dinner bell for other Walkers.'\n");
  load_chat("Anthony looks through the fence to the south searching for signs of walkers.\n");
  load_chat("Anthony says: 'One time I was on a run and got caught in the forest\n\
                by a mob. Walkers were everywhere. I had to mutilate\n\
                a Walker corpse in order to get out.'\n");

  move_object(clone_object("/players/dragnar/WalkingDead/obj/kill_check"), this_object());
  
  /* Put walker items in sack, Tier 2 2500 + Tier 1 1000 * 2 = 4500 value */
  sack = clone_object("/players/dragnar/WalkingDead/obj/rucksack");
  move_object( sack, this_object() );
  if( !random(3) ) {
    if( !random(2) )
  	  move_object(clone_object("/players/dragnar/WalkingDead/heals/mons/vicodin.c"), sack );
    else
      move_object(clone_object("/players/dragnar/WalkingDead/heals/mons/meth.c"), sack );
  }
  obj = clone_object("/players/dragnar/WalkingDead/obj/walker_obj");
  obj->set_value_tier( 2 );
  obj->set_object_stats();
  move_object( obj, sack );
  obj = clone_object("/players/dragnar/WalkingDead/obj/walker_obj");
  obj->set_value_tier( 1 );
  obj->set_object_stats();
  move_object( obj, sack );
  obj = clone_object("/players/dragnar/WalkingDead/obj/walker_obj");
  obj->set_value_tier( 1 );
  obj->set_object_stats();
  move_object( obj, sack );
  set_dead_ob(this_object());
  
  move_object(clone_object("/players/dragnar/WalkingDead/weap/mp5"), this_object());
  init_command("wield gun");
  
  add_spell("short_range_attack",
    "#MN# pulls a $HK$knife$N$ from his belt and $HK$F L I N G S$N$ it at you!\n",
    "#MN# pulls a $HK$knife$N$ from his belt and $HK$F L I N G S$N$ it at #TN#!\n",
    20,20-100,"physical", 5 );
}

init() {
  ::init();
}

heart_beat() {
    ::heart_beat();
}

monster_died() {
  object corpse;
  object item;
  
  corpse = present( "corpse", environment() );
  if( corpse ) {
    item = present( "kill_check_object", corpse );
    if( item )
      destruct( item );
  }
    return 0; 
}
