inherit "/obj/monster.c";
#include <ansi.h>
/******************************************************************************
 * Program: donatello.c
 * Path: /players/wicket/ninja_turtles/mobs
 * Type: Mob
 * Created: August 19, 2014 by Wicket/Dragnar
 *
 * Purpose: A high level quest mob who wanders the sewers of Nirvana
 *
 * Special Abilities:
 *  1. Multi cast with high damage / high % spells
 *  2. Random location (controled by Gnar's castle)
 *  3. Calls robot to assist
 *    - Robot cannot be peaced
 *    - Robot relentlessly hunts target
 *    - Robot has 100% resist physical dam spell
 *    - Donatello runs and heals while robot is active 
 *    - Chance of self destruct when robot dies causing major damage
 *  4. Under 2/10 health will hit everything attacking him with
 *     fury_attack spell.
 *   - Attack will include spells for all attackers.
 *
 * History:
 *          08/19/2014 - Wicket
 *            Created
 *          08/27/2014 - Gnar
 *            Added spell to call robot, updated wander.
 *          09/23/2014 - Rumplemintz
 *            Added quest drop
 *          09/26/2014 - Gnar
 *            Beefed up stats to meet requirements for level 30 quest mob.
 ******************************************************************************/

#define tpn this_player()->query_name()
object katana;
int robot;

#if 1 /* 0 to disable drop, 1 to enable - Rumplemintz */
#define NINJA_TURTLE_QUEST
#endif

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  move_object(clone_object("/players/wicket/ninja_turtles/weapons/dstaff.c"), this_object()); 
  command("wield staff", this_object());
  set_name("donatello");
  set_alt_name("turtle");
  set_alias("donnie");
  set_race("mutant_turtle");
  set_short(MAG+"Donatello"+NORM+", One of the"+HIR+" Legendary"+NORM+" "+GRN+"Ninja Turtles"+NORM);
  set_long(
    "  An ancient ninja turtle, he is one of four that make up the team\n\
of the ninja turtles. He is very well fit in strength and stamina\n\
and is a force to be reckon with if ever attacked. He stays forever\n\
defending the good and honorable in this realm.\n");
  add_money(10000+random(13000));
  set_level(30);
  set_hp(3000+random(100));
  set_al(-800);
  set_dead_ob(this_object());

  set_chat_chance(4);
  load_chat("Donatello says: 'C O W A B U N G A    DUDE!!!!'\n");
  load_chat("Donatello says: 'Did you guys order extra pepperoni this time!'\n");
  load_chat("Donatello says: 'Master Splinter where are you? \n");
  load_chat("Donatello says: 'I wonder what my brothers are into now!'\n");
  set_ac(32+random(4));
  set_wc(99);
  set_heal(40,3);
  set_multi_cast(1);
  /** For healing while robot is dealt with **/
  set_hp_bonus( 450 );
  /** For Fury attacks **/
  set_wc_bonus( 20 );

  add_spell("sai_stab",
  "$HR$Screams$N$ echo from $H$Donatello$N$ as he smashes you with inner strength!\n"+
  "$HR$                                     >>>Woosh<<<    $N$\n"+
  "$HR$                        >>>Bang<<<                  $N$\n"+
  "$HR$         >>>Whack<<<                                $N$\n"+ 
  "$HR$                                  >>>Smash<<<       $N$\n"+
  "$HR$                      >>>Crack<<<                   $N$\n",
  "#MN# screams as he grabs his bo staff smashing down with a deep inner strength!\n",
40,100,0,0);

   add_spell("shell_shock", 
   "$HB$ #MN#$N$ lunges forward and$HR$ G R A B S$N$ You!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$Dazed$N$ and $HG$Confused$N$!\n",
   "Room Message\n",
40,100,0,5);

   call_out("random_move", 5+random(10) );
   enable_commands();
}
status players_attacking_me(object ob) {
  return (object)ob->query_attack()==this_object();
}

heart_beat() {
  object rob;

  ::heart_beat();

  if( present("donnie_robot") ) {
    tell_room( environment(), "\nDonatello leaves to control his robot remotely.\n");
    wander();
  }

  if( attacker_ob ) {
    if( (query_hp() * 100 / query_mhp() < 70) && robot < 1 ) {
      robot++;
      rob = clone_object("/players/wicket/ninja_turtles/mobs/robot.c");
      rob->set_target( attacker_ob );
      move_object( rob, environment() );
    }
    if( query_hp() * 100 / query_mhp() < 20 )
      fury_attack( attacker_ob );
  }
}

fury_attack( object target ) {
  int i,s;
  object *targets;
#ifndef __LDMUD__
  targets = filter_array(all_inventory(environment()),"players_attacking_me",this_object());
#else
  targets = filter(all_inventory(environment()), "players_attacking_me", this_object());
#endif
  s = sizeof(targets);
  if( s < 2 )
    return 0;

  /** Target will get hit from regular HB so remove from array **/
  targets -= ({ target });
  s = sizeof(targets);

  for( i=0; i < s; i++ ) {
    attacker_ob = targets[i];
    already_fight=0;
    attack();
  }
  attacker_ob = target;
}

monster_died() {
  object corpse;
#ifdef NINJA_TURTLE_QUEST /* Rumplemintz */
  object mask;

  mask = clone_object("/players/wicket/ninja_turtles/quest/turtle_mask");
  mask->set_color("purple");
  move_object(mask, this_object());
#endif
  move_object(clone_object("/players/wicket/ninja_turtles/obj/remains.c"), this_object());
  corpse = present("corpse", environment() );
  if( corpse )
    destruct(corpse); 
  return 1;
}

status random_move() {
  if(!environment()) return 0;
  if( !attacker_ob || !present( attacker_ob, environment()) )
    wander();

  call_out("random_move",5+random(60));
  return 1;
}

