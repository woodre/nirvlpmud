inherit "/obj/monster.c";
#include <ansi.h>
/******************************************************************************
 * Program: raphael.c
 * Path: /players/wicket/ninja_turtles/mobs
 * Type: Mob
 * Created: August 19, 2014 by Wicket/Dragnar
 *
 * Purpose: A high level quest mob who wanders the sewers of Nirvana
 *
 * Special Abilities:
 *  1. Multi cast with high damage / high % spells
 *  2. Random location (controled by Gnar's castle)
 *  3. Hits all attackers (including spells) after 4/10 health. 
 *  4. Once attacked, will auto attack anyone who attacked him.
 *     - Keeps track of anyone that attacked him.
 *     - Cannot be peaced, will pick random previous attacker
 *     - If previous attacker enters room they are targeted 
 *       and hit 75 + random(75)
 *  5. Offwielded weapon = dual attacks.
 *
 * History:
 *          08/19/2014 - Wicket
 *            Created
 *          08/23/2014 - Gnar
 *            Added fury spell, updated wander.
 *          09/23/2014 - Rumplemintz
 *            Added quest drop
 *          09/26/2014 - Gnar
 *            Beefed up stats to meet requirements for level 30 quest mob.
 ******************************************************************************/
#define tpn this_player()->query_name()

#if 1 /* 0 to disable drop, 1 to enable - Rumplemintz */
#define NINJA_TURTLE_QUEST
#endif

object katana;
/** List of current attackers **/
object *targets;
/** String List of anyone that has attacked me **/
string *all_attackers;
int busy_attacking;

reset(arg) {
  ::reset(arg);
  if(arg) return;
	
  move_object(clone_object("/players/wicket/ninja_turtles/weapons/rsai.c"),
        this_object());
  command("wield");
        katana=clone_object("/players/wicket/ninja_turtles/weapons/rsai.c"),
        move_object(katana, this_object());
  katana->offwield( this_object() );
  set_name("raphael");
  set_alt_name("turtle");
  set_alias("raph");
  set_race("mutant_turtle");
  set_short(HIR+"Raphael"+NORM+", One of the"+HIR+" Legendary"+NORM+" "+GRN+"Ninja Turtles"+NORM);
  set_long(
    "  An ancient ninja turtle, he is one of four that make up the team\n"+
    "of the ninja turtles. He is very well fit in strength and stamina\n"+
    "and is a force to be reckon with if ever attacked. He stays forever\n"+
    "defending the good and honorable in this realm.\n");
  add_money(10000+random(13000));
  set_level(30);
  set_hp(3000+random(400));
  set_al(-800);
  set_dead_ob(this_object());
  set_chat_chance(9);
  load_chat("Raphael says: 'C O W A B U N G A    DUDE!!!!'\n");
  load_chat("Raphael says: 'Stupid pizza guy, I'm hungry I wish he would Hurry up!'\n");
  load_chat("Raphael says: 'Where is Master Splinter?'\n");
  load_chat("Raphael says: 'I wonder where my numb skull brothers have gone now!'\n");
  set_ac(32+random(9));
  set_wc(80);
  set_heal(75,5);
  set_multi_cast(1);
  add_spell("sai_stab",
  "$HR$Screams$N$ echo from $HR$Raphael$N$ as he stabs you with inner strength!\n"+
  "$HR$                >>>                                 $N$\n"+
  "$HR$                   >>>                              $N$\n"+
  "$HR$         >>>Blood Sprays Everywhere<<<              $N$\n"+ 
  "$HR$                         <<<                        $N$\n"+
  "$HR$                            <<<                     $N$\n",
  "#MN# screams as he grabs his sai stabbing with a deep inner strength!\n",
75,100,0,0);
   add_spell("shell_shock", 
   "$HB$ #MN#$N$ lundges forward and$HR$ G R A B S$N$ You!\n"+
   "$HY$       Stunning $N$ You....\n"+
   "       You $HK$stumble$N$ around $HR$Dazed$N$ and $HG$Confused$N$!\n",
   "Room Message\n",
75,100,0,0);
   call_out("random_move", 5+random(10) );
   enable_commands();
}
status present_attackers(string who) {
  return objectp(present(who, environment(this_object()) ));
}

status players_attacking_me(object ob) {
  return (object)ob->query_attack()==this_object();
}

init() {
  ::init();
  if( all_attackers && this_player() && this_player()->is_player() ) {
    if( member( all_attackers, this_player()->query_real_name() ) >= 0 ) {
      attacker_ob = this_player();
      tell_room(environment(), this_object()->short()+" screams and turns to attack "+
        this_player()->query_name()+".\n");
      this_player()->hit_player(75+random(75), "physical");
    }
  }
}

update_targets() {
  int i,s;

  if( !all_attackers )
    all_attackers = ({ });
  if( !targets )
    targets = ({ });

#ifndef __LDMUD__
  targets = filter_array(all_inventory(environment()),"players_attacking_me",this_object());
#else
  targets = filter(all_inventory(environment()), "players_attacking_me", this_object());
#endif
  s = sizeof(targets);

  for( i=0; i < s; i++ ) {
    if( member( all_attackers, targets[i]->query_real_name() ) < 0 ) {
      tell_room( environment(), "Adding "+targets[i]->query_name()+" to attacker list.\n");
      load_chat("Raphael says: 'Dude, have you seen "+
        targets[i]->query_name()+"? I REALLY want to talk to him.'\n");
      all_attackers += ({ targets[i]->query_real_name() }); 
    }
  }
}

heart_beat() {
  int s;
  string *pres_attackers;

  ::heart_beat();
  if( !environment() )
    return;

  if(attacker_ob) {
    update_targets();

    if( query_hp() * 100 / query_mhp() < 40 )
      fury_attack( attacker_ob ); 
  }
  if( !attacker_ob && all_attackers && sizeof(all_attackers) > 0 ) {

#ifndef __LDMUD__
    pres_attackers = filter_array(all_attackers,"present_attackers",this_object());
#else
    pres_attackers = filter(all_attackers, "present_attackers", this_object());
#endif
    s = sizeof(pres_attackers);
    if( s > 0 )
      attacker_ob = present(pres_attackers[ random(s) ], environment() );

  }
}

fury_attack( object target ) {
  int i,s;

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
  mask->set_color("red");
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
